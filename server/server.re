open Express;

open ReactRouter;

type compiler;

[@bs.module] external webpack : Js.Json.t => compiler = "webpack";

[@bs.module "body-parser"] external bodyParserJson : unit => Express.Middleware.t = "json";

let app = express();

! Utils.isPROD ? App.use(app, Webpack.webpackDevMiddleware) : ();

! Utils.isPROD ? App.use(app, Webpack.webpackHotMiddleware) : ();

let renderMiddleware =
  Middleware.from(
    (_req, res, _next) => {
      let renderer = FelaRenderer.renderer;
      let styleMarkup = Fela.renderToMarkup(renderer);
      let context = Js_json.object_ @@ Js_dict.empty();
      let location = Utils.geturl(_req);
      let html =
        ReactDOMServerRe.renderToString(
          <Fela.Provider renderer>
            <Fela.ThemeProvider theme={"color": "blue", "fontSize": "15px"}>
              ...<ServerRouter context location> <Root /> </ServerRouter>
            </Fela.ThemeProvider>
          </Fela.Provider>
        );
      let styles = styleMarkup;
      let app_bundle = [%bs.raw {|APP_BUNDLE|}];
      let vendor_bundle = [%bs.raw {|VENDOR_BUNDLE|}];
      Response.sendString(res, Render.view(html, styles, app_bundle, vendor_bundle))
    }
  );

App.useOnPath(
  app,
  ~path="/",
  Express.Static.make("build", Express.Static.defaultOptions()) |> Express.Static.asMiddleware
);

App.useOnPath(
  app,
  ~path="/static",
  Express.Static.make("build/static", Express.Static.defaultOptions())
  |> Express.Static.asMiddleware
);

App.get(app, ~path="*", renderMiddleware);

[@bs.val] external processEnvPort : string = "process.env.PORT";

let port = int_of_string("8080");

/* Listen for requests :D */
App.listen(
  app,
  ~port,
  ~onListen=(_err) => print_endline("Listening at http://127.0.0.1:" ++ string_of_int(port)),
  ()
);