let text = ReasonReact.stringToElement;

let component = ReasonReact.statelessComponent("About");

let make = (_children) => {
  ...component,
  render: (_self) => <View> <Hello message="Hello from about component" /> </View>
};