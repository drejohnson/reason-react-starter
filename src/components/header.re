/* [@bs.module] external logo : string = "../logo.svg"; */
let text = ReasonReact.stringToElement;

let component = ReasonReact.statelessComponent("Header");

let make = (_children) => {
  ...component,
  render: (_self) =>
    <header>
      <Image
        backgroundImage=(Css.backgroundImage("/images/logo.svg"))
        width=(Css.px(100))
        height=(Css.px(100))
        backgroundSize=(Css.backgroundSize(Cover))
        backgroundPosition=(Css.backgroundPosition(Center))
        backgroundRepeat=(Css.backgroundRepeat(NoRepeat))
      />
      <Navigation />
    </header>
};