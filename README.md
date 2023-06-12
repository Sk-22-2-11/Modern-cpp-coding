
# Modern C++: coding practices with new features

The coding sources are based on [Udemy modern c++20 masterclass](https://www.udemy.com/course/the-modern-cpp-20-masterclass/).

## 1. The development of modern c++

Modern C++ refers to the evolution of the C++ programming language, starting from the release of C++11 and continuing with subsequent versions, including C++14, C++17, C++20, and the upcoming C++23. These updates have brought numerous new features and improvements to the language, enhancing its expressiveness, efficiency, and safety. 

Let's review the major features introduced in each version:

### 1.1 c++11

Auto Type Inference: The auto keyword allows the compiler to deduce the type of a variable from its initializer automatically. This reduces verbosity and improves code readability.

Lambda Expressions: Lambdas enable the creation of anonymous functions within the code, promoting a more functional programming style.

Range-based for Loop: This loop simplifies iteration over collections by automatically handling the bounds and providing a convenient syntax.

Smart Pointers: std::shared_ptr, std::unique_ptr, and std::weak_ptr facilitate automatic memory management, reducing the risk of memory leaks and improving code safety.

Move Semantics: Move semantics enable the efficient transfer of resources (e.g., ownership of dynamically allocated memory) without unnecessary copying.

### 1.2 c++14

Binary Literals and Digit Separators: Binary literals (0b) and digit separators (e.g., 1'000'000) improve the readability of numeric constants.

Return Type Deduction: Functions can now use auto as the return type, allowing the compiler to deduce it based on the return statement.

Variable Templates: Templates can now be used to define variables, enabling the creation of generic constants.

Generic Lambdas: Lambdas can be defined using the auto parameter type, making them more flexible and versatile.

### 1.3 c++17

Structured Bindings: Structured bindings allow unpacking the members of a tuple-like object or data structure into individual variables.

if with Initialization: Initialization of variables within an if statement condition is now possible, improving code readability.

std::optional: The std::optional type provides a safer alternative to nullable pointers by wrapping an optional value that can be empty.

std::variant: std::variant introduces a type-safe union, allowing a variable to hold one of several alternative types.

### 1.4 c++20

Concepts: Concepts enable the specification of requirements on template arguments, improving error messages and reducing template-related issues.

Ranges: Ranges provide a new abstraction for working with sequences, offering a more expressive and composable alternative to iterators.

Coroutines: Coroutines allow the creation of functions that can be suspended and resumed, facilitating asynchronous programming.

Modules: Modules provide a new way of organizing and managing code, improving build times and enhancing separation of interface and implementation.

### 1.5 c++23(upcoming)

Contracts: Contracts introduce a mechanism for expressing preconditions, postconditions, and assertions in code, improving code correctness and robustness.

std::source_location: std::source_location provides access to information about the source location (e.g., file, line) where a function is called.

Improved Modules: C++23 aims to refine and expand the module system introduced in C++20, addressing feedback and further improving performance and usability.

Overall, the evolution of C++ has brought many powerful features that enhance productivity, safety, and performance. 

The new versions have made the language more expressive, reduced boilerplate code, and introduced modern programming paradigms, making C++ a versatile and relevant language

## 2. Memorandum and summary of c++ codes

### 00 - Settings of VS Code

### Code 01 - basic template of mordern c++ coding using VSC

cout:
It is typically used for displaying regular output to the console or terminal.
It is associated with the standard output device, usually the console.
Output sent to cout is buffered.

clog:
It is similar to cout in terms of behavior and usage but is often used for logging purposes.
Unlike cout, clog is unbuffered by default, meaning that the data sent to clog is immediately displayed without waiting for a newline or explicit flushing.
This can be particularly useful when you want to ensure that log messages appear in a timely manner, even during program execution or in case of crashes.

cerr:
cerr stands for "character error stream" and is the standard error stream in C++.
It is intended for displaying error messages and diagnostic information.
Similar to clog, cerr is also unbuffered by default, allowing immediate display of error messages.
Unlike cout and clog, cerr is not affected by the standard output stream redirection, making it useful for separate error reporting, especially when capturing program errors or exceptions.

cin:
cin is the standard input stream in C++, used for reading input from the user or another input source.

cin.get():
It can be helpful when you need to read a specific character or when you want to process input character by character.

cin.clear():
By calling cin.clear(), you can clear any error flags and allow further input operations to be attempted.

getline():
It allows you to read a full line of text as a string, which is useful when you need to process input that may contain spaces or multiple words.
Unlike cin, getline() does not leave the newline character ('\n') in the input stream, discarding it after reading the line.

### Code 02 - built-in data types

Integer Types；
Floating-Point Types；
Character Types；
Boolean Type；
Void Type；
Other Types:
unsigned modifiers；
signed modifier；
auto and decltype: These are type inference mechanisms that allow the compiler to deduce the type of a variable automatically based on its initializer or expression.

### Code 03 - data operations

Precedence and associativity;
Prefix and postfix of in/decrement;
Compound assignment operators;
Relational operators;
Output formatting.

### Code 04 - process numeric types

include <limits>;
include <cmath>;
auto variable = (short int) + (short int);//auto -> int
auto variable = (char) + (char);//auto -> int

### Code 05 - Constants

const
constexpr:
The constexpr specifier declares that it is possible to evaluate the value of the function or variable at compile time.

A constexpr variable must satisfy the following requirements:
its type must be a LiteralType.
it must be immediately initialized
the full-expression of its initialization, including all implicit conversions, constructors calls, etc, must be a constant expression

constinit:
The constinit specifier declares a variable with static or thread storage duration.
Constinit cannot be used together with constexpr or consteval.


### Code 06 - Convertors

implicit data conversions:
The type conversion that is done automatically done by the compiler is known as implicit type conversion. This type of conversion is also known as automatic conversion.
Data lost during conversion (Narrowing Conversion).

explicit data conversions:
When the user manually changes data from one type to another, this is known as explicit conversion. This type of conversion is also known as type casting.
static_cast<>

overflow and underflow

### Code 07 - Bitwise operators

bitwise options:
shift operators
logical operators
compound operators

using masks

pack color information by bit oprating


### Code 08 - Flow control and loops

if constexpr
flow control with initializers
ternary operators
nested loops

size_t:
std::size_t can store the maximum size of a theoretically possible object of any type (including array). A type whose size cannot be represented by std::size_t is ill-formed. On many platforms (an exception is systems with segmented addressing) std::size_t can safely store the value of any non-member pointer, in which case it is synonymous with std::uintptr_t.

std::size_t is commonly used for array indexing and loop counting. Programs that use other types, such as unsigned int, for array indexing may fail on, e.g. 64-bit systems when the index exceeds UINT_MAX or if it relies on 32-bit modular arithmetic.

When indexing C++ containers, such as std::string, std::vector, etc, the appropriate type is the member typedef size_type provided by such containers. It is usually defined as a synonym for std::size_t.


### Code 09 - Array

size of array:
std:size() -> c++17
sizeof(array)/sizeof(element)

array initialization: 
default set to 0

array of charactors:
char[] {"HelloWorld"}, OR cstring with {... , '\0'},

multi dimension arrays

mini program: Fortune Teller

### Code 10 - Basic pointers

pointer
array of pointer

const pointer
pointer to a const variable

pointers and arrays
swap an array

### Code 11 - Pointer arithmetic

navigation
distance between elements:
std::ptrdiff_t

comparing pointers
swap an array

### Code 12 - Dynamically allocate and pointer safety

Dangling pointers
Null pointer:
nullptr

Dynamically allocate a pirece of memory
Memory leak










