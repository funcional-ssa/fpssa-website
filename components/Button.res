module Button = %styled.button(`
  color: white;
  background-color: black;
  height: 20px;
`);

@react.component
let make = (~onClick, ~children) => {
  <Button onClick>{children}</Button>
}