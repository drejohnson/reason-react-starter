let text = (props) => {
  let color = props##theme##color;
  let color = Js.Nullable.to_opt(color);
  let color = Js.Option.getWithDefault("red", color);
  {"fontSize": props##theme##fontSize, "color": color}
};

let make = (children) => ReactFela.createComponent(~rule=text, ~props=Js.Obj.empty(), children);