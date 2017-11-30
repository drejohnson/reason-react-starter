open Express;

open ReactRouter;

let app = express();

! Utils.isPROD ? App.use(app, Webpack.webpackDevMiddleware) : ();

! Utils.isPROD ? App.use(app, Webpack.webpackHotMiddleware) : ();

[@bs.val] external app_bundle : string = "APP_BUNDLE";

[@bs.val] external vendor_bundle : string = "VENDOR_BUNDLE";

/* Same as with index.re, using contents of Root component as a work around to get routing to work client side. Issue is with context I believe */
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
              ...<ServerRouter context location>
                   <div>
                     <Header />
                     <Switch>
                       <Route path="/" exact=true component=(() => <Home />) />
                       <Route path="/about" exact=true component=(() => <About />) />
                       <Route component=(() => <NotFound />) />
                     </Switch>
                   </div>
                 </ServerRouter>
            </Fela.ThemeProvider>
          </Fela.Provider>
        );
      let styles = styleMarkup;
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

App.listen(
  app,
  ~port,
  ~onListen=(_err) => print_endline("Listening at http://127.0.0.1:" ++ string_of_int(port)),
  ()
);