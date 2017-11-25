/* [@bs.module] external logo : string = "../logo.svg"; */
let text = ReasonReact.stringToElement;

let component = ReasonReact.statelessComponent("Header");

let make = (_children) => {
  ...component,
  render: (_self) =>
    <header>
      <Image
        source="/images/logo.svg"
        width=(REM(7))
        height=(REM(7))
        resizeMode=Contain
        backgroundColor="white"
      />
      <Navigation />
    </header>
};