open Express;

open Data;

type glamorOutput = Js.t {. html : string, css : string};

external renderStatic : (unit => string) => glamorOutput = "" [@@bs.module "glamor/server"];

let template html css =>
  "<!DOCTYPE html><html><head>  <meta charset=\"UTF-8\">  <meta name=\"viewport\" content=\"width=device-width, initial-scale=1\">  <title>Rolf learns reasonml</title>  <style>    html, body { padding: 0; margin: 0; }    body { background: #f6f4f4; }   " ^
  css ^ "</style> </head><body>  <div id=\"root\">" ^ html ^ "</div></body></html>";

let renderPage element => {
  let output = renderStatic (fun () => ReactDOMServerRe.renderToString element);
  template output##html output##css
};

let app = express ();

App.useOnPath
  app
  path::"/"
  (Express.Static.make "dist" (Express.Static.defaultOptions ()) |> Express.Static.asMiddleware);

App.get app path::"/" @@
Middleware.from (
  fun req res _next =>
    switch (Request.baseUrl req) {
    | _ => Response.sendString res (renderPage <Landing />)
    }
);

let onListen port e =>
  switch e {
  | exception (Js.Exn.Error e) =>
    Js.log e;
    Node.Process.exit 1
  | _ => Js.log @@ "Listening at http://127.0.0.1:" ^ string_of_int port
  };

App.listen app onListen::(onListen 3000) ();
