open BsReactNative;

let component = ReasonReact.statelessComponent("Sidebar");

let styles =
  StyleSheet.create(
    Style.{
      "sidebar":
        style([
          flex(1.),
          flexBasis(Pt(350.)),
          alignItems(Center),
          paddingHorizontal(Pt(20.)),
        ]),
      "block": style([padding(Pt(20.))]),
      "blockTitle":
        style([
          fontSize(Float(24.)),
          marginBottom(Pt(12.)),
          color(String("#DE6D88")),
        ]),
      "icons": style([flexDirection(Row), justifyContent(Center)]),
      "icon": style([padding(Pt(4.))]),
      "iconWrapper": style([zIndex(1), lineHeight(24.), padding(Pt(6.))]),
      "iconBackground": style([paddingTop(Pt(4.)), paddingRight(Pt(4.))]),
    },
  );

let make = children => {
  ...component,
  render: _self =>
    <View style=styles##sidebar>
      <Spacer size=M />
      <AuthorAvatar />
      <Spacer size=M />
      <View style=styles##block>
        <Text style=styles##blockTitle>
          {ReasonReact.string({j|Bienvenue|j})}
        </Text>
        <Bio />
      </View>
      <Spacer />
      <SocialIcons
        wrapperStyle=styles##icons
        iconStyle=styles##icon
        iconSize=24.
        iconWrapperFunc={(~children) =>
          <ImageBackgroundFromUri
            resizeMode=`contain
            style=styles##iconBackground
            uri="/images/pink/circle-bg-lg.png">
            <Text style=styles##iconWrapper> ...children </Text>
          </ImageBackgroundFromUri>
        }
      />
      <Spacer size=L />
      <DonationInvite />
      <Spacer size=L />
      <View> ...children </View>
    </View>,
};
