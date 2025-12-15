# Ch.6 Notes - Operators

## Ch. 6.1 - Operator Precedence and Associativity
- generally follows order of operations (check table)
- can use parentheses to force order of operations just like in normal math
- they are evaluated generally left to right
  - but function inputs can evaluate left to right or right to left depending on compiler


## Ch. 6.2 - Arithmetic Operators
- the binary division operator will do floating point or integer division depending on the inputs
  - ie ```7 / 4 = 1``` while ```7.0 / 4 = 1.75```
  - integers can be static cast to floating point to force floating point division

## Ch. 6.2 - Remainder and Exponentiation
- to use exponents you must ```#include <cmath>``` and use the ```pow()``` function
  - this uses doubles so there may be rounding errors
    - to avoid rounding errors use your own function for integer exponentiation
      - keep in mind that it will almost certainly overflow the int type anyways lol


