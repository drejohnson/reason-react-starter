type t;

type base;

type bodyAttributes;

type htmlAttributes;

type link;

type meta;

type noscript;

type script;

type style;

type titleAttributes;

let optionToBool = (optional) =>
  switch optional {
  | Some(_) => true
  | _ => false
  };

type props = {
  .
  "base": Js.Nullable.t(base),
  "bodyAttributes": Js.Nullable.t(bodyAttributes),
  "defaultTitle": Js.Nullable.t(string),
  "encodeSpecialCharacters": Js.boolean,
  "htmlAttributes": Js.Nullable.t(htmlAttributes),
  "link": Js.Nullable.t(array(link)),
  "meta": Js.Nullable.t(array(meta)),
  "noscript": Js.Nullable.t(array(noscript)),
  "onChangeClientState": Js.Nullable.t(((~newState: t) => t)),
  "script": Js.Nullable.t(array(script)),
  "style": Js.Nullable.t(array(style)),
  "title": Js.Nullable.t(string),
  "titleAttributes": Js.Nullable.t(titleAttributes),
  "titleTemplate": Js.Nullable.t(string)
};

[@bs.module "react-helmet"] external helmet : ReasonReact.reactClass = "Helmet";

[@bs.val] [@bs.scope "Helmet"] [@bs.module "react-helmet"]
external renderStatic : unit => Js.t('a) =
  "renderStatic";

let make =
    (
      ~base=?,
      ~bodyAttributes=?,
      ~defaultTitle=?,
      ~encodeSpecialCharacters=?,
      ~htmlAttributes=?,
      ~link=?,
      ~meta=?,
      ~noscript=?,
      ~onChangeClientState=?,
      ~script=?,
      ~style=?,
      ~title=?,
      ~titleAttributes=?,
      ~titleTemplate=?,
      children
    ) => {
  let props: props = {
    "base": Js.Nullable.from_opt(base),
    "bodyAttributes": Js.Nullable.from_opt(bodyAttributes),
    "defaultTitle": Js.Nullable.from_opt(defaultTitle),
    "encodeSpecialCharacters": Js.Boolean.to_js_boolean(optionToBool(encodeSpecialCharacters)),
    "htmlAttributes": Js.Nullable.from_opt(htmlAttributes),
    "link": Js.Nullable.from_opt(link),
    "meta": Js.Nullable.from_opt(meta),
    "noscript": Js.Nullable.from_opt(noscript),
    "onChangeClientState": Js.Nullable.from_opt(onChangeClientState),
    "script": Js.Nullable.from_opt(script),
    "style": Js.Nullable.from_opt(style),
    "title": Js.Nullable.from_opt(title),
    "titleAttributes": Js.Nullable.from_opt(titleAttributes),
    "titleTemplate": Js.Nullable.from_opt(titleTemplate)
  };
  ReasonReact.wrapJsForReason(~reactClass=helmet, ~props, children)
};