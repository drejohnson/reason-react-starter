type compiler;

[@bs.module] external webpack : Js.Json.t => compiler = "webpack";

[@bs.module] external devMiddleware : (compiler, Js.t({..})) => 'a = "webpack-dev-middleware";

[@bs.module] external hotMiddleware : (compiler, Js.t({..})) => 'a = "webpack-hot-middleware";

[@bs.module] external config : Js.Json.t =
  "/home/dre/workspaces/PHRESHR/reason-react-ssr/webpack.config.js";

let compiler = webpack(config);

let webpackDevMiddleware =
  devMiddleware(
    compiler,
    {"publicPath": "/", "noInfo": true, "hot": true, "stats": "minimal", "serverSideRender": true}
  );

let webpackHotMiddleware = hotMiddleware(compiler, {"log": Js.log, "reload": true});

module WebpackStats = {
  type t;
  [@bs.get] external getFromLocals : 'a => t = "webpackStats";
  [@bs.send] external toJson : t => Js.Json.t = "toJson";
  [@bs.get] external assetsByChunkName : Js.Json.t => Js.Json.t = "assetsByChunkName";
  let getAssetsByChunkName = (locals) => getFromLocals(locals) |> toJson |> assetsByChunkName;
};