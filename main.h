#ifndef __MAIN_H
#define __MAIN_H
#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>
/* declaration of buffer size */
#define BUFFER_SIZE 1024
/* struct declaration */
/**
 * struct specifier - defines a structure for specifier and function
 * @sign: the operator after the modulus
 * @f: the function to be taken
 */
struct specifier
{
	char *sign;
	int (*f)(va_list, char *, int *);
};
typedef struct specifier spec;
/* functions prototypes */
int _printf(const char *format, ...);
int chkr(const char *format, spec fun_list[], va_list args, char *buffer, int *buffer_index);
/* helper function */
int print_number(unsigned int n);
/* print based on specifier it meets */
int print_chara(va_list list, char *buffer, int *buffer_index);
int print_percent(va_list list __attribute__((unused)), char *buffer, int *buffer_index);
int print_string(va_list list, char *buffer, int *buffer_index);
int print_int(va_list list, char *buffer, int *buffer_index);
int print_binary(va_list list, char *buffer, int *buffer_index);
int print_unsigned(va_list list, char *buffer, int *buffer_index);
int print_octal(va_list list, char *buffer, int *buffer_index);
int print_hex(va_list list, char *buffer, int *buffer_index);
int print_heX(va_list list, char *buffer, int *buffer_index);
int print_S(va_list list, char *buffer, int *buffer_index);
#endif /* MAIN_H */
