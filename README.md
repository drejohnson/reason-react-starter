# ReasonReact Starter

> A starter for building universal web apps with ReasonReact.

## Features

* [x] [ReasonReact](https://reasonml.github.io/reason-react/)
* [x] SSR - Server side rendering
* [x] [Webpack](https://webpack.js.org/)
* [x] HMR - Hot Module Reloading
* [x] [PWA - Progressive Web Applications](https://developers.google.com/web/progressive-web-apps/)
* [x] [React Router v4](https://reacttraining.com/react-router/api) bindings
* [x] [React Fela](http://fela.js.org/) bindings ([bs-react-fela](https://github.com/astrada/bs-react-fela)) plus custom bindings that add [server rendered styles](http://fela.js.org/docs/advanced/ServerRendering.html)

## Quick start

- Use install dependencies: `yarn`
- For dev mode with hmr run `yarn dev` or `npm run dev`, open browser, the app should be running at: http://localhost:8080. *(If you get errors in terminal run `bsb -make-world`)*
- To build run: `yarn build` or `npm run build`
- To build and run use: `yarn build` or `npm run build` followed by `yarn start` or `npm start`

**TODO**
* [ ] Better HMR
* [ ] Optimized Webpack builds
* [ ] Graphql client - [Reason-Apollo](https://github.com/Gregoirevda/reason-apollo) or [ReGql](https://github.com/kennetpostigo/regql) until official [Apollo Client and React Apollo binding](https://github.com/apollographql/react-apollo/blob/master/ROADMAP.md#reason) are released
* [ ] Code splitting?