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
      <Text
        _as="h2"
        style=(
          ReactDOMRe.Style.make(
            ~color="#db4d3f",
            ~backgroundColor="#eee",
            ~padding="20px 10px",
            ~margin="0",
            ()
          )
        )>
        (text(message))
      </Text>
    </View>
};