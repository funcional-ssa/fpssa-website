module Require = {
  type t;

  [@val]
  [@scope("require")]
  external make: (
    string,
    ~useSubdirectories: bool,
    ~regExp: Js.Re.t
  ) => t = "context";

  [@send]
  external keys: t => array(string) = "keys"
}
