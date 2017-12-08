module Component = {
  let component = ReasonReact.statelessComponent("Component");
  let make = (~theme, children) => {...component, render: (_self) => children[0](theme)};
};

let make = (children) =>
  ReactFela.withTheme(~component=Component.component, ~make=Component.make, children);