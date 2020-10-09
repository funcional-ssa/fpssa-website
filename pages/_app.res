%%raw(`import '../assets/styles.css';`)

type pageComponent = React.component<Js.t<{.}>>;
type pageProps = Js.t<{.}>;

type props = {
  .
  "Component": pageComponent,
  "pageProps": pageProps
};

@obj
external makeProps:
  (~component: pageComponent, ~pageProps: pageProps, ~key: string=?, unit) =>
    props = "";

let make = (props: props) => {
  let component = props["Component"];
  let pageProps = props["pageProps"];
  let content = React.createElement(component, pageProps);

  content;
}

let default = make;