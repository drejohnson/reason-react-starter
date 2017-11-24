let component = ReasonReact.statelessComponent("Root");

let make = (_children) => {
  ...component,
  render: (_self) =>
    <div className="App">
      <div className="App-header">
        /* <img src=logo className="App-logo" alt="logo" /> */
         <h2> (ReasonReact.stringToElement("Welcome to React and Reason")) </h2> </div>
      <p className="App-intro">
        (ReasonReact.stringToElement("To get started, edit"))
        <code> (ReasonReact.stringToElement(" src/App.re ")) </code>
        (ReasonReact.stringToElement("and save to reload."))
      </p>
    </div>
};