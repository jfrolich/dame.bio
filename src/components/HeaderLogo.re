open BsReactNative;

let component = ReasonReact.statelessComponent("HeaderLogo");

let styles =
  StyleSheet.create(
    Style.{
      "background":
        style([
          width(Pct(100.)),
          padding(Pt(40.)),
          justifyContent(Center),
          alignItems(Center),
          overflow(Hidden),
        ]),
      "backgroundImageWrapper":
        style([position(Absolute), top(Pt(0.)), left(Pct(50.))]),
      "backgroundImage":
        style([
          left(Pct(-50.)),
          width(Pt(3599. /. 2.)),
          height(Pt(266. /. 2.)),
        ]),
      "logo": style([position(Relative), zIndex(1)]),
      "logoImage": style([zIndex(2)]),
    },
  );

let make = _children => {
  ...component,
  render: _self =>
    <View style=styles##background>
      <View style=styles##backgroundImageWrapper>
        <Image
          resizeMode=`contain
          style=styles##backgroundImage
          source={
                   `URI(
                     Image.(
                       imageURISource(
                         ~uri="/images/header-background.png",
                         (),
                       )
                     ),
                   )
                 }
        />
      </View>
      <TextLink style=styles##logo href="/">
        <View style=styles##logoImage>
          <SVGDameBioLogo width=350. height=140. fill="#67B44B" />
        </View>
      </TextLink>
    </View>,
};
