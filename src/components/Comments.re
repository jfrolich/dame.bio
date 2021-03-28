open Belt;
open ReactNative;

let styles =
  Style.(
    StyleSheet.create({
      "comments": style(),
      "noComment":
        style(
          ~textAlign=`center,
          ~fontSize=18.,
          ~color="#d6d5d2",
          ~fontWeight=`_600,
          (),
        ),
    })
  );

[@react.component]
let make =
    (
      ~databaseId,
      ~commentCounts,
      ~comments: option(WPGraphQL.PostDetailFragment.t_comments),
    ) => {
  <>
    /* @todo native fix */
    <a name="comments" />
    <View>
      <TextSubtitle>
        (
          switch (commentCounts->Option.getWithDefault(0)) {
          | 0 => "Commentaires"
          | 1 => "1 Commentaire"
          | count => count->string_of_int ++ " Commentaires"
          }
        )
        ->React.string
      </TextSubtitle>
    </View>
    <Spacer size=S />
    <View style=styles##comments>
      {switch (
         comments->Option.flatMap(ts => ts.nodes)->Option.getWithDefault([||])
       ) {
       | [||] =>
         <>
           <Spacer size=L />
           <Text style=styles##noComment>
             {j|Aucun commentaire pour l'instant. Laissez le vôtre !|j}
             ->React.string
           </Text>
           <Spacer size=L />
         </>
       | coms =>
         coms
         ->Array.mapWithIndex((index, comment) =>
             comment->Option.mapWithDefault(React.null, comment =>
               comment.parent->Option.isNone
                 ? <CommentWithReplyAndChildren
                     key={string_of_int(
                       comment.commentId->Option.getWithDefault(index),
                     )}
                     comment
                     parentCommentId={
                       comment.commentId->Option.getWithDefault(0)
                     }
                     databaseId
                     comments
                   />
                 : React.null
             )
           )
         ->React.array
       }}
      <CommentSeparator />
      <Spacer />
    </View>
    <CommentForm databaseId parentCommentId=0 />
  </>;
};
