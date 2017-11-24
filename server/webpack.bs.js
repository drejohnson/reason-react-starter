// Generated by BUCKLESCRIPT VERSION 2.1.0, PLEASE EDIT WITH CARE
'use strict';

import * as Webpack              from "webpack";
import * as WebpackDevMiddleware from "webpack-dev-middleware";
import * as WebpackHotMiddleware from "webpack-hot-middleware";
import * as WebpackConfigJs      from "/home/dre/workspaces/PHRESHR/reason-react-ssr/webpack.config.js";

var compiler = Webpack(WebpackConfigJs);

var webpackDevMiddleware = WebpackDevMiddleware(compiler, {
      publicPath: "/",
      noInfo: /* true */1,
      hot: /* true */1,
      stats: "minimal",
      serverSideRender: /* true */1
    });

var webpackHotMiddleware = WebpackHotMiddleware(compiler, {
      log: (function (prim) {
          console.log(prim);
          return /* () */0;
        }),
      reload: /* true */1
    });

function getAssetsByChunkName(locals) {
  return locals.webpackStats.toJson().assetsByChunkName;
}

var WebpackStats = /* module */[/* getAssetsByChunkName */getAssetsByChunkName];

export {
  compiler             ,
  webpackDevMiddleware ,
  webpackHotMiddleware ,
  WebpackStats         ,
  
}
/* compiler Not a pure module */
