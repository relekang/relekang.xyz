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
    links: [App "http://relekang.xyz", Code "https://github.com/relekang/relekang.xyz"],
    description: "A simple react-reason site with serverside rendering."
  }
];
