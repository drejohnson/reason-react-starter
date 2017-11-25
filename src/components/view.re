/* https://github.com/bloodyowl/reReactPrimitives/blob/master/src/view.re */
let component = ReasonReact.statelessComponent("View");

let make = (~style=?, children) => {
  ...component,
  render: (_self) =>
    ReasonReact.createDomElement("div", ~props={"style": Js.Nullable.from_opt(style)}, children)
};