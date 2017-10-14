open Glamor;

let component = ReasonReact.statelessComponent "Landing";

type link =
  | Code string
  | App string;

type project = {
  name: string,
  links: list link,
  description: string
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
    links: [],
    description: "A simple react-reason site with serverside rendering."
  }
];

let renderLink link =>
  switch link {
  | App url => <Link key=url url title="[app]" />
  | Code url => <Link key=url url title="[code]" />
  };

let renderProject project =>
  <li key=project.name>
    <strong className=(css [fontSize "1.4em"])>
      (ReasonReact.stringToElement project.name)
      <span className=(css [fontWeight "100", fontSize "0.8em"])>
        (ReasonReact.arrayToElement (Array.of_list (List.map renderLink project.links)))
      </span>
    </strong>
    <p> (ReasonReact.stringToElement project.description) </p>
  </li>;

let make _children => {
  ...component,
  render: fun _ =>
    <div
      className=(css [fontSize "20px", width "600px", margin "4rem auto", fontFamily "Georgia"])>
      <h1> (ReasonReact.stringToElement "Rolf tries to learn reasonml") </h1>
      <p>
        (
          ReasonReact.stringToElement "I am trying to learn reasonml, and on the I build a bunch of small projects. These is just a list of them, some are open-source some are not."
        )
      </p>
      <ul className=(css [listStyleType "none", margin "0", padding "0"])>
        (ReasonReact.arrayToElement (Array.of_list (List.map renderProject projects)))
      </ul>
    </div>
};
