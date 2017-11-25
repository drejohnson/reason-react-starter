let text = ReasonReact.stringToElement;

let component = ReasonReact.statelessComponent("NotFound");

let make = (_children) => {
  ...component,
  render: (_self) => <View> <Hello message="Sorry page not found" /> </View>
};