// Generated by ReScript, PLEASE EDIT WITH CARE

import * as Slug from "../../utils/Slug.js";
import * as React from "react";
import * as $$Promise from "reason-promise/src/js/promise.js";
import * as Belt_Array from "bs-platform/lib/es6/belt_Array.js";
import GrayMatter from "gray-matter";
import ReactMarkdown from "react-markdown";

function $$default(props) {
  return React.createElement(React.Fragment, {
              children: null
            }, React.createElement("h1", undefined, props.data.title), React.createElement(ReactMarkdown, {
                  source: props.content
                }));
}

function getStaticProps(ctx) {
  var match = ctx.params;
  var slug = match.slug;
  var contentPromise = (import('../../posts/' + slug + '.md'));
  return $$Promise.map($$Promise.map(contentPromise, (function (content) {
                    return GrayMatter(content.default);
                  })), (function (body) {
                return {
                        props: {
                          data: body.data,
                          content: body.content,
                          slug: slug
                        }
                      };
              }));
}

function getStaticPaths(param) {
  var paths = Belt_Array.map(require.context("../../posts", true, /\.md$/).keys(), (function (path) {
          var slug = Slug.get(path);
          return {
                  params: {
                    slug: slug
                  }
                };
        }));
  return $$Promise.resolved({
              paths: paths,
              fallback: false
            });
}

export {
  $$default ,
  $$default as default,
  getStaticProps ,
  getStaticPaths ,
  
}
/* react Not a pure module */