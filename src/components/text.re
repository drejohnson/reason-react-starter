let rule = (props) => {"fontSize": props##fontSize, "color": props##color};

let make = (~_as, ~fontSize=?, ~color=?, children) =>
  ReactFela.createComponent(
    ~rule,
    ~baseElement=`String({j|$(_as)|j}),
    ~props={
      "_as": _as,
      "fontSize": Js.Nullable.from_opt(fontSize),
      "color": Js.Nullable.from_opt(color)
    },
    children
  );