open ReactRouter;

[@bs.val] [@bs.module "react-dom"] external hydrate : (ReasonReact.reactElement, 'a) => unit =
  "hydrate";

[@bs.module "./registerServiceWorker"] external register_service_worker : unit => unit = "default";

module AppContainer = {
  [@bs.module "react-hot-loader"] external appContainer : ReasonReact.reactClass = "AppContainer";
  let make = (children) =>
    ReasonReact.wrapJsForReason(~reactClass=appContainer, ~props=Js.Obj.empty(), children);
};

let rootId = Utils.getElementById(Utils.dom, "root");

let renderer = FelaRenderer.renderer;

/* Using contents of Root component as a work around to get routing to work client side. Issue is with context I believe */
let app = () =>
  Utils.isPROD ?
    <Fela.Provider renderer>
      <Fela.ThemeProvider theme={"color": "blue", "fontSize": "15px"}>
        ...<BrowserRouter>
             <div>
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