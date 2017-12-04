type t;

[@bs.module "react-ga"] external initialize : string => unit = "";

[@bs.module "react-ga"] external set : Js.t({..}) => unit = "";

[@bs.module "react-ga"] external pageview : string => unit = "";