# Ch. 0 Notes


06/16/25
## Ch. 0 - Introduction
### Ch. 0.5 - Compiler, Linker, and Libraries
-  source code .cpp files are compiled into **object files**
  - marked with the '.o' suffix
- **Linker**
  - first ensures objects from the compiler are valid
  - second ensures all cross-file dependencies are resolved
  - third links libraries
  - finally linker outputs executable file


06/18/25
### Ch. 0.7 - Compiling
-**g++**
  - use the same way as **gcc**
    - ex: g++ -o filename filename.cpp

### Ch. 0.9 - Build Configuration
- **debug configuration** turns off all optimizations to make program easier to debug
  - add **-ggdb** for debug builds
- **release configuration** optimizes build for size and performance
  - add **-02 -DNDEBUG** for release builds

### Ch. 0.10 - Compiler Extensions
- enabled by default but do not meet c++ standard
- disable with the **-pedantic-errors** flag


### Ch. 0.11 - Compiler Warnings and Errors
- **diagnostic error** means the compilation is halted because the program is ill-formed
- **diagnostic warning** means the compiler did not halt and finished compiling
  - ie technically legal but suspicious
- increase warnings with *-Wall -Weffc++ -Wextra -Wconversion -Wsign-conversion*
- treat warnings as errors with *-Werror*

### Ch. 0.14 - Language Standards
- most common default is C++14
- select which version of C++ to compile with **-std=c++17** flag
- check which version it's compiling with with the printstandard.cpp example
>[!NOTE]
>This guide uses C++17


