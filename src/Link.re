open Glamor;

let component = ReasonReact.statelessComponent "Landing";

let make ::url ::title _children => {
  ...component,
  render: fun _ =>
    <a href=url className=(css [color "#db4d3f", margin "0.5rem"])>
      (ReasonReact.stringToElement title)
    </a>
};
