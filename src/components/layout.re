[@bs.module "utils/fonts"] external fonts : unit => unit = "default";

let component = ReasonReact.statelessComponent("Page");

let make = (~style=?, children) => {
  ...component,
  didMount: (_self) => {
    fonts();
    ReasonReact.NoUpdate
  },
  render: (_self) =>
    <View ?style>
      <Header />
      (ReasonReact.createDomElement("div", ~props=Js.Obj.empty(), children))
    </View>
};