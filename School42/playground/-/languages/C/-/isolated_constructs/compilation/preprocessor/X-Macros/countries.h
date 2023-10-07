/*
X-Macros is a programming technique that uses macros to define data structures, constants, or code blocks.
The "X" in X-Macros stands for "external data," which refers to the external data or constants that are used by the program.

In X-Macros, a macro is defined with a list of parameters, and the macro is called with different arguments to generate different code or data.
The parameters to the macro are typically defined in a header file, and the macro is used in the source code to generate data structures or code.

For example, suppose we have a program that needs to define a list of countries and their corresponding ISO 3166-1 alpha-2 codes.
We can use X-Macros to define the data structure for the list of countries and generate the necessary code to initialize it.
Here's an example of how this might work: First, we define the X-Macro in a header file, countries.h:
*/

#define COUNTRY_LIST \
    X("United States", "US") \
    X("Canada", "CA") \
    X("Mexico", "MX") \
    X("Germany", "DE") \
    X("France", "FR") \
    X("Italy", "IT")
