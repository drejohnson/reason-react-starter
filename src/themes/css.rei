/*
   ** adapted from the excellent bs-css repo: https://github.com/SentiaAnalytics/bs-css/blob/master/src/Css.rei
   ** Removed the Glamor parts since I just want the css typings for typed styles
 */
type css = string;

type color;

type cssunit;

type keyframes;

type transform;

type angle;

let rad: float => angle;

let deg: float => angle;

let turn: float => angle;

/* let important: rule => rule; */
/* units */
let px: int => cssunit;

let pct: float => cssunit;

let rem: float => cssunit;

let em: float => cssunit;

let vh: float => cssunit;

let vw: float => cssunit;

let cm: float => cssunit;

let mm: float => cssunit;

let fr: float => cssunit;

let zero: cssunit;

/* color */
let rgb: (int, int, int) => color;

let rgba: (int, int, int, float) => color;

let hex: string => color;

let white: color;

let black: color;

/* CSS RULES */
/* let unsafe: (string, string) => rule; */
type visibility =
  | Visible
  | Hidden;

let visibility: visibility => string;

let opacity: float => string;

/* BACKGROUND */
let backgroundImage: string => string;

type backgroundAttachment =
  | Scroll
  | Fixed
  | Local
  | Initial;

let backgroundAttachment: backgroundAttachment => string;

let backgroundColor: color => string;

type backgroundSize =
  | Cover
  | Contain
  | Width(cssunit)
  | Height(cssunit)
  | Custom(cssunit, cssunit);

let backgroundSize: backgroundSize => string;

type backgroundPosition =
  | Top
  | Bottom
  | Left
  | Right
  | Center;

let backgroundPosition: backgroundPosition => string;

type backgroundRepeat =
  | RepeatX
  | RepeatY
  | Repeat
  | Space
  | Round
  | NoRepeat;

let backgroundRepeat: backgroundRepeat => string;

type background =
  | None
  | Color(color)
  | Image(string);

let background: background => string;

/* TEXT */
let color: color => string;

let fontFamily: string => string;

let fontSize: cssunit => string;

type fontStyle =
  | Normal
  | Italic
  | Oblique;

let fontStyle: fontStyle => string;

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

let fontWeight: fontWeight => string;

type textDecoration =
  | None
  | Underline(color)
  | UnderlineWavy(color);

let textDecoration: textDecoration => string;

type textAlign =
  | Auto
  | Left
  | Right
  | Center
  | Justify;

let textAlign: textAlign => string;

let textIndent: cssunit => string;

let textShadow: (cssunit, cssunit, color) => string;

type textTransform =
  | None
  | Uppercase
  | Lowercase
  | Capitalize
  | FullWidth;

let textTransform: textTransform => string;

let letterSpacing: cssunit => string;

let lineHeight: cssunit => string;

/* BORDER */
type borderStyle =
  | None
  | Hidden
  | Solid
  | Dotted
  | Dashed
  | Double;

let border: (cssunit, borderStyle, color) => string;

let borderTop: (cssunit, borderStyle, color) => string;

let borderBottom: (cssunit, borderStyle, color) => string;

let borderLeft: (cssunit, borderStyle, color) => string;

let borderRight: (cssunit, borderStyle, color) => string;

let borderWidth: cssunit => string;

let borderTopWidth: cssunit => string;

let borderBottomWidth: cssunit => string;

let borderLeftWidth: cssunit => string;

let borderRightWidth: cssunit => string;

let borderStyle: borderStyle => string;

let borderTopStyle: borderStyle => string;

let borderBottomStyle: borderStyle => string;

let borderLeftStyle: borderStyle => string;

let borderRightStyle: borderStyle => string;

let borderColor: color => string;

let borderTopColor: color => string;

let borderBottomColor: color => string;

let borderLeftColor: color => string;

let borderRightColor: color => string;

let borderRadius: cssunit => string;

let borderTopLeftRadius: cssunit => string;

let borderTopRightRadius: cssunit => string;

let borderBottomLeftRadius: cssunit => string;

let borderBottomRightRadius: cssunit => string;

/* LAYOUT */
let width: cssunit => string;

let minWidth: cssunit => string;

let maxWidth: cssunit => string;

let height: cssunit => string;

let minHeight: cssunit => string;

let maxHeight: cssunit => string;

