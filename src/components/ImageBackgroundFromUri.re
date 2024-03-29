open BsReactNative;

[@react.component]
let make = (~uri, ~resizeMode=?, ~style=?, ~children, ()) => {
  <ImageBackground
    ?resizeMode
    ?style
    source={`URI(Image.(imageURISource(~uri, ())))}
    // SSR workaround https://github.com/necolas/react-native-web/issues/543
    defaultSource={`URI(Image.(defaultURISource(~uri, ())))}>
    children
  </ImageBackground>;
};
