let component = ReasonReact.statelessComponent("LogView");

let make = (_children) => {
  ...component,
  render: (_self) => {
    if (Utils.isBrowser) {
      ReactGA.set({"page": Utils.pathname});
      ReactGA.pageview(Utils.pathname)
    };
    ReasonReact.nullElement
  }
};