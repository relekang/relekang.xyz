type link =
  | Code string
  | App string;

type project = {
  name: string,
  links: list link,
  description: string
};

let json_of_link link =>
  switch link {
  | App url => Json.Encode.(object_ [("type", string "app"), ("url", string url)])
  | Code url => Json.Encode.(object_ [("type", string "code"), ("url", string url)])
  };

let json_of_project (project: project) => {
  let links = Array.of_list (List.map json_of_link project.links);
  Json.Encode.(
    object_ [
      ("name", string project.name),
      ("description", string project.description),
      ("links", array links)
    ]
  )
};

let projects = [
  {
    name: "caretaker",
    links: [Code "https://github.com/relekang/caretaker"],
    description: "A tiny script written in reason that will send you nice notifications to take care of you."
  },
  {
    name: "wo",
    links: [App "https://wo.relekang.xyz"],
    description: "A tiny app for a 6 minute strength program."
  },
  {
    name: "2048",
    links: [App "https://2048.relekang.xyz"],
    description: "A implementation of the 2048 game."
  },
  {
    name: "relekang.xyz",
    links: [App "http://relekang.xyz", Code "https://github.com/relekang/relekang.xyz"],
    description: "A simple react-reason site with serverside rendering."
  }
];
