open ReactRouter;

let text = ReasonReact.stringToElement;

let component = ReasonReact.statelessComponent("Navigation");

let make = (_children) => {
  ...component,
  render: (_self) =>
    <nav> <Link _to="/"> (text("Home")) </Link> <Link _to="/about"> (text("About")) </Link> </nav>
};