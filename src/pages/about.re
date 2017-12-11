let component = ReasonReact.statelessComponent("About");

let make = (_children) => {
  ...component,
  render: (_self) =>
    <div>
      <ReactHelmet>
        <title> (Utils.text("About ReasonReact Starter")) </title>
        <meta name="description" content="About page description" />
      </ReactHelmet>
      <Hello message="Hello from about component" />
    </div>
};