[@bs.send] external toString : string => string = "toString"; /* Hack for glamor returning an object */

type renderFunc =
  {
    .
    "_match": Js.Dict.t(string),
    "history": History.History.t,
    "location": History.History.Location.t
  } =>
  ReasonReact.reactElement;

let optionToBool = (optional) =>
  switch optional {
  | Some(_) => true
  | _ => false
  };

module Route = {
  [@bs.module "react-router-dom"] external route : ReasonReact.reactClass = "Route";
  let make =
      (
        ~component: option(('a => ReasonReact.reactElement))=?,
        ~exact: option(bool)=?,
        ~path: option(string)=?,
        ~render: option(renderFunc)=?,
        children
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass=route,
      ~props={
        "exact": Js.Boolean.to_js_boolean(optionToBool(exact)),
        "path": Js.Nullable.from_opt(path),
        "component": Js.Nullable.from_opt(component),
        "render": Js.Nullable.from_opt(render)
      },
      children
    );
};

module Router = {
  [@bs.module "react-router-dom"] external router : ReasonReact.reactClass = "Router";
  let make = (children) =>
    ReasonReact.wrapJsForReason(~reactClass=router, ~props=Js.Obj.empty(), children);
};

module BrowserRouter = {
  [@bs.module "react-router-dom"] external browserRouter : ReasonReact.reactClass =
    "BrowserRouter";
  let make = (children) =>
    ReasonReact.wrapJsForReason(~reactClass=browserRouter, ~props=Js.Obj.empty(), children);
};

module ServerRouter = {
  [@bs.module "react-router-dom"] external staticRouter : ReasonReact.reactClass = "StaticRouter";
  let make = (~context: Js.Json.t, ~location: Js.Json.t, children) =>
    ReasonReact.wrapJsForReason(
      ~reactClass=staticRouter,
      ~props={"context": context, "location": location},
      children
    );
};

module Switch = {
  [@bs.module "react-router-dom"] external _switch : ReasonReact.reactClass = "Switch";
  let make = (children) =>
    ReasonReact.wrapJsForReason(~reactClass=_switch, ~props=Js.Obj.empty(), children);
};

module Link = {
  [@bs.module "react-router-dom"] external link : ReasonReact.reactClass = "Link";
  let make = (~_to, children) =>
    ReasonReact.wrapJsForReason(~reactClass=link, ~props={"to": _to}, children);
};

module NavLink = {
  [@bs.module "react-router-dom"] external navLink : ReasonReact.reactClass = "NavLink";
  let make =
      (
        ~_to: string,
        ~innerRef: option((Js.null(Dom.element) => unit))=?,
        ~className: option(string)=?,
        ~activeClassName: option(string)=?,
        ~onClick: option((ReactEventRe.Mouse.t => unit))=?,
        children
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass=navLink,
      ~props={
        "to": _to,
        "innerRef": Js.Nullable.from_opt(innerRef),
        "className":
          switch className {
          | Some(name) => toString(name)
          | None => ""
          },
        "activeClassName":
          switch activeClassName {
          | Some(name) => toString(name)
          | None => ""
          },
        "onClick": Js.Nullable.from_opt(onClick)
      },
      children
    );
};

module Redirect = {
  [@bs.module "react-router-dom"] external redirect : ReasonReact.reactClass = "Redirect";
  let make = (~_to: string, ~from: option(string)=?, children) =>
    ReasonReact.wrapJsForReason(
      ~reactClass=redirect,
      ~props={"to": _to, "from": Js.Nullable.from_opt(from)},
      children
    );
};