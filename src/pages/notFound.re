let component = ReasonReact.statelessComponent("NotFound");

let make = (_children) => {
  ...component,
  render: (_self) => <div> <Hello message="Sorry page not found" /> </div>
};