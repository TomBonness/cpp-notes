# Chapter 4 - Fundamental Data Types

07/11/2025
## Ch. 4.1 - Introduction to Fundamental Data Types
- a **binary digit** or **bit** is the smallest unit of memory
  - holds a value of 1 or 0
- a **memory address** is an organized sequence of units 
  - each memory address holds 1 byte of data (8 bits)
- the **type** tells the compiler how to interperate the memory byte meaningfully
- an **integral** means 'like an integer'
  - **integral types** in C++ are **bool**
  - stored in memory as an integer, but only inetegers output as integers
- an **integer** is a number with no decimal or fractional part, includes +/-/0
  - **standard integer types** in C++ are **short**, **int**, **long**, and **long long**
- the ```_t``` suffix means type ie ```std::nullptr_t```


## Ch. 4.2 - Void
- **void** means no type and is therefore an incomplete type
- an **incomplete type** is a type that has been declared but not defined
  - incomplete types cannot be instantiated
- void is most commonly used in functions that do not return any values


07/12/2025
## Ch. 4.3 - Object Size and the SizeOf Operator
- an object of n bits can hold 2^n unique values
- a byte is 8 bits so 2^8 = 256 different values, 2 bytes can hold 2^16 = 65536
- C++ standard outlines that
  - ```char``` is 8 bits
  - ```short``` is 16 bits
  - ```int``` is 16 bits
  - ```long``` is 32 bits
  - ```long long``` is 64 bits
  - ```char``` and ```char8_t``` are exactly 1 byte
- the ```sizeof()``` operator is a unary operator that takes a type or variable and returns size in bytes
- the ```sizeof()``` operator does not include dynamically allocated memory used by an object
- Smaller types are not always faster as CPUs are optimized for certain size operators


## Ch. 4.4 - Signed Integers
- a **sign** is an attribute of an integer that allows it to be negative, positive, or zero
  - ie ```-3```
- by default integers in C++ are signed, and its sign is stored as part of the value
- preferred way to define the four types of signed integers
```cpp
    short s;      // prefer "short" instead of "short int"
    int i;
    long l;       // prefer "long" instead of "long int"
    long long ll; // prefer "long long" instead of "long long int"
```
- can also include the optional ```signed``` keyword before definition
- the **range** is the set of specific values a data type can hold (2^n)
  - range is determined by it's size in bits and whther it is signed or not
    - ie an 8 bit signed int can store any value between -128 to 127
    - range calculated with -(2^n-1) to (2^n-1)-1
- an **overflow** is when data is not within the range of representable values for a type
- an **integer overflow** happens when an operation attempts to create a value outside the possible range
  - for signed integers it will cause undefined behavior
- **integer division** always produces an integer result - integers cannot hold fractional values
  - fractional parts of the quotient are lost


## Ch. 4.5 - Unsigned Integers, and Why to Avoid Them
- **unsigned integers** are integers that only hold non-negative whole numbers
- can be defined with:
  ```cpp
    unsigned short us;
    unsigned int ui;
    unsigned long ul;
    unsigned long long ull;
  ```
- a 1-byte unsigned integer has a range of 0 to 255
- unsigned int range calculated by 0 to (2^n)-1
- if an unsigned int is out of range it is divided by one greater than the largest number, only remaineder is kept
  - ie for 280 in a 1-byte unsigned int -> 280 / 256 -> 1 remainder 24 -> only 24 is stored after the overflow
    - any number larger than the largest number representable wraps around (aka modulo wrapping)
  >[!WARNING] If an operation has one signed and one unsigned int, the signed int will be converted to unsigned
- Google recommends avoiding unsigned ints
  - exception:
    - bit manipulation
    - when well defined wrap around behavior is required
    - array indexing
    - embedded systems with processor or memory limited context


## Ch. 4.6 - Fixed-Width Integers and size_t
- must ```#include <cstdint>``` to use the ```_t```
- only the minimum size of integer variables is guaranteed
  - int is min 16 bits but it's typically 32-bits on modern architectures
- C++11 introduced **fixed-width integers** that are guaranteed to be the same size on any architecture
  - these should always be used when you need a guaranteed range
- ```std::int8_t``` and ```std::uint8_t``` behave the same as a signed and unsigned char
  - the 16 bit versions dont have this issue
- downsides
  - fixed width integers are not guaranteed to be defined on all architectures
  - fixed width integers may be slower than a wider type on certain architectures
- **fast types** provide the fastest signed/unsigned integer type with a width of at least x bits
  - ```std::int_fast_32_t``` will result in teh fastest signed int type that's at least 32 bits
  - fast types can lead to memory wastage
- **least types** provide the smallest signed/unsigned integer type with a width of at least x bits
  - ```std::uint_least32_t``` will result in the smallest unsigned integer type that's 32 bits
- best practice is to avoid fast and least integral types because they may behave differently on different architectures
>[!TIP] better to be correct than fast, and better to fail at compile time than runtime
- the ```sizeof()``` operator returns a value type of ```std::size_t```
  - guaranteed to be unsigned and at least 16 bits, but is mostly equivalent to address width of the application
  - which is an alias of an implementation defined unsigned integral type
    - it's actually a typedef
    - best header to include for this is  ```<cstddef>```


## Ch. 4.7 - An Introduction to Scientific Notation
- 
