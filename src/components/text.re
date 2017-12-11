let rule = (props) => Css.(style([fontSize(rem(props##fontSize)), color(props##color)]));

let make = (~_as, ~fontSize, ~color, children) =>
  ReactFela.createComponent(
    ~rule,
    ~baseElement=`String({j|$(_as)|j}),
    ~props={"_as": _as, "fontSize": fontSize, "color": color},
    children
  );