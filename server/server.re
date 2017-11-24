open Express;

type compiler;

[@bs.module] external webpack : Js.Json.t => compiler = "webpack";

[@bs.module "body-parser"] external bodyParserJson : unit => Express.Middleware.t = "json";

let app = express();

App.use(app, Webpack.webpackDevMiddleware);

App.use(app, Webpack.webpackHotMiddleware);

let renderView = (html, app_bundle, vendor_bundle) => {j|
  <html lang="en">
    <head>
      <meta charset="utf-8">
      <meta name="viewport" content="width=device-width, initial-scale=1">
      <meta name="theme-color" content="#000000">
      <link rel="manifest" href="/manifest.json">
      <link rel="shortcut icon" href="/favicon.ico">
      <title>ReasonReact Starter</title>
    </head>
    <body>
      <noscript>
        You need to enable JavaScript to run this app.
      </noscript>
      <div id="root">$(html)</div>
      <script src=$(vendor_bundle)></script>
      <script src=$(app_bundle)></script>
    </body>
  </html>
|j};

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

App.get(
  app,
  ~path="/",
  Middleware.from(
    (_req, res, _next) => {
      /* We can server render a React app here and send it to the client! */
      let html = ReactDOMServerRe.renderToString(<Root />);
      let app_bundle = [%bs.raw {|APP_BUNDLE|}];
      let vendor_bundle = [%bs.raw {|VENDOR_BUNDLE|}];
      Response.sendString(res, renderView(html, app_bundle, vendor_bundle))
    }
  )
);

[@bs.val] external processEnvPort : string = "process.env.PORT";

let port = int_of_string("8080");

/* Listen for requests :D */
App.listen(
  app,
  ~port,
  ~onListen=(_err) => print_endline("Listening at http://127.0.0.1:" ++ string_of_int(port)),
  ()
);