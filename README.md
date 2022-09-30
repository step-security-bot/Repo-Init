<div align="center" width="50">
<img src=scripts/data/branding/logo.png>

![GitHub top language](https://img.shields.io/github/languages/top/egecetin/Repo-Init?style=plastic)
![GitHub](https://img.shields.io/github/license/egecetin/Repo-Init?style=plastic)
![GitHub Workflow Status](https://img.shields.io/github/workflow/status/egecetin/Repo-Init/Build%20and%20test?style=plastic)
![Codecov](https://img.shields.io/codecov/c/github/egecetin/Repo-Init?style=plastic&token=G65MG0J07F)
</div>

## Project
CMake template to create new C++ applications with basic codes/interfaces are already defined.

It provides the following features
  - Logging
    - Spdlog with rotating file, syslog and coloured stdout outputs
    - Sentry for automatic forwarding of logs to a HTTP server
    - Prometheus client for track internal metrics like error counts, performance of functions
  - User interactivity
    - Telnet
    - ZeroMQ

## Contents

- [Project](#project)
- [Contents](#contents)
- [CMake](#cmake)
- [Scripts](#scripts)
- [Dependencies](#dependencies)
- [Targets](#targets)
- [Developer comments](#developer-comments)

## CMake

- AddressSanitizer      : Defines address sanitizer
- AutoBuildNumber       : Auto increments the build number
- CodeCoverage          : Detects and enables gcovr
- Colorize              : Color commands for message outputs
- CompilerFlags         : Defines compiler flags for GCC and Intel Compiler for compile types
- CompilerOptions       : Enables/Disables compiler warnings
- CustomFindSubversion  : Modified version of FindSubversion.cmake to ignore errors
- Doxy                  : Find doxygen package and prepare doc environment
- GitVersion            : Get SHA1 hash of current commit
- GraphViz              : Find graphviz and dot executable to create dependency graph
- LinkTimeOptimization  : Enables Link Time Optimization
- MemorySanitizer       : Defines memory sanitizer
- PostBuild             : Post build action to prepare makeself package after CPack while calculating checksums for all binaries
- Sanitizers            : Controls sanitizer targets
- SvnVersion            : Get revision number of current commit
- ThreadSanitizer       : Defines thread sanitizer
- UndefinedBehaviourSan : Defines undefined behaviour sanitizer

## Scripts

All scripts should be executed from top level directory

- create_installer      : Creates installer package using makeself
- firstName             : Script to change placeholder name
- generateKey           : Generates public/private key pairs
- init                  : Script used initialization of this repo
- ldd-copy-dependencies : Script to copy dynamic dependencies of a binary
- makeself              : [Makeself](https://github.com/megastep/makeself) self-extractable archive creator
- passwordless-ssh      : Script to enable passwordless ssh from Windows hosts
- prepare-release       : Prepares a release package
- system-setup          : Installs desired packages on RedHat based systems

## Dependencies

 - [CppZMQ](https://github.com/zeromq/cppzmq.git)
 - [MemPlumber](https://github.com/seladb/MemPlumber.git)
 - [Prometheus-cpp](https://github.com/jupp0r/prometheus-cpp.git)
 - [RapidJSON](https://github.com/Tencent/rapidjson.git)
 - [Spdlog](https://github.com/gabime/spdlog.git)
 - [Sentry](https://github.com/getsentry/sentry-native.git)
 - [TelnetServLib](https://github.com/lukemalcolm/TelnetServLib.git) (Modified and embedded to source directory)
 - [ZeroMQ](https://github.com/zeromq/libzmq.git)

## Targets

 - all              : Prepares all targets
 - coverage         : Prepares coverage report
 - docs             : Prepares documentation
 - dependency-graph : Prepares graphviz visualization of dependencies
 - package          : Prepares RPM and makeself packages
 - test             : Prepares gtest target

## Developer comments

 - Update branding information after cloning. The folder should include three icons/logos and a css file. Look the branding.css or RHEL branding folder for recommended image sizes
   - logo.png
   - favicon.ico
   - apple-touch-icon.png
   - branding.css
