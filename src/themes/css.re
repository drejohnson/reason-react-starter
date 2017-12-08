/*
   ** adapted from the excellent bs-css repo: https://github.com/SentiaAnalytics/bs-css/blob/master/src/Css.re
   ** Removed the Glamor parts since I just want the css typings for types theming
 */
type css = string;

type rule =
  | Property(string)
  | Selector(list(rule));

type angle = string;

let join = (sep, strings) => {
  let rec j = (acc) =>
    fun
    | [] => acc
    | [x] => acc ++ x
    | [x, y, ...strings] => j(acc ++ (x ++ sep), [y, ...strings]);
  j("", strings)
};

/* let intProp = (v) => string_of_int(v);

   let stringProp = (v) => v; */
/* let important = (v) =>
   switch v {
   | Property(name, value) => Property(name, value ++ " !important")
   | _ => v
   }; */

/*********
 * COLORS
 **********/
type color = string;

let rgb = (r, g, b) => {j|rgb($r, $g, $b)|j};

let rgba = (r, g, b, a) => {j|rgba($r, $g, $b, $a)|j};

let white = "white";

let black = "black";

let hex = (v) => "#" ++ v;


/*********
 * UNITS
 **********/
type cssunit = string;

let px = (i) => {j|$(i)px|j};

let pct = (i) => {j|$(i)%|j};

let rem = (i) => {j|$(i)rem|j};

let em = (i) => {j|$(i)em|j};

let cm = (i) => {j|$(i)cm|j};

let mm = (i) => {j|$(i)mm|j};

let vh = (i) => {j|$(i)vh|j};

let vw = (i) => {j|$(i)vw|j};

let fr = (i) => {j|$(i)fr|j};

let zero = "0";


/*********
 * ANGLE
 **********/
let rad = (i) => {j|$(i)rad|j};

let deg = (i) => {j|$(i)deg|j};

let turn = (i) => {j|$(i)turn|j};


/*********
 * CSS RULES
 **********/
/* let unsafe = (name, value) => Property(name, value); */
type visibility =
  | Visible
  | Hidden;

let visibility = (v) =>
  switch v {
  | Hidden => "hidden"
  | Visible => "visible"
  };

let opacity = (v) => {j|$v|j};

/* BACKGROUND */
let backgroundImage = (url) => {j|url($url)|j};

type backgroundAttachment =
  | Scroll
  | Fixed
  | Local
  | Initial;

let backgroundAttachment = (v) =>
  switch v {
  | Scroll => "scroll"
  | Fixed => "fixed"
  | Local => "local"
  | Initial => "initial"
  };

let backgroundColor = (v) => {j|$v|j};

type backgroundSize =
  | Cover
  | Contain
  | Width(cssunit)
  | Height(cssunit)
  | Custom(cssunit, cssunit);

let backgroundSize = (v) =>
  switch v {
  | Cover => "cover"
  | Contain => "contain"
  | Width(v) => v
  | Height(v) => "auto " ++ v
  | Custom(v, h) => v ++ (" " ++ h)
  };

type backgroundPosition =
  | Top
  | Bottom
  | Left
  | Right
  | Center;

let backgroundPosition = (v) =>
  switch v {
  | Top => "top"
  | Bottom => "bottom"
  | Left => "left"
  | Right => "right"
  | Center => "center"
  };

type backgroundRepeat =
  | RepeatX
  | RepeatY
  | Repeat
  | Space
  | Round
  | NoRepeat;

let backgroundRepeat = (v) =>
  switch v {
  | RepeatX => "repeat-x"
  | RepeatY => "repeat-y"
  | Repeat => "repeat"
  | Space => "space"
  | Round => "round"
  | NoRepeat => "no-repeat"
  };

type background =
  | None
  | Color(color)
  | Image(string);

let background = (v) =>
  switch v {
  | None => "none"
  | Color(color) => color
  | Image(url) => {j|url($url)|j}
  };

/* TEXT */
let color = (color) => {j|$color|j};

let fontFamily = (v) => {j|$v|j};

let fontSize = (v) => {j|$v|j};

type fontStyle =
  | Normal
  | Italic
  | Oblique;

let fontStyle = (v) =>
  switch v {
  | Normal => "normal"
  | Italic => "italic"
  | Oblique => "oblique"
  };

type fontWeight =
  | Normal
  | Bold
  | W100
  | W200
  | W300
  | W400
  | W500
  | W600
  | W700
  | W800
  | W900;

