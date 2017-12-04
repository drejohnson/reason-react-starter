type compiler;

[@bs.module] external webpack : Js.Json.t => compiler = "webpack";

[@bs.module]
external devMiddleware : (compiler, {. "noInfo": bool, "serverSideRender": bool}) => 'a =
  "webpack-dev-middleware";

[@bs.module] external hotMiddleware : compiler => 'a = "webpack-hot-middleware";

/* TODO: fix */
[@bs.module] external config : Js.Json.t = "../../../webpack.config";

let config = config;

let compiler = webpack(config);

let webpackDevMiddleware = devMiddleware(compiler, {"noInfo": true, "serverSideRender": true});

let webpackHotMiddleware = hotMiddleware(compiler);