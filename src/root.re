open ReactRouter;

let text = ReasonReact.stringToElement;

let renderHome = () => <Home />;

let renderAbout = () => <About />;

let renderNotFound = () => <NotFound />;

let component = ReasonReact.statelessComponent("Root");

let make = (_children) => {
  ...component,
  render: (_self) =>
    <div>
      <ReactHelmet>
        <meta charSet="utf-8" />
        <meta name="viewport" content="width=device-width, initial-scale=1" />
        <meta name="theme-color" content="#000000" />
        <link rel="manifest" href="/manifest.json" />
        <link rel="shortcut icon" href="/favicon.ico" />
        <title> (text("ReasonReact Starter")) </title>
        <meta
          name="description"
          content="Reason lets you write simple, fast and quality type safe code while leveraging both the JavaScript & OCaml ecosystems."
        />
      </ReactHelmet>
      <Header />
      <Switch>
        <Route path="/" exact=true component=renderHome />
        <Route path="/about" exact=true component=renderAbout />
        <Route component=renderNotFound />
      </Switch>
    </div>
};