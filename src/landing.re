let component = ReasonReact.statelessComponent "landing";

let make _children => {
  ...component,
  render: fun _ => <div> (ReasonReact.stringToElement "hi there") </div>
};
