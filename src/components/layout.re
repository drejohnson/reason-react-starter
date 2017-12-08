let rule = (props) => {"backgroundColor": props##theme##page##backgroundColor};

let make = (children) =>
  ReactFela.createComponent(~rule, ~baseElement=`String("div"), ~props=Js.Obj.empty(), children);