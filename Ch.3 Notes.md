# Chapter 3 - Debugging C++ Programs

07/10/2025
## Ch. 3.1 - Syntax and Semantic Errors
- a **syntax error** occures when a statement does not use proper c++ grammer
- **semantic errors** occure when when the syntax is valid but the statement violates other rules


## Ch. 3.4 - Basic Debugging Tactics
- commenting out code
- can use 3rd party libs for debug that are not compiled in release mode
- have function print its name when it runs to see flow
  - use ```std::cerr``` instead of ```std::cout``` because cout can be buffered
  - don't indent the cerr statements
    - can have clang ignore it by doing
      ```c++
        // clang-format off
        std::cerr << "function() called\n";
        // clang-format on
        ```
- print values to see what values are being passed


## Ch. 3.5 - More Debugging Tactics
- manual debugging has downsides mainly that it's error prone adding/removing stuff
- can use conditional statements to debug
  ```c++
  #define ENABLE_BUG
  #ifdef ENABLE_DEBUG
  std::cerr << "function() called\n";
  #endif
  ```
  - can enable/disable debug mode by addeding/removing the ```#define ENABLE_DEBUG```
    - the define would go in a header file included in all files for a large program
      >[!CAUTION] causes clutter and typos can break the debug mode
- a **log** is a sequential record of time stamped events
  - logs help avoid clutter since the output is a separate file
  - ```std::clog``` basically is the same as ```std:cerr``` and you must pipe to file yourself
    - likely better off using a 3rd party lib for this (they use 'plog' library)

## Ch. 3.6 - Using an Integrated Debugger: Stepping
- 
