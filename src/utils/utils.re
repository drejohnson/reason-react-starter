[@bs.val] external nodeEnv : string = "process.env.NODE_ENV";

let isPROD = nodeEnv === "production";

let dangerousHtml: string => Js.t('a) = (html) => {"__html": html};

type dom;

[@bs.val] external dom : dom = "document";

type element;

[@bs.send] external get_by_id : (dom, string) => element = "getElementById";

[@bs.val] external hot : bool = "module.hot";

[@bs.val] external accept : unit => unit = "module.hot.accept";