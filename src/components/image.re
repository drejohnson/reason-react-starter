let rule = (props) => {
  let borderRadius_ = props##borderRadius;
  let borderRadius_ = Js.Nullable.to_opt(borderRadius_);
  let borderRadius_ = Js.Option.getWithDefault(Css.px(0), borderRadius_);
  Css.(
    style([
      backgroundImage(props##backgroundImage),
      backgroundSize(props##backgroundSize),
      backgroundRepeat(props##backgroundRepeat),
      backgroundPosition(props##backgroundPosition),
      borderRadius(borderRadius_),
      width(props##width),
      height(props##height)
    ])
  )
};

let make =
    (
      ~backgroundImage,
      ~backgroundSize,
      ~backgroundRepeat,
      ~backgroundPosition,
      ~borderRadius=?,
      ~width,
      ~height,
      children
    ) =>
  ReactFela.createComponent(
    ~rule,
    ~props={
      "backgroundImage": backgroundImage,
      "width": width,
      "height": height,
      "backgroundSize": backgroundSize,
      "backgroundRepeat": backgroundRepeat,
      "backgroundPosition": backgroundPosition,
      "borderRadius": Js.Nullable.from_opt(borderRadius)
    },
    children
  );