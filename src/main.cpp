#include <iostream>
#include "Calculator/CCalculator.h"

// document directories

/**
 * @dir src
 * @brief Source files directory
 */
/**
* @dir src/Calculator
* @brief Command pattern (except command) related classes
*/
/**
* @dir src/Command
* @brief CCommand class and its inherited classes in inner folders
*/
/**
* @dir src/Command/Basic
* @brief Working with program related command classes
*/
/**
* @dir src/Command/Math
* @brief Linear algebra algorithms related command classes
*/
/**
* @dir src/Command/Memory
* @brief Working with program and file memory related command classes
*/
/**
* @dir src/Command/Operation
* @brief Operations with matrices related command classes
*/
/**
* @dir src/Matrix
* @brief Matrix effective memory representation related classes
*/

int main() {
    CCalculator calculator;

    calculator.run();

    return 0;
}
