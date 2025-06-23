# Ch. 1 - C++ Basics

06/17/25
## Ch. 1.1 - Statements and Structure of a Program
- A **function** is a collection of statements executed in order
- all C++ programs must have a main function
- camelCase with ()
- the **identifier** is the name of the function


06/19/25
## Ch. 1.3 - Objects and Variables
- **object** in C++ only refers to objects in memory or variables and NOT functions
- **definition** is a declaration of a variable
  - ie x = 1;


## Ch. 1.4 - Variable Assignment and Initialization
- different types of initialization all behave the same in C++17 and above
  - in older versions of C++ direct copy initialization is slower
  - ie int x = 1; and int x { 1 }; are the same
- can't list initialize and narrow
  - ie cant do int i = { 4.5 }; since the type doesnt match compiler will get angry
- list initialization {} is the most preferred
- an initialized object is called an **instance**
- *maybe_unused* before initializing variable to allow compiler to generate with unused variables
  - this is just lazy instead of taking out the unused variables


06/22/25
## Ch. 1.5 - iostream: cout, cin, and endl
- **std::cout** - character output
  - sends data to console
  - used with the **insertion operator <<**
  - this is a **buffered** command
    - does not execute immediately, instead is output when the buffer is **flushed**
    - writing data to buffer and flushing in batches is faster than unbuffered data transfer
- **std::endl** - end line
  - newline and flushes the buffer to output
    - this means it's slow to call it for every line
  - use **\n** instead and only use **std::endl** when you need new line and flush
    - works the same as in C
- **std::cin** - character input
  - input is added to end of the input buffer
  - then the **extraction operator >>** removes characters from the front of the input buffer
    - assigns them to a variable via copy-assignment
  - each line of input data is terminated by **\n** when the user hits return
    - the \n is not extracted when copy-assigned to a variable
- **extraction**
  - if prior extraction fails, then no further attempts will be made
  - if no characters could be extracted, variable is copy assigned to 0
  - leading whitespace is discarded
  - if input buffer is empty operator >> will wait for user input
  - the >> operator extracts as many **consecutive** characters until it finds \n or non valid character


