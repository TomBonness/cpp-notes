# Ch.2 - Introduction to Functions


06/26/2025
## Ch. 2.1 - Introduction to Functions
- a **function** is a reusable series of statements designed to do a paticular task
  - **user defined functions** are created by the user and not part of a library
  - a **function call** interrupts the current function and calls another
  - the **function header** is the first line that tells the compiler the function exists
    - *returnType functionName()*
  - the **function body** is everything inside the brackets { function body }
  - a function must be defined BEFORE it is called
  - c++ does not support **nested functions**
    - cannot define a function inside of another function, but you can call it


## Ch. 2.2 - Function Return Values
- **return type** the type defined before the functionname that determines the type it will return
- **return value** is what is returned back to the caller
  - return from main is also known as a **status code** or an **exit code**
    - exit code '0' means the program ran successfully
- requirements for main()
  - must return an **int**
  - cannot explicitly make a function call to main()
  - generally (not always) main should be the last function in the file
- a value returning function must return a value or else it's undefined behavior
- main() will implicitly return '0'
- functions can only return a single value


06/27/2026
## Ch. 2.3 - Void Functions
- a **void function** is a function that doesn't return anything
  - no return statement needed
- returning a value in a void function will cause a compiler error


## Ch. 2.4 - Introduction to Function Parameters and Arguments
- a **function parameter** is a variable used in the header of the function
  - they are initialized with a value provided by the caller of the function
- an **argument** is a value that is passed from the called to the function
- when a function is called all of the parameters are created as variables
  - the value of each argument is copied into the matching parameter
    - this is called **pass by value**
      - **value parameters** are functions that use pass by value 
