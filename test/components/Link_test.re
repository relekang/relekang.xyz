open Jest;

open ExpectJs;

describe
  "<Link />"
  (
    fun _ =>
      test
        "render matches snapshot"
        (
          fun _ =>
            <Link url="http://relekang.xyz" title="o/" /> |> ReactTestRenderer.create |> expect |> toMatchSnapshot
        )
  );
