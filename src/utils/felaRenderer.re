let rendererConfig =
  Fela.rendererConfig(
    ~plugins=[|
      FelaPlugins.extend(),
      FelaPlugins.embedded(),
      FelaPlugins.prefixer(),
      FelaPlugins.fallbackValue(),
      FelaPlugins.lvha(),
      FelaPlugins.namedKeys({
        "xxl": "@media (min-width: 100em)",
        "xl": "@media (min-width: 80)",
        "lg": "@media (min-width: 64em)",
        "md": "@media (min-width: 48em)",
        "sm": "@media (min-width: 36em)",
        "supportsFlex": "@supports (display: flex)",
        "supportsGrid": "@supports (display: grid)"
      })
    |],
    ~selectorPrefix="bs_react_fela_",
    ()
  );

let renderer = Fela.createRenderer(rendererConfig);