open Css;

/* let default =
   style([
     color(hex("222")),
     fontSize(rem(2.5)),
     backgroundColor(hex("EEE")),
     display(Grid),
     gridTemplateRows("repeat(3, 1fr)"),
     gridTemplateColumns("repeat(3, 1fr)"),
     gridRowGap(px(10)),
     gridColumnGap(px(10)),
     gridAutoRows("minmax(100px, auto)")
   ]); */
let default = {
  "color": hex("222"),
  "fontSize": rem(2.5),
  "backgroundColor": hex("EEE"),
  "backgroundImage": backgroundImage("/images/logo.svg"),
  "display": display(Grid),
  "gridTemplateRows": gridTemplateRows("repeat(3, 1fr)"),
  "gridTemplateColumns": gridTemplateColumns("repeat(3, 1fr)"),
  "gridRowGap": gridRowGap(px(10)),
  "gridColumnGap": gridColumnGap(px(10)),
  "gridAutoRows": gridAutoRows("minmax(100px, auto)"),
  "page": {"backgroundColor": hex("EEE")},
  "header": {"backgroundColor": hex("EEE")}
};