@react.component
let make = () => {
  <nav className="teste">
    <Next.Link href="/">
      <a> {ReasonReact.string("Home")} </a>
    </Next.Link>
    <Next.Link href="/about">
      <a> {ReasonReact.string("About")} </a>
    </Next.Link>
  </nav>;
};

let default = make;
