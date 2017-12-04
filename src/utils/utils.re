type dom;

type element;

type t;

[@bs.scope ("window", "location")] [@bs.val] external pathname : string = "pathname";

[@bs.val] external nodeEnv : string = "process.env.NODE_ENV";

[@bs.val] external browserEnv : bool = "process.browser";

let isPROD = nodeEnv === "production";

let isBrowser = browserEnv;

let dangerousHtml: string => Js.t('a) = (html) => {"__html": html};

[@bs.val] external dom : dom = "document";

[@bs.send] external getElementById : (dom, string) => element = "getElementById";

[@bs.send] external getElementsByClassname : (dom, string) => array(element) =
  "getElementsByClassName";

[@bs.val] external hot : bool = "module.hot";

[@bs.val] external accept : unit => unit = "module.hot.accept";

[@bs.get_index] external gett : ('a, string) => Js.Json.t = "";

let geturl = (req) => gett(req, "url");

let thenResolve = (fn) => Js.Promise.then_((value) => Js.Promise.resolve(fn(value)));
/* Js.Promise.(resolve(1) |> thenResolve((value) => value + 1) |> thenResolve(Js.log)); */