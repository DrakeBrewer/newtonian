# Newtonian
Newtonian is a physics simulator designed to use a graphics rendering tool (in this implementation Qt). This grants a level of modularity that makes it easy to potentially accomidate other rendering engines in the future. This can be accomplished through using CMake and its target system to build Qt components, Newtonian components, or both.

## Technology
Primary Language: [C++23](https://cplusplus.com/reference/)<br>
Build System: [CMake](https://cmake.org/) (Minimum version 3.31)<br>
Graphics Rendering: [Qt](https://www.qt.io/developers) (Version 6.8)<br>
Testing Framework: [GoogleTest](https://google.github.io/googletest/)<br>

## Conventions
Commit messages ideally follow the [Conventional Commits](https://www.conventionalcommits.org/en/v1.0.0/) guidelines. This is optional for commits within a branch but it would be ideal to hold this convention for PR titles to more easily parse commit history on the main branch.

Branches should be created in a `name/type/change` format i.e: `joe/feature/add-readme`. refer to conventional commits for branch type names.

## Setup
### macOs
Ensure that [Homebrew](https://brew.sh/) is installed.<br>
Within your terminal run:
``` sh
brew install cmake
```

### Windows
Navigate to the [CMake](https://cmake.org/download/) official download page.<br>
Download the Windows Installer file (the .msi file, or click [this](https://github.com/Kitware/CMake/releases/download/v3.31.4/cmake-3.31.4-windows-x86_64.msi) to download it).<br>
After downloading it, run the .msi file to begin installation (follow the installation Wizard).<br>
After installing CMake you can verify the installation on Command Prompt or PowerShell by running:
``` sh 
cmake --version
```
If installed correctly, it will output the installed version of CMake.

### Linux
Installing CMake with your package manager may result in an older version of the program. 
Instead, go to the [github repo](https://github.com/kitware/cmake/releases) to install the latest version in tar.gz format
Then extract from the command line using the following commands:

```bash
tar -xvzf cmake-<version>.tar.gz
cd cmake-<version>
./bootstrap
make
sudo make install
```

Then, verify the latest version using:

```bash
cmake --version
```

If the version output is not what you were expecting, you may need to configure your PATH. Example:
// in .bashrc
export PATH=/usr/local/bin:$PATH
Then, you must reload the configurations using:
source ~/.bashrc

## Build
From within the root directory of the project run:
```sh
cmake -B build
```
to generate a build system within the specified directory. Then, cd into your new build directory located at the root of your project and run:
```sh
cmake --build . --target <target>
```
to generate your CMake generated project binary tree. To run the program, simply cd into the directory with the build target located within the build directory that we generated earlier and run the generated executable.
>[!TIP]
>If you are using VSCode, you can follow [this](https://learn.microsoft.com/en-us/vcpkg/get_started/get-started-vscode?pivots=shell-powershell) tutorial to build your projects using VSCode's built in tooling.
<!-- TODO: Expand when we have a concrete build process that can be documented -->

## Use
<!-- TODO: -->
