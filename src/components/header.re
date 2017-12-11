let component = ReasonReact.statelessComponent("Header");

let make = (_children) => {
  ...component,
  render: (_self) =>
    <header>
      <Image
        backgroundImage="/images/logo.svg"
        width=(Css.px(100))
        height=(Css.px(100))
        backgroundSize=Cover
        backgroundPosition=Center
        backgroundRepeat=NoRepeat
      />
      <Navigation />
    </header>
};