let left: cssunit => string;

let right: cssunit => string;

let top: cssunit => string;

let bottom: cssunit => string;

let margin: cssunit => string;

let marginLeft: cssunit => string;

let marginRight: cssunit => string;

let marginTop: cssunit => string;

let marginBottom: cssunit => string;

let padding: cssunit => string;

let paddingLeft: cssunit => string;

let paddingRight: cssunit => string;

let paddingTop: cssunit => string;

let paddingBottom: cssunit => string;

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

let display: display => string;

type position =
  | Static
  | Relative
  | Absolute
  | Fixed
  | Sticky;

let position: position => string;

type boxSizing =
  | BorderBox
  | ContentBox;

let boxSizing: boxSizing => string;

type overflow =
  | Visible
  | Hidden
  | Scroll
  | Auto;

let overflow: overflow => string;

let overflowX: overflow => string;

let overflowY: overflow => string;

let zIndex: int => string;

/* FLEXBOX */
let flex: int => string;

type flexDirection =
  | Row
  | RowReverse
  | Column
  | ColumnReverse;

let flexDirection: flexDirection => string;

let flexBasis: int => string;

let flexFlow: int => string;

let flexGrow: int => string;

let flexShrink: int => string;

type flexWrap =
  | Wrap
  | NoWrap;

let flexWrap: flexWrap => string;

type justify =
  | FlexStart
  | FlexEnd
  | Center
  | Stretch
  | SpaceAround
  | SpaceBetween;

let alignContent: justify => string;

type alignment =
  | FlexStart
  | FlexEnd
  | Center
  | Stretch
  | Baseline;

let alignItems: alignment => string;

let alignSelf: alignment => string;

let justifyContent: justify => string;

let order: int => string;

/* CSS GRID */
type grid;

let gridTemplateRows: string => string;

let gridTemplateColumns: string => string;

let gridAutoRows: string => string;

let gridAutoColumns: string => string;

let gridAutoFlow: string => string;

let gridRowStart: string => string;

let gridColumnStart: string => string;

let gridRowEnd: string => string;

let gridColumnEnd: string => string;

let gridRow: int => int;

let gridColumn: string => string;

let gridRowGap: cssunit => string;

let gridColumnGap: cssunit => string;

/* SHADOW */
type shadow;

let shadow: (~x: int=?, ~y: int=?, ~blur: int=?, ~spread: int=?, color) => shadow;

let boxShadow: shadow => string;

let boxShadows: list(shadow) => string;

/* ANIMATION */
let animationDuration: int => string;

let animationDelay: int => string;

type animationDirection =
  | Normal
  | Reverse
  | Alternate
  | AlternateReverse;

let animationDirection: animationDirection => string;

type animationFillMode =
  | None
  | Forwards
  | Backwards
  | Both;

let animationFillMode: animationFillMode => string;

type animationIterationCount =
  | Infinite
  | Iterate(int);

let animationIterationCount: animationIterationCount => string;

let animationName: keyframes => string;

type animationPlayState =
  | Paused
  | Running;

let animationPlayState: animationPlayState => string;

type animationSteps =
  | Start
  | End;

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

let animationTimingFunction: timingFunction => string;

/* TRANSITION */
let transitionDelay: int => string;

let transitionDuration: int => string;

let transitionTimingFunction: timingFunction => string;

let transitionProperty: string => string;

let transition:
  (~delay: int=?, ~duration: int=?, ~timingFunction: timingFunction=?, string) => string;

/* TRANSFORM */
let transform: transform => string;

let transforms: list(transform) => string;

let translate: (cssunit, cssunit) => transform;

let translateX: cssunit => transform;

let translateY: cssunit => transform;

let scale: (float, float) => transform;

let scaleX: float => transform;

let scaleY: float => transform;

let rotate: angle => transform;

let skew: (angle, angle) => transform;

let skewX: angle => transform;

let skewY: angle => transform;

let translate3d: (cssunit, cssunit, cssunit) => transform;

let translateZ: cssunit => transform;

let scale3d: (float, float, float) => transform;

let scaleZ: float => transform;

let rotateX: angle => transform;

let rotateY: angle => transform;

let rotateZ: angle => transform;

let perspective: cssunit => string;

/* MISC */
type cursor =
  | Auto
  | Pointer
  | Custom(string);

let cursor: cursor => string;