[@react.component]
let make = () => {
  <div>
    <h1 className="home__text">{"Home page!" -> React.string}</h1>
  </div>;
}

let default = make;