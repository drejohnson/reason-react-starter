[@bs.val] [@bs.module "react-dom"] external hydrate : (ReasonReact.reactElement, 'a) => unit =
  "hydrate";

[@bs.module "./registerServiceWorker"] external register_service_worker : unit => unit = "default";

module AppContainer = {
  [@bs.module "react-hot-loader"] external appContainer : ReasonReact.reactClass = "AppContainer";
  let make = (children) =>
    ReasonReact.wrapJsForReason(~reactClass=appContainer, ~props=Js.Obj.empty(), children);
};

let rootId = Utils.get_by_id(Utils.dom, "root");

let app = Utils.isPROD ? <Root /> : <AppContainer> <Root /> </AppContainer>;

let _ = hydrate(app, rootId);

if (Utils.hot) {
  Utils.accept()
};

register_service_worker();