open ReactRouter;

let component = ReasonReact.statelessComponent("Navigation");

let make = (_children) => {
  ...component,
  render: (_self) =>
    <nav>
      <Link _to="/"> (Utils.text("Home")) </Link>
      <Link _to="/about"> (Utils.text("About")) </Link>
    </nav>
};