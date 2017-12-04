open ReactRouter;

[@bs.val] [@bs.module "react-dom"] external hydrate : (ReasonReact.reactElement, 'a) => unit =
  "hydrate";

[@bs.module "./registerServiceWorker"] external register_service_worker : unit => unit = "default";

module AppContainer = {
  [@bs.module "react-hot-loader"] external appContainer : ReasonReact.reactClass = "AppContainer";
  let make = (children) =>
    ReasonReact.wrapJsForReason(~reactClass=appContainer, ~props=Js.Obj.empty(), children);
};

let text = ReasonReact.stringToElement;

let rootId = Utils.getElementById(Utils.dom, "root");

let renderer = FelaRenderer.renderer;

/* Using contents of Root component as a work around to get routing to work client side. Issue is with context I believe */
let app = () =>
  Utils.isPROD ?
    <Fela.Provider renderer>
      <Fela.ThemeProvider theme={"color": "blue", "fontSize": "15px"}>
        ...<BrowserRouter>
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
                 <Route path="/" exact=true component=(() => <Home />) />
                 <Route path="/about" exact=true component=(() => <About />) />
                 <Route component=(() => <NotFound />) />
               </Switch>
             </div>
           </BrowserRouter>
      </Fela.ThemeProvider>
    </Fela.Provider> :
    <AppContainer>
      <Fela.Provider renderer>
        <Fela.ThemeProvider theme={"color": "blue", "fontSize": "15px"}>
          ...<BrowserRouter>
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
                   <Route path="/" exact=true component=(() => <Home />) />
                   <Route path="/about" exact=true component=(() => <About />) />
                   <Route component=(() => <NotFound />) />
                 </Switch>
               </div>
             </BrowserRouter>
        </Fela.ThemeProvider>
      </Fela.Provider>
    </AppContainer>;

let render = (component) => hydrate(component(), rootId);

render(app);

if (Utils.hot) {
  Utils.accept()
};

register_service_worker();