let fontWeight = (v) =>
  switch v {
  | Normal => "normal"
  | Bold => "bold"
  | W100 => "100"
  | W200 => "200"
  | W300 => "300"
  | W400 => "400"
  | W500 => "500"
  | W600 => "600"
  | W700 => "700"
  | W800 => "800"
  | W900 => "900"
  };

let textShadow = (x, y, color) => {j|$(x) $(y) $(color)|j};

let textIndent = (v) => {j|$v|j};

type textAlign =
  | Auto
  | Left
  | Right
  | Center
  | Justify;

let textAlign = (v) =>
  switch v {
  | Auto => "auto"
  | Left => "left"
  | Right => "right"
  | Center => "center"
  | Justify => "justify"
  };

type textDecoration =
  | None
  | Underline(color)
  | UnderlineWavy(color);

let textDecoration = (v) =>
  switch v {
  | None => "none"
  | Underline(color) => "underline " ++ color
  | UnderlineWavy(color) => "underline wavy " ++ color
  };

type textTransform =
  | None
  | Uppercase
  | Lowercase
  | Capitalize
  | FullWidth;

let textTransform = (v) =>
  switch v {
  | None => "none"
  | Uppercase => "uppercase"
  | Lowercase => "lowercase"
  | Capitalize => "capitalize"
  | FullWidth => "fullwidth"
  };

let lineHeight = (v) => {j|$v|j};

let letterSpacing = (v) => {j|$v|j};

/* BORDER */
type borderStyle =
  | None
  | Hidden
  | Solid
  | Dotted
  | Dashed
  | Double;

let borderStyleToString = (s) =>
  switch s {
  | None => "none"
  | Hidden => "hidden"
  | Solid => "solid"
  | Dotted => "dotted"
  | Dashed => "dashed"
  | Double => "double"
  };

let border = (width, style, color) => {j|$(width) $borderStyleToString($style) $(color) |j};

let borderTop = (width, style, color) => {j|$(width) $borderStyleToString($style) $(color) |j};

let borderBottom = (width, style, color) => {j|$(width) $borderStyleToString($style) $(color) |j};

let borderLeft = (width, style, color) => {j|$(width) $borderStyleToString($style) $(color) |j};

let borderRight = (width, style, color) => {j|$(width) $borderStyleToString($style) $(color) |j};

let borderWidth = (v) => {j|$v|j};

let borderTopWidth = (v) => {j|$v|j};

let borderBottomWidth = (v) => {j|$v|j};

let borderLeftWidth = (v) => {j|$v|j};

let borderRightWidth = (v) => {j|$v|j};

let borderStyle = (style) => borderStyleToString(style);

let borderTopStyle = (style) => borderStyleToString(style);

let borderBottomStyle = (style) => borderStyleToString(style);

let borderLeftStyle = (style) => borderStyleToString(style);

let borderRightStyle = (style) => borderStyleToString(style);

let borderColor = (color) => color;

let borderTopColor = (color) => color;

let borderBottomColor = (color) => color;

let borderLeftColor = (color) => color;

let borderRightColor = (color) => color;

let borderRadius = (v) => {j|$v|j};

let borderTopRightRadius = (v) => {j|$v|j};

let borderTopLeftRadius = (v) => {j|$v|j};

let borderBottomRightRadius = (v) => {j|$v|j};

let borderBottomLeftRadius = (v) => {j|$v|j};

/* LAYOUT */
let width = (v) => {j|$v|j};

let minWidth = (v) => {j|$v|j};

let maxWidth = (v) => {j|$v|j};

let height = (v) => {j|$v|j};

let minHeight = (v) => {j|$v|j};

let maxHeight = (v) => {j|$v|j};

let left = (v) => {j|$v|j};

let right = (v) => {j|$v|j};

let top = (v) => {j|$v|j};

let bottom = (v) => {j|$v|j};

let margin = (v) => {j|$v|j};

let marginLeft = (v) => {j|$v|j};

let marginRight = (v) => {j|$v|j};

let marginTop = (v) => {j|$v|j};

let marginBottom = (v) => {j|$v|j};

let padding = (v) => {j|$v|j};

let paddingLeft = (v) => {j|$v|j};

let paddingRight = (v) => {j|$v|j};

let paddingTop = (v) => {j|$v|j};

let paddingBottom = (v) => {j|$v|j};

type display =
  | Block
  | None
  | Inline
  | Flex
  | Grid
  | Subgrid
  | Contents
  | Table
  | TableRow
  | TableCell
  | TableColumn
  | InlineBlock
  | InlineTable
  | InlineFlex
  | InlineGrid;

