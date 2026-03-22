# holbertonschool-printf

School project to recreate C's printf function.

## Authors

Sam Chen

Sierra Hunt

## Requirements

- A valid C installation
- A C compiler, such as **gcc**

## Installation

To use _printf in your own code:
1. Download the *.c and main.h files from the main directory in this repository
2. Place all the files in the same directory together, such as a subdirectory in your project

## Usage

Download and use `man [directory]/man_3_printf` for more information
1. `#include "[directory]/main.h"` in the file you intend to use `_printf`
2. First give the function a string, known as a format string, then none or many other arguments. The format string can contain subformats which define the output of the respective arguments, and is given as `%[flags][width][precision]specifier`. Consult the manual page
3. When compiled and run, when `_printf` is executed it will output its arguments as defined in the format string into the terminal

## Examples

### Print a variable string

Input: `_printf("Hey, %s.", name);`, where `name` is a pointer to a string "Adora".

Output: `Hey, Adora.`

### Print a number

Input: `_printf("Bytes in a kilobyte: %d", 1024);`

Output: `Bytes in a kilobyte: 1024`

### Print a string and a number, the number is at least 9 digits long

Input: `_printf("%s's high score: %.9d", "Sam", 4500);`

Output: `Sam's high score: 000004500`

### Print a hexadecimal, the field is at least 6 characters wide, is left justified, and has the hex prefix

Input: `_printf("21 in hex: [%#6x]", 21);`

Output: `21 in hex: [0x15  ]`

## What if I give more arguments than the format string needs?

They will be safely ignored. For example, if called as `_printf("hello %s\n", "world", 1, 2, 3, 4);`, the output will be `hello world` (with a new line) and the extra arguments will have no effect.
