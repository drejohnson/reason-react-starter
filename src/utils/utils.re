[@bs.val] external nodeEnv : string = "process.env.NODE_ENV";

let isPROD = nodeEnv === "production";

let dangerousHtml: string => Js.t('a) = (html) => {"__html": html};

type dom;

[@bs.val] external dom : dom = "document";

type element;

[@bs.send] external get_by_id : (dom, string) => element = "getElementById";

[@bs.val] external hot : bool = "module.hot";

[@bs.val] external accept : unit => unit = "module.hot.accept";

[@bs.get_index] external gett : ('a, string) => Js.Json.t = "";

let geturl = (req) => gett(req, "url");

let thenResolve = (fn) => Js.Promise.then_((value) => Js.Promise.resolve(fn(value)));
/* Js.Promise.(resolve(1) |> thenResolve((value) => value + 1) |> thenResolve(Js.log)); */