let rule = (props) => {
  "backgroundImage": props##backgroundImage,
  "width": props##width,
  "height": props##height,
  "backgroundSize": props##backgroundSize,
  "backgroundRepeat": props##backgroundRepeat,
  "backgroundPosition": props##backgroundPosition,
  "borderRadius": props##borderRadius
};

let make =
    (
      ~backgroundImage=?,
      ~width=?,
      ~height=?,
      ~backgroundSize=?,
      ~backgroundRepeat=?,
      ~backgroundPosition=?,
      ~borderRadius=?,
      children
    ) =>
  ReactFela.createComponent(
    ~rule,
    ~props={
      "backgroundImage": backgroundImage,
      "width": Js.Nullable.from_opt(width),
      "height": Js.Nullable.from_opt(height),
      "backgroundSize": Js.Nullable.from_opt(backgroundSize),
      "backgroundRepeat": Js.Nullable.from_opt(backgroundRepeat),
      "backgroundPosition": Js.Nullable.from_opt(backgroundPosition),
      "borderRadius": Js.Nullable.from_opt(borderRadius)
    },
    children
  );