/* https://github.com/bloodyowl/reReactPrimitives/blob/master/src/image.re */
type state = {isReady: bool};

let component = ReasonReact.reducerComponent("Image");

type resizeMode =
  | Cover
  | Contain
  | Actual;

type unit =
  | PX(int)
  | EM(int)
  | REM(int)
  | VH(int)
  | VW(int)
  | PCT(int)
  | AUTO;

/* type width = unit;

   type height = unit; */
let size = (size) =>
  switch size {
  | PX(size) => string_of_int(size) ++ "px"
  | EM(size) => string_of_int(size) ++ "em"
  | REM(size) => string_of_int(size) ++ "rem"
  | VH(size) => string_of_int(size) ++ "vh"
  | VW(size) => string_of_int(size) ++ "vw"
  | PCT(size) => string_of_int(size) ++ "%"
  | AUTO => "auto"
  };

let make = (~source, ~width, ~height, ~resizeMode, ~backgroundColor=?, _children) => {
  ...component,
  initialState: (_) => {isReady: false},
  reducer: ((), _state) => ReasonReact.NoUpdate,
  didMount: (_self) => ReasonReact.Update({isReady: true}),
  render: ({state}) =>
    <div
      style=(
        ReactDOMRe.Style.make(
          ~width=size(width),
          ~height=size(height),
          ~backgroundSize=
            switch resizeMode {
            | Cover => "cover"
            | Actual => "auto"
            | Contain => "contain"
            },
          ~backgroundRepeat="no-repeat",
          ~backgroundPosition="50% 50%",
          ~backgroundImage=state.isReady ? "url(" ++ (source ++ ")") : "",
          /* TODO: FIX ROUND */
          /* ~borderRadius=round ? string_of_int(min(width, height)) ++ "px" : "0px", */
          ()
        )
      )
    />
};