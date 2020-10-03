// let styles = ReactDOMRe.Style.make(~marginRight="10px", ());

[@react.component]
let make = () => {
  <div className="teste">
    <Next.Link href="/">
      <a> {ReasonReact.string("Home")} </a>
    </Next.Link>
    <Next.Link href="/about">
      <a> {ReasonReact.string("About")} </a>
    </Next.Link>
  </div>;
};

let default = make;
