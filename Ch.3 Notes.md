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
- **program state** is all the tracked information about where it is in execution
- a **debugger** is a tool that controls how a program executes and examine its state at a given point
- **stepping** allows you to execute the code statement by statement (stepping)
- **step into** command executes the enxt statement in the normal execution path and then pauses
  - if there is a function call it will jump to the top of the function being called
- **step over** will execute the entire function call and return after function execution
- **step out** executes all remaining code in the current function and stops when function returns
- **step back** is not really a thing so just restart the debugger


## Ch. 3.7 - Using an Integrated Debugger: Running and breakpoints
- **run to cursor** runs program until it reaches your cursor
- **continue** runs the program from that point forward until it finishes or hits a breakpoint
- **start** same as continue but starts from beginning of program
- **breakpoints** are special markers that tell the debugger to stop execution in debug mode
- **set next statement** change to a different point of execution
  - changes the point of execution but does not change the program's state


07/11/2025
## Ch. 3.8 - Using an Integrated Debugger: Watching Variables
- **watching a variable** is inspecting it as the program executes
- the **watch window** is a pane that displays selecter variables as the program is stepped through
- can set a breakpoint for watched variables to more easily track


## Ch. 3.9 - Using an Integrated Debugger: The Call Stack
- the **call stack** is a list of all functions called before current point of execution

## Ch. 3.10 - Finding Issues Before They Become Problems
- **refactoring** is changing the structure of the code without changing the function
  - the goal is to make the program less complex by increasing organizatoin and modularity
- **defensive programming* anticipates all the ways the software could be misused
- **unit testing** is used to test small units of source code for proper functionality
  - a **test function** is a dummy load to make sure a component is working
- **constraints** can be used to make sure proper data is being passed to the function
  - ie stop negative number from being passed when the func expects positive number
    - function immediately errors instead of continuing with bad inputs
      - ```assert``` and ```static_assert``` can be used to help with this
- **static analysis tools** aka **linters** check for semantic issues before compilation

