# Chapter 5 - Constants and Strings

07/14/25
## Ch. 5.1 - Constant Variables (Named Constants)
- a **constant** is a value that may not be changed during a programs execution
- a **named constant** is a constant value associated with an identifier
- a **literal constant** is a constant value not associated with an identifier
- three ways to define **named constants**
  1. constant variables
    - a variable who's value cannot be changed after initialization
    - declared like ```const double gravity { 9.8 }```
    - must be initialized when defined
    - use intercapped names with a 'k' at the start eg ```kEarthGravity```
    - use const whenever possible to reduce complexity
  2. object-like macros with substitution text
  3. enumerated constants

