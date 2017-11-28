type t;

[@bs.obj] external unit_config : (~unit_: string=?, ~unitPerProperty: Js.t({..})=?, unit) => t =
  "";

[@bs.module "fela-plugin-extend"] external extend : t = "default";

[@bs.module "fela-plugin-embedded"] external embedded : t = "default";

[@bs.module "fela-plugin-prefixer"] external prefixer : t = "default";

[@bs.module "fela-plugin-fallback-value"] external fallbackValue : t = "default";

[@bs.module "fela-plugin-lvha"] external lvha : t = "default";

[@bs.module "fela-plugin-unit"] external unit_ : t => 'a = "default";

[@bs.module "fela-plugin-named-keys"] external namedKeys : Js.t({..}) => 'a = "default";

let unitConfig = unit_config(~unit_="rem", ());

let extendPlugin = extend;

let embeddedPlugin = embedded;

let prefixerPlugin = prefixer;

let fallbackValue = fallbackValue;

let lvha = lvha;

let unitPlugin = unit_(unitConfig);

let namedKeysPlugin =
  namedKeys({
    "xxl": "@media (min-width: 100em)",
    "xl": "@media (min-width: 80)",
    "lg": "@media (min-width: 64em)",
    "md": "@media (min-width: 48em)",
    "sm": "@media (min-width: 36em)",
    "supportsFlex": "@supports (display: flex)",
    "supportsGrid": "@supports (display: grid)"
  });