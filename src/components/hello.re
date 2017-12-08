let text = ReasonReact.stringToElement;

let component = ReasonReact.statelessComponent("Hello");

let make = (~message, _children) => {
  ...component,
  render: (_self) =>
    <WithTheme>
      (
        (theme) =>
          <Text _as="h2" fontSize=theme##fontSize color=theme##color> (text(message)) </Text>
      )
    </WithTheme>
};