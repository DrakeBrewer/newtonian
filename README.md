# Newtonian
Newtonian is a physics simulator designed to funciton as it's own entity separate from any graphics rendering tool. This grants the ability to abandon a graphics rendering technology if we so choose. This can be accomplished through using CMake and its target system to build Qt components, Newtonian components, or both.

## Technology
Primary Language: [C++](https://cplusplus.com/reference/)<br>
Build System: [CMake](https://cmake.org/)<br>
Graphics Rendering: [Qt](https://www.qt.io/developers)<br>
Testing Framework: [GoogleTest](https://google.github.io/googletest/)<br>

## Conventions
Branches should be created in a `name/type/change` format i.e: `joe/feature/add-readme`. refer to conventional commits for branch type names.

Commit messages ideally follow the [Conventional Commits](https://www.conventionalcommits.org/en/v1.0.0/) guidelines. This is optional for commits within a branch but it would be ideal to hold this convention for PR titles.
<!-- TODO: determine snake- vs camel-case -->

## Setup
### macOs
``` sh
brew install cmake
```

### windows
<!-- TODO: -->

### linux
<!-- TODO: -->
