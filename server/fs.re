[@bs.module "fs"] external readFile : (string, string, (Js.null(Js.Exn.t), unit) => unit) => unit =
  "";
/* let readFile = (path, unicode) => readFile(path, unicode) |> Async.from_js; */