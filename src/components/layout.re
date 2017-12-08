let rule = (props) => {
  "display": props##theme##display,
  "backgroundColor": props##theme##backgroundColor,
  "gridTemplateRows": props##theme##gridTemplateRows,
  "gridRowGap": props##theme##gridRowGap
};

let make = (children) =>
  ReactFela.createComponent(~rule, ~baseElement=`String("div"), ~props=Js.Obj.empty(), children);