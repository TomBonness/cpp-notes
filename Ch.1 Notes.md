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


06/23/25
## Ch. 1.6 - Uninitialized Variables and Undefined Behavior
- **Uninitialized variables**
  - given memory address but it points to garbage
  - C/C++ does not automatically initialize variables
  - initialization can be omitted for small performance gain
- **implementation-defined behavior**
  - an **implementation** is the compiler and associated standard library it comes with
  - sometimes the implementation can define how an aspect of the language will behave
    - ex **sizeof(int)** could produce different answers
- **unspecified behavior**
  - behavior is left up to the implementation but it is not documented


## Ch. 1.7 - Keywords and Naming Identifiers
- **keywords** are a set of 92 words reserved by c++ with special meanings
  - **special identifiers** are also reserved, but unlike keywords they are only reserved in special cases
- an **identifier** is the name of a variable (ie int identifier or identifier())
  - cannot be a keyword
  - can only be composed of letters, numbers, and underscores (no symbols or white space)
  - must start with lowercase letter or underscore
  - case sensitive (iDentifier =/= identifier)
- convention
  - variable names should begin with a lowercase letter
    - if it's a single word, it should be entirely lowercase (including functions)
  - function names that start with capital letters are usually user defined types
  - camelCase
  - avoid starting a variable name with an underscore
  - make the identifier name equally as specific as it is specific and accessible
    - ie in the body of a short function variable can have a shorter name


06/24/25
## Ch. 1.8 - Whitespace and Basic Formatting
- **whitespace** is characters used for formatting purposes (spaces, tabs, newline)
- compiler doesnt care how much whitespace is used (ie int     x; still works lol)
- newlines are not allowed in quoted text
  - quoted text separated by nothing but whitespace will be concatenated
- whitespace is otherwise generally ignored by the comiler so no hard rules
- "whitespace independent language"
- tabs should be set equivalent to 4 spaces generally
- typically 80 characters max for lines; if longer split into multiple lines
- if a line is split on an operator (+, -, etc) it should go at the start of the new line
- pick a style guide!


## Ch. 1.9 - Introduction to Literals and Operators
- **Literals** (aka constants)
  - a fixed value that is inserted directly into the code (ie *std::out << 5;* // 5 is the literal)
  - value cannot be changed unlike a variable
- **Operators**
  - +, -, %, new, delete, throw, etc
  - **Unary** - operator that acts on one operand. (ie '-' flips positive 5 to -5)
  - **Binary** - operator that acts on two operands. (ie '+' in 1 + 2)
  - **Ternary** - operator that acts on three operands. (the conditional operator)
  - **Nullnary** - operator that acts on zero operands. (the throw operator)
  - operators generally execute in order of PEMDAS
  - most operators produce return values
  - an operator that produces an effect beyond a return value has a **side effect**
    - ie *std::cout << 5* has the side effect of printing 5 to the console

## Ch. 1.10 - Intro to Expressions
- an **expression** is a sequence of non empty variables, literals, operators, and function calls
  that calculate a value
- **evaluation** is the process of executing an expression
  - expressoins are always evaluated as part of a statement
- the **result** is the output after evaluation (aka return value)
  - this can be a value, object, function, or nothing
- *type identifier { expression };*
- expressoins cannot be executed by themselves - they must exist as part of a statement
- **expression statement** - a statement that is an expression followed by a semicolon
- **subexpression** is an expression used as an operator
  - ie x = 4 + 5; the subexpressions are 'x' and '4 + 5'
- **full expressoin** - an expression that is not a subexpression
  - ie x = 4 + 5 //the whole thing is the full expression
- **compound expression** - an expression that that contains two or more uses of operators
  - x = 4 + 5 is compound because it uses operator= and operator+

## Ch. 1.11 - Developing Your First Program
- check example program :D
