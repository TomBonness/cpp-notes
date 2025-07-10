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
- **unreferenced functions** are functions that have parameters that are not used
  - compiler will warn
  - an **unnamed parameter** is where the type is defined but it has no name
    - *fuction(int){}* will work without an error
      - google style guide says to comment what it does like function(int /*count*/) {};


07/04/2025
## Ch. 2.5 - Introduction to Local Scope
- **Local variables** are defined inside the body of a function
  - function parameters are also considered to be local variables
- local variables are destroyed in the opposite order they are instantiated
  - at the end of the curley brackets in which it was definted
- an objects **lifetime** is the time between it's creation and destruction
- **scope** is where an identifier can be seen and used
  - compile time property, not in scope will cause compilation error
- **local scope** or **block scope**
  - usable from point of definitoin to end of curly brackets it's declared in
- variables should be defined as close to their first use as reasonable
- a **temporary object** (aka **anonymous object**) is used to hold a variable this is only used
  or needed for a short period of time
  - for example when a function ends but its caller still needs to hold the info to do something
  - temporary objects have no scope and are solely created by the compiler
  - temporary objects are always destroyed at the end of the expression in which they were created


07/06/2025
## Ch. 2.7 - Forward Declarations and Definitions
- a **forward declaration** tells the compiler about a function identifier before it is defined
  - **function declaration statement** (aka function prototype) is used as the forward declaration
    - consists of the return types, name, and parameter types
      - ie *int add(int x, int y);* before the main function
- most often used for when functions are defined in different files
- a **declaration** tells the compiler about the existance of a function
  - a **definition** is a declaration that implements the identifier
    - all definitions are delcarations, but not all definitions are declarations
- **One Definition Rule (ODR)**
  - within a file, each function can only have one definition inside its scope
    - compiler error
  - within a program, each function can only have one definiton inside its scope
    - linker error
  - types, templates, inline functions, and inline vars can have dup definitions in different files
    - undefined behavior


## Ch. 2.8 - Programs with Multiple Code Files
- must use forward declarations for calls to functions in other files
- order of compilation should not be relevant


## Ch. 2.9 - Naming Collisions and Introduction to Name Spaces
- **naming collision** occures when two identical identifiers are introduced in the same program in a 
  way that either the compiler or linker cannot tell them apart
- a **scope region** is an area of code where all declared identifiers are considered distinct
  from names declared in other scopes
- a **namespace** allows for the declaration of functions inside of its scape to avoid collisions
  - executable statements are not allowed inside namespaces (ie x=5;)
- the **global namespace** is everything that isnt declared inside inside a class, function, or namespace
  - implicitly defined namespace called global namespace or global scope
- **scope resolution operator** is the :: (ie std::cout)
  - ie the cout that is declared in namespace std
  - when the identifier includes a namespace prefix it's called a **qualified name**
  - the **namespace prefix** is the std in std::cout
- a **using directive** statement can also be used instead of a namespace prefix 
  - ie *using namespace std;* you could then just call it like *cout << "text";*
  - this should always be avoided
 
07/08/2025
## Ch. 2.10 - Introduction to the Preprocessor
- the preprocessor processes code before its sent to compiler
- **preprocessor directives** start with # and end with newline and tell preprocessor to perform tasks
- the preprocessor replaces #include <foo> with the contents of foo
- a **macro** is a rule that defines how input text is converted into replacement output text
  - **function-like macros** - act like a function and are generally considered unsafe
  - **object-like macros** - define a single identifier
    - generally avoided for better options mostly used in legacy code
    - #define IDENTIFIER substitution_text
  - macro names a typically uppercase and separated by underscores
- **conditional compilation** specifies whether a program will or will not compile
  - #ifdef #ifndef #endif
  - #if0 with #endif is used to comment out code from compiling
- directives are resolved file to file top to bottom before compilation
  - only in scope in the file they are resolved
    - file scope, cannot be in a function's scope


07/09/2025
## Ch. 2.11 - Header Files
- **header files** end in .h and allow you to have forward declarations in one place
- Consists of two main parts:
  - a **header guard**
  - the content in the header file (generall forward declarations)
-  often paired with a corresponding .cpp file with the same name
- when the preprocessor reads #include "file.h" it inserts the file contents at that point
- avoid putting function or variable definitions in header files (violates one definition rule ODR)
- including header files can help catch errors
  - ie declaration in header has different return type than definition in .cpp file will throw error
- do not #include any .cpp files
  - can cause big list of errors and there is no reason to do so
  - if project wont compile unless .cpp is #included, file is likely not being compiled in makefile
- angled brackets <> tell preprocessor will only search included directories
- quotes "" tell preprocessor to search in current local directory first, then included dirs
- if you wrote it use "" if not use <>
- can include relative path like #include "../desktop/folder/file.h"
- **transitive includes** happen when one #included file also #includes another file
  - try to avoid relying on this and #include other files explicitly
- order of #inclusion should generally not matter but
  1. paired header file
  2. other headers from same project
  3. 3rd party library headers
  4. standard library headers
- always include header guards

## Ch. 2.12 - Header Guards
