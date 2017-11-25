let text = ReasonReact.stringToElement;

let component = ReasonReact.statelessComponent("Home");

let make = (_children) => {
  ...component,
  render: (_self) => <View> <Hello message="Hello from home component" /> </View>
};