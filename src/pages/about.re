let text = ReasonReact.stringToElement;

let component = ReasonReact.statelessComponent("About");

let make = (_children) => {
  ...component,
  render: (_self) =>
    <View>
      <ReactHelmet>
        <title> (text("About ReasonReact Starter")) </title>
        <meta name="description" content="About page description" />
      </ReactHelmet>
      <Hello message="Hello from about component" />
    </View>
};