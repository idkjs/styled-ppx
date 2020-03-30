module App = [%styled.div {|
  display: flex;
  justify-content: center;
  align-items: center;
  flex-direction: column;

  height: 100vh;
  width: 100vw;

  font-size: 30px;
|}];

/* Define keyframes 
.css-ankwuq-animated {
    -webkit-animation-name: animation-1leqys6;
    animation-name: animation-1leqys6;
    -webkit-animation-duration: 300ms;
    animation-duration: 300ms;
    -webkit-animation-iteration-count: 7;
    animation-iteration-count: 7;
}

*/
// let bounce = Css.(keyframes([
//   (0, [ transform( scale(0.1, 0.1) ),  opacity(0.0) ]),
//   (60, [ transform( scale(1.2, 1.2) ),  opacity(1.0) ]),
//   (100, [ transform( scale(1.0,1.0) ), opacity(1.0) ])
// ]));

// let animated = [%styled
//   [
//     /* Use generated animation name */
//     animationName(bounce),
//     animationDuration(`ms(300)),
//     animationIterationCount(`i(7))
//   ]
// ];
module Component = [%styled {| margin-left: 10px |}];
module ComponentWithPadding = [%styled {| padding: 5px |}];
module Opacity = [%styled "opacity: 0.33"];
module ComponentInline = [%styled "color: #454545"];
// open Css.;
// module ComponentWithHover = [%styled {| padding: 32px;
//         background-color: #454545;
//         font-size: 24px;
//         border-radius: 4px;
//         hover([borderRadius(`pct(50.)), important(cursor(`grab))])
//         |}];
module Link = [%styled.a {| color: #454545 |}];

ReactDOMRe.renderToElementWithId(
  <App onClick={Js.log}>
    <Component>
      {React.string("- styled-ppx -")}
    </Component>
    <Link href="http://sancho.dev">
      {React.string("sancho.dev")}
    </Link>
    <ComponentWithPadding>
    {React.string("ComponentWithPadding")}
    </ComponentWithPadding>
    <Opacity>
    {React.string("Opacity")}
    </Opacity>
    <ComponentInline />
    // <ComponentWithHover>
    // {React.string("Hover to change color")}
    // </ComponentWithHover>
  </App>,
  "app"
);
