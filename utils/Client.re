let api = [%raw {|process.env.NEXT_PUBLIC_API_URL|}];
let token = [%raw {|process.env.NEXT_PUBLIC_API_TOKEN|}];

open ApolloClient;

let headers = () => {
  let token = token->Js.Option.getExn;

  {"Authorization": "bearer " ++ token};
}

let instance = Js.Option.map((. uri) => {
  let link = Link.HttpLink.make(~uri=_ => uri, ~headers=Obj.magic(headers()), ());

  make(
    ~cache=Cache.InMemoryCache.make(),
    ~connectToDevTools=true,
    ~defaultOptions=DefaultOptions.make(
      ~mutate=DefaultMutateOptions.make(~awaitRefetchQueries=true, ~errorPolicy=All, ()),
      ~query=DefaultQueryOptions.make(~fetchPolicy=NetworkOnly, ~errorPolicy=All, ()),
      ~watchQuery=DefaultWatchQueryOptions.make(~fetchPolicy=NetworkOnly, ~errorPolicy=All, ()),
      (),
    ),
    ~link,
    (),
  );
}, api)->Js.Option.getExn;
