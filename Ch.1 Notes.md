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
