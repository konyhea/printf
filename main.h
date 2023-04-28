#ifndef __MAIN_H
#define __MAIN_H

#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>


/* struct declaration */

/**
 * struct specifier - defines a structure for specifier  and function
 * @sign: the operator after the modulus
 * @f: the operation that will have to be taken
 *
 */

struct specifier
{
	char *sign;
	int(*f)(va_list);
};
typedef struct specifier spec;

/* function prototypes */

int print_char(char c);
int _printf(const  char *format, ...);
int checker(const char *format, spec fun_list[], va_list args);

/* helper function */

int print_number(unsigned int n);

/* function to write output based on the specifier it meet */

int print_chara(va_list);
int print_string(va_list);
int print_percent(va_list);
int print_int(va_list);
int print_binary(va_list);
int print_unsigned(va_list);


#endif
