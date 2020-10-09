// Generated by ReScript, PLEASE EDIT WITH CARE

import * as React from "react";
import * as Emotion from "@ahrefs/bs-emotion/src/Emotion.js";

var styles = Emotion.css(undefined, {
      hd: Emotion.color(Emotion.Css.Color.white),
      tl: {
        hd: Emotion.backgroundColor(Emotion.Css.Color.black),
        tl: {
          hd: Emotion.height(Emotion.px(20)),
          tl: /* [] */0
        }
      }
    });

function make(props) {
  var stylesObject = {
    className: styles
  };
  var newProps = Object.assign(stylesObject, props);
  var chil = props.children;
  return React.createElement("button", newProps, [chil !== undefined ? chil : null]);
}

var Button = {
  styles: styles,
  make: make
};

function Button$1(Props) {
  var onClick = Props.onClick;
  var children = Props.children;
  return React.createElement(make, {
              children: children,
              onClick: onClick
            });
}

var make$1 = Button$1;

export {
  Button ,
  make$1 as make,
  
}
/* styles Not a pure module */
