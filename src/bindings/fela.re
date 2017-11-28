type t;

type renderer;

[@bs.obj]
external rendererConfig :
  (
    ~plugins: array(t)=?,
    ~enhancers: array(t)=?,
    ~mediaQueryOrder: array(string)=?,
    ~supportQueryOrder: array(string)=?,
    ~selectorPrefix: string=?,
    unit
  ) =>
  renderer =
  "";

[@bs.module "fela-dom"] external renderToMarkup : renderer => renderer = "renderToMarkup";

[@bs.module "fela"] external createRenderer : renderer => renderer = "";

let defaultRenderer = createRenderer(rendererConfig());

/* Providers lifted from bs-react-fela. Added the ability to add plugins to renderer */
/* TODO: polymorphic variants for renderer? */
module Provider = {
  [@bs.module "react-fela"] external provider : ReasonReact.reactClass = "Provider";
  let make = (~renderer, children) =>
    ReasonReact.wrapJsForReason(~reactClass=provider, ~props={"renderer": renderer}, children);
};

/* Not needed. Can just use bs-react-fela's ThemeProvider */
/* TODO: remove */
module ThemeProvider = {
  [@bs.module "react-fela"] external reactClass : ReasonReact.reactClass = "ThemeProvider";
  let make = (~theme, ~overwrite=false, children) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props={"theme": theme, "overwrite": Js.Boolean.to_js_boolean(overwrite)},
      children
    );
};