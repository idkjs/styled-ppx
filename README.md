# styled-ppx

**styled-ppx** is the ppx that enables *CSS-in-Reason*.

Allows you to create **React Components** with style definitions with CSS that don't rely on a specific DSL and keeps type-safety with great error messages. Build on top of [bs-emotion](https://github.com/ahrefs/bs-emotion), it allows you to style apps quickly, performant and as you always done it.

> ⚠️ **Early stage** This ppx is in a early stage. Meaning that it doesn't support full functionality as [emotion](https://emotion.sh) or [styled-components](https://styled-components.com/).
> But you can safely use it, as it woudn't break any existing code in further releases.
> In case you want to know more, take a look at the [ROADMAP](./ROADMAP.md), or feel free to chat on Discord: @davesnx#5641

The biggest missing features is: **Dynamic components not supported** [Here is the issue](https://github.com/davesnx/styled-ppx/issues/12)

## Motivation
I love CSS and I'm coming from the JavaScript world, writing React code with styled-components. I found it, one of the best combos to write scalable frontend applications and wasn't a reality in ReasonML/OCaml.

As well, saw a few people asking for it ([a](https://reasonml.chat/t/idiomatic-way-to-bind-to-styled-components/886) [f](https://reasonml.chat/t/styled-components-possible/554)[e](https://reasonml.chat/t/styling-solutions-reasonreact-as-of-aug-18/958)[w](https://reasonml.chat/t/options-and-best-practices-for-styling-in-reasonreact/261) [t](https://twitter.com/lyovson/status/1233397294311100417)[i](https://discord.gg/byjdYFH)[m](https://discord.gg/byjdYFH)[e](https://discord.gg/byjdYFH)[s](https://discord.gg/byjdYFH)). So I took the time to create it with help from [@jchavarri](https://github.com/jchavarri) 🙌.

## Usage
**`styled-ppx`** implements a ppx that transforms `[%styled]` extensions into [bs-emotion](https://github.com/ahrefs/bs-emotion) calls, that does all the CSS-in-JS that provides [emotion](https://emotion.sh).

This is how you write components in ReasonML with this ppx:
```reason
module StyledComponent = [%styled.div {|
  display: flex;
  justify-content: center;
  align-items: center;

  height: 100vh;
  width: 100vw;
|}];

ReactDOMRe.renderToElementWithId(
  <StyledComponent>
    {React.string("- Middle -")}
  </StyledComponent>,
  "app"
);
```

This is how you write components in OCaml with this ppx:
```ocaml
module StyledComponent = [%styled.div
  {|
    display: flex;
    justify-content: center;
    align-items: center;

    height: 100vh;
    width: 100vw;
  |}
]
```

## Installation

This package depends on bs-emotion, make sure you follow the instalation as well: https://github.com/ahrefs/bs-emotion#installation

### With `esy` on native projects

```bash
esy add davesnx/styled-ppx
```

### With `npm` or `yarn` on BuckleScript projects

```bash
yarn global add @davesnx/styled-ppx @ahrefs/bs-emotion
# Or
npm -g install @davesnx/styled-ppx @ahrefs/bs-emotion
```

And add the PPX in your `bsconfig.json` file:

```json
{
  "bs-dependencies": [
    "reason-react",
    "@ahrefs/bs-emotion"
  ],
  "ppx-flags": ["@davesnx/styled-ppx/styled-ppx"]
}
```

However, if you want to use `esy` in BuckleScript:
Create an `esy.json` file with the content:

```json
{
  "dependencies": {
    "styled-ppx": "*",
    "ocaml": "~4.6.1000"
  },
  "resolutions": {
    "styled-ppx": "davesnx/styled-ppx"
  }
}
```

And add the PPX in your `bsconfig.json` file:

```json
{
  "ppx-flags": ["esy x styled-ppx.exe"]
}
```

If you want to try out of the box a project, just visit https://github.com/davesnx/try-styled-ppx and follow the instalation process there.

## Thanks to
Thanks to [Javier Chávarri](https://github.com/jchavarri), for helping me understand all the world of OCaml and his knowledge about ppx's. It has been a great experience.
Inspired by [@astrada](https://github.com/astrada/) `bs-css-ppx` and their CSS Parser.
Thanks to [ahrefs/bs-emotion](https://github.com/ahrefs/bs-emotion) and [emotion](https://github.com/emotion-js/emotion).

## Contributing
We would love your help improving styled-ppx, there's still a lot to do.
The ROADMAP is well organized, take a look in [here](./ROADMAP.md).

Next big feature would be: support all CSS Properties and dynamic props.

Instead of using a string to define a "styled" component, provide a function that will be executed to generate styles on run-time, based on component's props.
```reason
/* This is not implemented yet! */
module StyledWithProps = [%styled (~color) => {| color: $color |}];

type size =
  | Small
  | Big
  | Full;

/* And you would be able to create components with Pattern Matching, or compose functions! */
module StyledWithPatternMatcing = [%styled
  (~size) => switch (size) {
    | Small => "width: 33%"
    | Big => "width: 80%"
    | Full => "width: 100%"
  }
];
```

### Developing
You need `esy`, you can install the latest version from [npm](https://npmjs.com):

```bash
yarn global add esy@latest
# Or
npm install -g esy@latest
```

> NOTE: Make sure `esy --version` returns at least `0.5.8` for this project to build.

Then run the `esy` command from this project root to install and build depenencies.

```bash
esy
```

Now you can run your editor within the environment (which also includes merlin):

```bash
esy $EDITOR
esy vim
```

After you make some changes to source code, you can re-run project's build
again with the same simple `esy` command and run the native tests with

```bash
esy test
```

This project uses [Dune](https://dune.build/) as a build system, if you add a dependency in your `package.json` file, don't forget to add it to your `dune` and `dune-project` files too.

### Running Tests

You can test compiled executable (runs `scripts.tests` specified in `package.json`):

This will run the native unit test.
```bash
esy test
```
> This tests only ensures that the output looks exactly as a snapshot, so their mission are to ensure the ppx transforms to a valid OCaml syntax.

If you want to run Bucklescript's integration test instead, you can do:
```bash
esy
cd test/bucklescript
yarn install
yarn build
yarn test
```
> This tests are more like an end to end tests, that ensures that emotion have the correct methods for each CSS property.

---
### Resources

[An introduction to OCaml PPX ecosystem](https://tarides.com/blog/2019-05-09-an-introduction-to-ocaml-ppx-ecosystem)

[yusufyildirim/ppx-examples](https://github.com/yusufyildirim/ppx-examples)

##### Happy reasoning!

<!--

### Creating release builds

To release prebuilt binaries to all platforms, we use Github Actions to build each binary individually.

The binaries are then uploaded to a Github Release and NPM automatically.

To trigger the Release workflow, you need to push a git tag to the repository.
We provide a script that will bump the version of the project, tag the commit and push it to Github:

```bash
./scripts/release.sh
```

The script uses `npm version` to bump the project, so you can use the same argument.
For instance, to release a new patch version, you can run:

```bash
./scripts/release.sh patch
```
 -->
