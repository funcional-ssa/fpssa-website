open Next;

module ProjectsQuery = [%graphql
  {|
  query {
    organization(login: "funcional-ssa") {
      repositories(first: 10) {
        nodes {
          name
          description
          id
          url
        }
      }
    }
  }
|}
];

type props = {
  projects:
    Belt.Result.t(
      array(ProjectsQuery.t_organization_repositories_nodes),
      string,
    ),
};

type params;

let default = (props: props) => {
  switch (props.projects) {
  | Ok(projs) =>
    <div>
      {projs
       ->Belt.Array.map(project => {
           let uri = project.url->Js.Json.decodeString->Belt.Option.getUnsafe;

           <div className="project" key={project.id}>
             <h2 className="project__name">
               <a href=uri> {project.name}->React.string </a>
             </h2>
             <p className="project__description">
               {project.description
                ->Belt.Option.getWithDefault({j|Sem descrição|j})
                ->React.string}
             </p>
           </div>;
         })
       ->React.array}
    </div>
  | Error(message) => <div> message->React.string </div>
  };
};

let getServerSideProps: GetServerProps.t(props, params) =
  _ctx => {
    Client.instance
    ->ApolloClient.query(~query=(module ProjectsQuery), ())
    ->Promise.Js.fromBsPromise
    ->Promise.Js.toResult
    ->Promise.map(projects => {
        let projects =
          switch (projects) {
          | Ok({
              data:
                Some({
                  organization: Some({repositories: {nodes: Some(repos)}}),
                }),
            }) =>
            let projects = repos->Belt.Array.keepMap(repo => {repo});
            Ok(projects);
          | _ => Belt.Result.Error("No repository found")
          };

        let props =
          GetServerProps.unsafelyRemoveUndefined({projects: projects});

        {"props": props};
      });
  };
