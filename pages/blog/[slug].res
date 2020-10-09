open Next

type params = {slug: string}

type postData = {title: string}

type props = {
  data: postData,
  content: string,
  slug: string,
}

let default = (props: props) => {
  let {data, content} = props

  <React.Fragment>
    <h1> {data.title->React.string} </h1>
    <ReactMarkdown source={content} />
  </React.Fragment>
}

let getStaticProps: GetStaticProps.t<props, params> = ctx => {
  let {slug} = ctx.params

  let contentPromise = %raw(`import('../../posts/' + slug + '.md')`)

  contentPromise
  ->Promise.map(content => GrayMatter.parse(content["default"]))
  ->Promise.map(body => {
    let props = {
      data: body.data,
      content: body.content,
      slug: slug,
    }

    {
      "props": props,
    }
  })
}

let getStaticPaths: GetStaticPaths.t<params> = () => {
  open GetStaticPaths
  open Webpack

  let paths =
    Require.make("../../posts", ~useSubdirectories=true, ~regExp=%re("/\.md$/"))
    ->Require.keys
    ->Belt.Array.map(path => {
      let slug = Slug.get(path)

      {
        params: {
          slug: slug,
        },
      }
    })

  let response = {paths: paths, fallback: false}

  Promise.resolved(response)
}
