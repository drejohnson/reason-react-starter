let text = ReasonReact.stringToElement;

let component = ReasonReact.statelessComponent("Hello");

let make = (~message, _children) => {
  ...component,
  render: (_self) =>
    <View>
      <Image
        source="https://fakeimg.pl/1600x350/?retina=true"
        resizeMode=Cover
        width=(PCT(100))
        height=(PX(350))
        backgroundColor="#ccc"
      />
      <Text _as="h2"> (text(message)) </Text>
    </View>
};