let rule = (props) => Css.(style([backgroundColor(props##theme##backgroundColor)]));

let make = (children) =>
  ReactFela.createComponent(~rule, ~baseElement=`String("div"), ~props=Js.Obj.empty(), children);