# Chapter 5 - Constants and Strings

07/14/25
## Ch. 5.1 - Constant Variables (Named Constants)
- a **constant** is a value that may not be changed during a programs execution
- a **named constant** is a constant value associated with an identifier
- a **literal constant** is a constant value not associated with an identifier
- three ways to define **named constants**
- 
  1. constant variables
    - a variable who's value cannot be changed after initialization
    - declared like ```const double gravity { 9.8 }```
    - must be initialized when defined
    - use intercapped names with a 'k' at the start eg ```kEarthGravity```
    - use const whenever possible to reduce complexity
  2. object-like macros with substitution text
    - the preprocessor notes since they are consts
    - dont use them since they have file scope
  3. enumerated constants



  10/13/25
  ## Ch. 5.2 - Literals
- Values inserted directly into code are **Literals**
- **literal constants** are literals whose value cannot be redefined
- literals have types like normal variables ie ```int``` or ```float```
- literals can use suffix to change type 
```c++
float f { 4.1 }; // warning: 4.1 is a double literal, not a float literal
float f { 4.1f }; // use 'f' suffix so the literal is a float and matches variable type of float
double d { 4.1 }; // change variable to type double so it matches the literal type double
```
- string literals
  - implicit ```/0``` **null terminator** to mark end of string
  - guaranteed to exist for entire program - created at start
  - ```std::string``` and ```std::stringview``` both create temp objs - NOT like C strings above
- **magic numbers** need to be changed later or have unclear meanings
  - for example what do these numbers do? We don't know.
  ```c++
    const int maxStudentsPerSchool{ numClassrooms * 30 };
    setMax(30);
  ```
>[!DANGER] never use magic numbers, instead use symbolic constants

  ```c++
   const int maxStudentsPerClass { 30 };
   const int totalStudents{ numClassrooms * maxStudentsPerClass }; // now obvious what this 30 means
 e
   const int maxNameLength{ 30 };
   setMax(maxNameLength); // now obvious this 30 is used in a different context
  ```



10/13/2025
## Ch. 5.4 - The as-if Rule and Compile-time Optimization
- a **Profiler** can see how long certain branches of the program take to run
- the **as-if** rule means a compiler can optimize in any ways as long as it does not change the observabe behavior
- a compiler can do work at **compile time** rather than run time to optimize
  - **constant folding** is a compile time evaluation where the compiler replaces fixed operands with their result
    - ```std::cout << 3 + 4 << '\n';``` gets optimized to ```std::cout << 7 << '\n';```
  - **constant propagation** is a compile time optimization that replaces constant variables with their value
  - **dead code elimination** is an optimization that removes unused code
  - optimization at compile time vs run time has several different effects


10/29/2025
## Ch. 5.5 - Constant Expressions
- ```constexpr``` variables require an initializer that can be evaluated at compile-time
- compile time programming
  - lets us write more secure and performant programs
  - basically anything that makes use of constant expressions

11/11/2025
## Ch. 5.6 - Constexpr Variables
- ```constexpr``` variable is always a compile-time constant
  - will get compile error if it's not constant
  - also works with variables of non integer types
- Any constant variable whose initializer is a constant expression should be declared as constexpr
- Any constant variable whose initializer is not a constant expression should be declared as const

11/21/2025
## Ch. 5.7 - Intro to std::string
- ```std::string``` is not a fundamental type but a class type
- ```#include <string>``` header to allow use
- in string form numbers are treated as text not integers
  - cannot use with math operators etc
- can store strings of any length (via dynamic memory allocation)
- ```std::getline``` requires ```std::cin``` and then your variable
  - ```std::getline(std::cin >> std::ws, name);```
    - this gets a line from the string ```name``` and gives it to ```std:ws```
- ```std::ws```
  - tells ```std:cin``` to ignore any whitespace (ws)
- ```stringName.length()``` member function will output the length of the string in characters (ie 'steve' would output 5)
- ```std::string::length()``` returns the unsigned integer value of type ```size_t```
  - should be static cast into an int to avoid problems ```int length { static_cast<int>(name.length()) };```
- do not pass std::string by value, as it makes an expensive copy
- it's okay to return a std::string when:
  - it resolves to a local variable
  - if it has already been returned by value from another function caller
  - if it's temporary as part of a return statement

11/24/25
## Ch. 5.8 - Introduction to std::string_view
- ```std::string_view``` is faster than copying the string entirely into memory only to later destroy it
- unlike fundamental types initializing and copying a ```std::string``` is slow
- instead use ```std::string_view``` (only for c++17 or higher)
  - provides read only access to an existing string
    - read only as in it cannot be modified
  - must call ```<string_view>``` header
  - can be initialized with a string literal, a ```std::string``` or another ```std::string_view```
- for example:
```c++
#include <iostream>
#include <string_view> // C++17

// str provides read-only access to whatever argument is passed in
void printSV(std::string_view str) // now a std::string_view
{
    std::cout << str << '\n';
}

int main()
{
    std::string_view s{ "Hello, world!" }; // now a std::string_view
    printSV(s);

    return 0;
}```
- the c++ compiler wont implicitly convert ```std::string_view``` into ```std::string```
- assigning a ```std::string_view``` to view a normal string doesn't modify the original string at all - it just views it
```c++
#include <iostream>
#include <string>
#include <string_view>

int main()
{
    std::string name { "Alex" };
    std::string_view sv { name }; // sv is now viewing name
    std::cout << sv << '\n'; // prints Alex

    sv = "John"; // sv is now viewing "John" (does not change name)
    std::cout << sv << '\n'; // prints John

    std::cout << name << '\n'; // prints Alex

    return 0;
}
```
- unlike ```std::string``` , string view does support constexpr



## Ch. 5.9 - std::string_view Part 2
- An initialized object has no control over what happens to the initialization value after initialization is finished
  - ```std::string_view``` is dependent on its initializer
    - a destroyed string_view is sometimes called a **dangling viewer**
  - but ```std::string``` creates its own object so it's not dependent on the initializer
- string view is best used as a function parameter
```c++
#include <iostream>
#include <string>
#include <string_view>

void printSV(std::string_view str) // now a std::string_view, creates a view of the argument
{
    std::cout << str << '\n';
}

int main()
{
    printSV("Hello, world!"); // call with C-style string literal

    std::string s2{ "Hello, world!" };
    printSV(s2); // call with std::string

    std::string_view s3 { s2 };
    printSV(s3); // call with std::string_view

    return 0;
}
```
- the return of a function is temporary so you can't use ```std::string_view``` on it since it wont copy
  - a function can still return a string_view tho
- memberfunctions ```remove_prefix()``` and ```remove_suffix()``` to remove characters on the left or right of the string
  - these only modify the view and not the string itself
    - ```str.remove_suffix(1)```
  - view can be reset by reassigning the source again

