This project has been created as part of the 42 curriculum by luimarti.

ft_printf
Description

ft_printf is a reimplementation of the C library function printf. The goal is to recreate its variadic interface and formatting behaviour from scratch, without using the standard library's own output functions.

The interesting part of the project is not the formatting itself but the mechanism behind it: a function that accepts an unknown number of arguments of unknown types, resolved at runtime by parsing the format string. That means working with stdarg.h (va_start, va_arg, va_end), understanding default argument promotion, and writing a parser that walks the format string character by character and dispatches to the right conversion.

The function returns the number of characters printed, and handles undefined input the way the real printf does wherever the standard defines it.

Features

Supported conversions:

Specifier	Prints
%c	A single character
%s	A string
%p	A pointer in hexadecimal
%d / %i	A signed decimal integer
%u	An unsigned decimal integer
%x / %X	An unsigned hexadecimal, lower/upper case
%%	A literal percent sign
<!-- TODO: if you implemented the bonus (flags -, 0, ., #, space, +, width), list them here. If you did not, delete this comment and leave the table. -->
Instructions
bash
git clone https://github.com/Lucho-cadete/ft_printf.git
cd ft_printf
make

This builds libftprintf.a. To use it:

c
#include "ft_printf.h"

int main(void)
{
    ft_printf("Hex: %x, pointer: %p, string: %s\n", 255, &main, "hello");
    return (0);
}
bash
cc main.c -L. -lftprintf -I. -o test && ./test
Resources
man 3 printf — the authoritative description of every conversion and of the return value.
man 3 stdarg — the variadic argument macros and their constraints.
GNU C manual — Variadic Functions — explains default argument promotion, which is the source of most subtle bugs in this project.
Use of AI

AI assistance was used for: explaining what variadic functions are and why they exist, which was new to me; clarifying default argument promotion, which is the source of most of the subtle bugs in this project; discussing whether a dispatch table would be cleaner than an if-chain, after mine was already working; and suggesting edge cases to test (empty strings, INT_MIN, a null pointer passed to %p). The parser, the conversions and the debugging are mine.