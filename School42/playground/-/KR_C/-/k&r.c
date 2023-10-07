#include <stdio.h>

/*** VARIABLES SCOPE ***/

/***********************************************************************************************************************************************
BLOCK SCOPE 
- Variables declared inside a block, typically within a function, have block scope.
- They are visible only within that block and its nested blocks.
************************************************************************************************************************************************/

void block_scope() 
{
    int x = 10; // Variable x has block scope
    if (x > 5)
    {
        int y = 20; // Variable y has block scope inside the if block
    }
        // y is not accessible here (out of scope)
}

/************************************************************************************************************************************************
FUNCTION SCOPE
- Function parameters and variables declared inside a function have function scope.
- They are visible only within that specific function.
- When the function returns, the function's scope is exited, and the local variables are deallocated. 
*************************************************************************************************************************************************/

void function_scope(int param)
{
    int localVar = 5; // localVar has function scope
    // localVar and param are accessible within this function
}
    // localVar and param are not accessible outside the function (out of scope)

/*************************************************************************************************************************************************
FILE SCOPE (STATIC GLOBAL SCOPE)
- Variables declared outside any function (at the top level of a file) have file scope.
- By default, these variables have external linkage, meaning they are visible across multiple files.
- If the static keyword is used before the declaration, the variable has internal linkage and is only visible within the current file.
**************************************************************************************************************************************************/

static int file_scope_internal; // filescope has file scope with in (visible only within the file)ternal linkage

int file_scope_external; // file scope with external linkage (visible across multiple files)


/*************************************************************************************************************************************************
GLOBAL SCOPE
- Variables declared outside any function (at the top level of a file) without the static keyword have global scope and external linkage by default.
- They are visible across multiple files in the entire program.
**************************************************************************************************************************************************/

int global_scope; // globalVar has global scope with external linkage (visible across multiple files)

/*************************************************************************************************************************************************
STRUCT/UNION/ENUMERATION SCOPE
- Members of a structure, union, or enumeration have scope limited to the structure, union, or enumeration in which they are defined.
**************************************************************************************************************************************************/

struct Point
{
    int x; // Member x has scope limited to the Point structure
    int y; // Member y has scope limited to the Point structure
};


/**************************************************************************************************************************************************
LABEL SCOPE
- Labels used for goto statements have a limited scope and are accessible only within the same function.
***************************************************************************************************************************************************/

void someFunction()
{
    start: // Label "start" has limited scope within someFunction()
    // ...
    goto start; // Valid since "start" is within the same function
};

/**************************************************************************************************************************************************
MACRO SCOPE
- Macros defined using the #define directive have global scope.
- They can be used anywhere in the program after their definition.
**************************************************************************************************************************************************/


#define MAX_VALUE 100 // MAX_VALUE has global scope and can be used anywhere in the program