let display = (v) =>
  switch v {
  | Block => "block"
  | None => "none"
  | Inline => "inline"
  | Flex => "flex"
  | Grid => "grid"
  | Subgrid => "subgrid"
  | Contents => "contents"
  | Table => "table"
  | TableRow => "table-row"
  | TableCell => "table-cell"
  | TableColumn => "table-column"
  | InlineBlock => "inline-block"
  | InlineTable => "inline-table"
  | InlineFlex => "inline-flex"
  | InlineGrid => "inline-grid"
  };

type position =
  | Static
  | Relative
  | Absolute
  | Fixed
  | Sticky;

let position = (v) =>
  switch v {
  | Static => "static"
  | Relative => "relative"
  | Absolute => "absolute"
  | Fixed => "fixed"
  | Sticky => "sticky"
  };

type boxSizing =
  | BorderBox
  | ContentBox;

let boxSizing = (v) =>
  switch v {
  | BorderBox => "border-box"
  | ContentBox => "content-box"
  };

type overflow =
  | Visible
  | Hidden
  | Scroll
  | Auto;

let overflow = (o) =>
  switch o {
  | Visible => "visible"
  | Hidden => "hidden"
  | Auto => "auto"
  | Scroll => "scroll"
  };

let overflowX = (o) =>
  switch o {
  | Visible => "visible"
  | Hidden => "hidden"
  | Auto => "auto"
  | Scroll => "scroll"
  };

let overflowY = (o) =>
  switch o {
  | Visible => "visible"
  | Hidden => "hidden"
  | Auto => "auto"
  | Scroll => "scroll"
  };

let zIndex = (v) => string_of_int(v);

/* FLEXBOX */
let flex = (v) => string_of_int(v);

let flexBasis = (v) => string_of_int(v);

let flexGrow = (v) => string_of_int(v);

let flexShrink = (v) => string_of_int(v);

let flexFlow = (v) => string_of_int(v);

let order = (v) => string_of_int(v);

type flexDirection =
  | Row
  | RowReverse
  | Column
  | ColumnReverse;

let flexDirection = (v) =>
  switch v {
  | Row => "row"
  | RowReverse => "row-reverse"
  | Column => "column"
  | ColumnReverse => "column-reverse"
  };

type flexWrap =
  | Wrap
  | NoWrap;

let flexWrap = (v) =>
  switch v {
  | Wrap => "wrap"
  | NoWrap => "no-wrap"
  };

type justify =
  | FlexStart
  | FlexEnd
  | Center
  | Stretch
  | SpaceAround
  | SpaceBetween;

let justifyToString = (v) =>
  switch v {
  | FlexStart => "flex-start"
  | FlexEnd => "flex-end"
  | Center => "center"
  | Stretch => "stretch"
  | SpaceAround => "space-around"
  | SpaceBetween => "space-between"
  };

let alignContent = (v) => justifyToString(v);

type alignment =
  | FlexStart
  | FlexEnd
  | Center
  | Stretch
  | Baseline;

let alignmentToString = (v) =>
  switch v {
  | FlexStart => "flex-start"
  | FlexEnd => "flex-end"
  | Center => "center"
  | Stretch => "stretch"
  | Baseline => "baseline"
  };

let alignItems = (v) => alignmentToString(v);

let alignSelf = (v) => alignmentToString(v);

let justifyContent = (v) => justifyToString(v);

/* CSS GRID */
type grid = string;

/* let gridTemplateRows = (cssunit) => Property("gridTemplateRows", join(" ", cssunit));

   let gridTemplateColumns = (cssunit) => Property("gridTemplateColumns", join(" ", cssunit)); */
let gridTemplateRows = (v) => v;

let gridTemplateColumns = (v) => v;

let gridAutoRows = (v) => v;

let gridAutoColumns = (v) => v;

let gridAutoFlow = (v) => v;

let gridRowStart = (v) => v;

let gridColumnStart = (v) => v;

let gridRowEnd = (v) => v;

let gridColumnEnd = (v) => v;

let gridRow = (v) => v;

let gridColumn = (v) => v;

let gridRowGap = (v) => v;

let gridColumnGap = (v) => v;

/* SHADOW */
type shadow = string;

let shadow = (~x=0, ~y=0, ~blur=0, ~spread=0, color) => {j|$(x)px $(y)px $(blur)px $(spread)px $color|j};

let boxShadow = (v) => v;

let boxShadows = (shadows) => join(", ", shadows);

/* ANIMATION */
type keyframes = string;

let animationName = (v) => v;

let animationDuration = (ms) => string_of_int(ms) ++ "ms";

