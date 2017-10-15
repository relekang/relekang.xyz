open Glamor;

open Data;

let component = ReasonReact.statelessComponent "Landing";

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
