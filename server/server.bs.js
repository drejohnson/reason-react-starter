// Generated by BUCKLESCRIPT VERSION 2.1.0, PLEASE EDIT WITH CARE
'use strict';

import * as Express                    from "bs-express/src/express.js";
import * as Express$1                  from "express";
import * as Pervasives                 from "bs-platform/lib/es6/pervasives.js";
import * as Caml_format                from "bs-platform/lib/es6/caml_format.js";
import * as ReasonReact                from "reason-react/src/ReasonReact.js";
import * as Server                     from "react-dom/server";
import * as Root$ReasonReactStarter    from "../src/root.bs.js";
import * as Webpack$ReasonReactStarter from "./webpack.bs.js";

var app = Express.express(/* () */0);

app.use(Webpack$ReasonReactStarter.webpackDevMiddleware);

app.use(Webpack$ReasonReactStarter.webpackHotMiddleware);

function renderView(html, app_bundle, vendor_bundle) {
  return "\n  <html lang=\"en\">\n    <head>\n      <meta charset=\"utf-8\">\n      <meta name=\"viewport\" content=\"width=device-width, initial-scale=1\">\n      <meta name=\"theme-color\" content=\"#000000\">\n      <link rel=\"manifest\" href=\"/manifest.json\">\n      <link rel=\"shortcut icon\" href=\"/favicon.ico\">\n      <title>ReasonReact Starter</title>\n    </head>\n    <body>\n      <noscript>\n        You need to enable JavaScript to run this app.\n      </noscript>\n      <div id=\"root\">" + (String(html) + ("</div>\n      <script src=" + (String(vendor_bundle) + ("></script>\n      <script src=" + (String(app_bundle) + "></script>\n    </body>\n  </html>\n")))));
}

app.use("/", Express$1.static("build", Express.Static[/* defaultOptions */0](/* () */0)));

app.use("/static", Express$1.static("build/static", Express.Static[/* defaultOptions */0](/* () */0)));

app.get("/", (function (_, res, _$1) {
        var html = Server.renderToString(ReasonReact.element(/* None */0, /* None */0, Root$ReasonReactStarter.make(/* array */[])));
        var app_bundle = (APP_BUNDLE);
        var vendor_bundle = (VENDOR_BUNDLE);
        return res.send(renderView(html, app_bundle, vendor_bundle));
      }));

var port = Caml_format.caml_int_of_string("8080");

Express.App[/* listen */0](app, /* Some */[port], /* Some */[(function () {
          console.log("Listening at http://127.0.0.1:" + Pervasives.string_of_int(port));
          return /* () */0;
        })], /* () */0);

export {
  app        ,
  renderView ,
  port       ,
  
}
/* app Not a pure module */
