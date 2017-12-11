type plugins;

type enhancers;

type renderer;

[@bs.obj]
external rendererConfig :
  (
    ~plugins: array(plugins)=?,
    ~enhancers: array(enhancers)=?,
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
module Provider = {
  [@bs.module "react-fela"] external provider : ReasonReact.reactClass = "Provider";
  let make = (~renderer, children) =>
    ReasonReact.wrapJsForReason(~reactClass=provider, ~props={"renderer": renderer}, children);
};