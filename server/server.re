open Express;

open ReactRouter;

let app = express();

if (! Utils.isPROD) {
  App.use(app, Webpack.webpackDevMiddleware);
  App.use(app, Webpack.webpackHotMiddleware)
};

[@bs.val] external app_bundle : string = "APP_BUNDLE";

[@bs.val] external vendor_bundle : string = "VENDOR_BUNDLE";

/* Using a plain function as the Root component as a work around to get routing to work client side. Issue is with context I believe. Not ideal but it works and is DRY */
let renderMiddleware =
  Middleware.from(
    (_req, res, _next) => {
      let renderer = FelaRenderer.renderer;
      let styleMarkup = Fela.renderToMarkup(renderer);
      let context = Js.Json.object_(Js.Dict.empty());
      let location = Utils.geturl(_req);
      let html =
        ReactDOMServerRe.renderToString(
          <Fela.Provider renderer>
            <ReactFela.ThemeProvider theme=(Theme.default())>
              ...<ServerRouter context location> (Root.make()) </ServerRouter>
            </ReactFela.ThemeProvider>
          </Fela.Provider>
        );
      let styles = styleMarkup;
      let helmet = ReactHelmet.renderStatic();
      let helmetHtmlAttributes = helmet##htmlAttributes##toString();
      let helmetTitle = helmet##title##toString();
      let helmetMeta = helmet##meta##toString();
      let helmetLink = helmet##link##toString();
      let helmetScript = helmet##script##toString();
      Response.sendString(
        res,
        Render.view(
          html,
          helmetHtmlAttributes,
          helmetTitle,
          helmetMeta,
          helmetLink,
          helmetScript,
          styles,
          app_bundle,
          vendor_bundle
        )
      )
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