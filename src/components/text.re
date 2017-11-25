/* https://github.com/bloodyowl/reReactPrimitives/blob/master/src/text.re */
let component = ReasonReact.statelessComponent("Text");

let make = (~style=?, ~_as=?, children) => {
  ...component,
  render: (_self) => {
    let elementAs = (_as) =>
      switch _as {
      | Some(string) => string
      | None => "p"
      };
    ReasonReact.createDomElement(
      elementAs(_as),
      ~props={"style": Js.Nullable.from_opt(style)},
      children
    )
  }
};