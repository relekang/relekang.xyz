open Jest;

open ExpectJs;

describe
  "<Landing />"
  (
    fun _ =>
      test
        "render matches snapshot"
        (
          fun _ => {
            let component = ReactShallowRenderer.renderWithRenderer <Landing />;
            expect component |> toMatchSnapshot
          }
        )
  );