let animationDelay = (ms) => string_of_int(ms) ++ "ms";

type animationDirection =
  | Normal
  | Reverse
  | Alternate
  | AlternateReverse;

let animationDirection = (v) =>
  switch v {
  | Normal => "normal"
  | Reverse => "reverse"
  | Alternate => "alternate"
  | AlternateReverse => "alternate-reverse"
  };

type animationFillMode =
  | None
  | Forwards
  | Backwards
  | Both;

let animationFillMode = (v) =>
  switch v {
  | None => "none"
  | Forwards => "forwards"
  | Backwards => "backwards"
  | Both => "both"
  };

type animationIterationCount =
  | Infinite
  | Iterate(int);

let animationIterationCount = (v) =>
  switch v {
  | Infinite => "infinite"
  | Iterate(v) => string_of_int(v)
  };

type animationPlayState =
  | Paused
  | Running;

let animationPlayState = (v) =>
  switch v {
  | Paused => "paused"
  | Running => "running"
  };

type animationSteps =
  | Start
  | End;

let animationStepsToString = (s) =>
  switch s {
  | Start => "start"
  | End => "end"
  };

type timingFunction =
  | Ease
  | EaseIn
  | EaseOut
  | EaseInOut
  | Linear
  | StepStart
  | StepEnd
  | CubicBezier(float, float, float, float)
  | Steps(int, animationSteps)
  | Frames(int);

let timingFunctionToString = (v) =>
  switch v {
  | Ease => "ease"
  | EaseIn => "ease-in"
  | EaseOut => "ease-out"
  | EaseInOut => "ease-in-out"
  | Linear => "linear"
  | StepStart => "step-start"
  | StepEnd => "step-end"
  | CubicBezier(x1, y1, x2, y2) => {j|cubic-bezier($x1, $y1, $x2, $y2)|j}
  | Steps(i, s) => "steps(" ++ (string_of_int(i) ++ (", " ++ (animationStepsToString(s) ++ ")")))
  | Frames(i) => {j|frames($i)|j}
  };

let animationTimingFunction = (v) => timingFunctionToString(v);

/* TRANSITION */
let transitionDelay = (v) => string_of_int(v);

let transitionDuration = (v) => string_of_int(v);

let transitionProperty = (v) => v;

let transitionTimingFunction = (v) =>
  switch v {
  | Ease => "ease"
  | EaseIn => "ease-in"
  | EaseOut => "ease-out"
  | EaseInOut => "ease-in-out"
  | Linear => "linear"
  | StepStart => "step-start"
  | StepEnd => "step-end"
  | CubicBezier(x1, y1, x2, y2) => {j|cubic-bezier($x1, $y1, $x2, $y2)|j}
  | Steps(i, s) => "steps(" ++ (string_of_int(i) ++ (", " ++ (animationStepsToString(s) ++ ")")))
  | Frames(i) => {j|frames($i)|j}
  };

let transition = (~delay=0, ~duration=0, ~timingFunction=Ease, name) => {
  let func = timingFunctionToString(timingFunction);
  {j|$name $(duration)ms $func $(delay)ms|j}
};

/* TRANSFORM */
type transform = string;

let transform = (v) => v;

let transforms = (transforms) => join(" ", transforms);

let translate = (x, y) => {j|translate($x, $y)|j};

let translateX = (x) => {j|translateX($x)|j};

let translateY = (y) => {j|translateY($y)|j};

let translateZ = (z) => {j|translateZ($z)|j};

let translate3d = (x, y, z) => {j|translate($x $y, $z)|j};

let scale = (x, y) => {j|scale($x, $y)|j};

let scale3d = (x, y, z) => {j|scale3d($x, $y, $z)|j};

let scaleX = (x) => {j|scaleX($x)|j};

let scaleY = (y) => {j|scaleY($y)|j};

let scaleZ = (y) => {j|scaleZ($y)|j};

let rotate = (a) => {j|rotate($a)|j};

let rotateX = (a) => {j|rotateX($a)|j};

let rotateY = (a) => {j|rotateY($a)|j};

let rotateZ = (a) => {j|rotateZ($a)|j};

let skew = (ax, ay) => {j|skew($ax, $ay|j};

let skewX = (a) => {j|skewX($a|j};

let skewY = (a) => {j|skewY($a|j};

let perspective = (v) => v;

/* MISC */
type cursor =
  | Auto
  | Pointer
  | Custom(string);

let cursor = (v) =>
  switch v {
  | Auto => "auto"
  | Pointer => "pointer"
  | Custom(cur) => cur
  };