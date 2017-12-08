/* adapted from https://github.com/SentiaAnalytics/bs-css/blob/master/src/Css.re  */
type rule =
  | Property(string, string)
  | Selector(string, list(rule));

type color = string;

type cssunit = string;

type transform = string;

type colors = {. "primary": color, "accent": color, "black": color, "white": color, "gray": color};

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
  Property(
    "fontWeight",
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
    }
  );

/* colors */
type rgb = (int, int, int) => color;

type rgba = (int, int, int, float) => color;

type hex = string => color;

/* units */
type px = int => cssunit;

type pct = float => cssunit;

type rem = float => cssunit;

type em = float => cssunit;

type vh = float => cssunit;

type vw = float => cssunit;

type cm = float => cssunit;

type mm = float => cssunit;

type zero = cssunit;

type theme = {
  .
  "color": color,
  "fontSize": cssunit,
  "backgroundColor": color,
  "page": {. "backgroundColor": color},
  "header": {. "backgroundColor": color}
};