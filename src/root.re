open ReactRouter;

Utils.isBrowser ? ReactGA.initialize("UA-40660556-1") : ();

let text = ReasonReact.stringToElement;

let renderHome = () => <Home />;

let renderAbout = () => <About />;

let renderNotFound = () => <NotFound />;

let make = () =>
  <Layout>
    <ReactHelmet>
      <meta charSet="utf-8" />
      <meta name="viewport" content="width=device-width, initial-scale=1" />
      <meta name="theme-color" content="#000000" />
      <link rel="manifest" href="/manifest.json" />
      <link rel="shortcut icon" href="/favicon.ico" />
      <title> (text("ReasonReact Parcel")) </title>
      <meta
        name="description"
        content="Reason lets you write simple, fast and quality type safe code while leveraging both the JavaScript & OCaml ecosystems."
      />
    </ReactHelmet>
    <Route path="/" component=(() => <LogView />) />
    <Header />
    <Switch>
      <Route path="/" exact=true component=renderHome />
      <Route path="/about" exact=true component=renderAbout />
      <Route component=renderNotFound />
    </Switch>
  </Layout>;