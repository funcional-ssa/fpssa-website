@react.component
let make = (~onClick, ~children) => {
  <button onClick>{children}</button>
}