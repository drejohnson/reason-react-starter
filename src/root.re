open ReactRouter;

let renderHome = () => <Home />;

let renderAbout = () => <About />;

let renderNotFound = () => <NotFound />;

let component = ReasonReact.statelessComponent("Root");

let make = (_children) => {
  ...component,
  render: (_self) =>
    <div>
      <Header />
      <Switch>
        <Route path="/" exact=true component=renderHome />
        <Route path="/about" exact=true component=renderAbout />
        <Route component=renderNotFound />
      </Switch>
    </div>
};