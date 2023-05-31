

C++11:


C++14:


C++17:


C++20:


C++23 (upcoming):


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

Integer Types:
int- Represents signed integers with a typical range of at least -32,767 to 32,767.
short- Represents signed short integers with a smaller range than int.
long- Represents signed long integers with a larger range than int.
long long- Represents signed long long integers with a larger range than long.

Floating-Point Types:
float- Represents single-precision floating-point numbers.
double- Represents double-precision floating-point numbers, which have higher precision than float.
long double- Represents extended-precision floating-point numbers, which have even higher precision than double.

Character Types:
char- Represents single characters, such as letters, digits, or special symbols.
char16_t- Represents 16-bit Unicode characters.
char32_t- Represents 32-bit Unicode characters.
wchar_t- Represents wide characters, typically used for extended character sets.

Boolean Type:
bool- Represents boolean values, which can be either true or false.

Void Type:
void- Represents the absence of a type. It is commonly used as a return type for functions that do not return a value.

Other Types:

unsigned modifiers- You can apply the unsigned modifier to integer types to represent only non-negative values, effectively doubling the positive range of the type.

signed modifier- The signed modifier is used to explicitly specify a signed integer type, although it is optional as most integer types are signed by default.

auto and decltype- These are type inference mechanisms that allow the compiler to deduce the type of a variable automatically based on its initializer or expression.

### Code 03(upcoming)
