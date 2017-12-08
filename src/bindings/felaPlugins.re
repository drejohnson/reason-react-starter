type t;

/* TODO fix typing for unit plugin options */
/* [@bs.obj]
   external unitpluginOptions : (~unit_: string=?, ~unitPerProperty: Js.t({..})=?, unit) => t =
     ""; */
[@bs.module "fela-plugin-extend"] external extend : unit => 'a = "default";

[@bs.module "fela-plugin-embedded"] external embedded : unit => 'a = "default";

[@bs.module "fela-plugin-prefixer"] external prefixer : unit => 'a = "default";

[@bs.module "fela-plugin-fallback-value"] external fallbackValue : unit => 'a = "default";

[@bs.module "fela-plugin-lvha"] external lvha : unit => 'a = "default";

[@bs.module "fela-plugin-unit"] external unit_ : unit => 'a = "default";

[@bs.module "fela-plugin-named-keys"] external namedKeys : Js.t({..}) => 'a = "default";