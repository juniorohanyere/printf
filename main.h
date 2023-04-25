#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

#define VOID(x) (void)(x)
#define BUFFER_SIZE 1024
#define MINUS 1
#define PLUS 2
#define ZERO 4
#define HASH 8
#define SPACE 16
#define LONG 2
#define SHORT 1

/**
 * struct fmt - a struct function
 *
 * @fmt: The format specifier
 * @func: The function associated
*/

struct fmt
{
	char fmt;
	int (*func)(va_list, char[], int, int, int, int);
};


/**
 * typedef struct fmt format_t - type definition for the struct fmt
 *
 * @fmt: The format specifier
 * @format_t: The function associated
*/

typedef struct fmt format_t;

int _printf(const char *format, ...);
int handle_print(const char *fmt, int *i,
va_list args, char buffer[], int flag, int width, int precision, int size);

int print_char(va_list args, char buffer[],
	int flag, int width, int precision, int size);
int print_string(va_list args, char buffer[],
	int flag, int width, int precision, int size);
int print_percentage(va_list args, char buffer[],
	int flag, int width, int precision, int size);


int print_integer(va_list args, char buffer[],
	int flag, int width, int precision, int size);
int print_binary(va_list args, char buffer[],
	int flag, int width, int precision, int size);
int print_unsigned(va_list args, char buffer[],
	int flag, int width, int precision, int size);
int print_octal(va_list args, char buffer[],
	int flag, int width, int precision, int size);
int print_hexadecimal(va_list args, char buffer[],
	int flag, int width, int precision, int size);
int print_HEXADECIMAL(va_list args, char buffer[],
	int flag, int width, int precision, int size);

int print_hex(va_list args, char map_to[],
char buffer[], int flag, char f, int width, int precision, int size);

int print_exclusive_string(va_list args, char buffer[],
	int flag, int width, int precision, int size);

int print_pointer(va_list args, char buffer[],
	int flag, int width, int precision, int size);

int get_flag(const char *format, int *i);
int get_width(const char *format, int *i, va_list list);
int get_precision(const char *format, int *i, va_list list);
int get_size(const char *format, int *i);

int print_reverse(va_list args, char buffer[],
	int flag, int width, int precision, int size);

int print_rot13(va_list args, char buffer[],
	int flag, int width, int precision, int size);

int write_char(char c, char buffer[],
	int flag, int width, int precision, int size);
int write_number(int is_positive, int i, char buffer[],
	int flags, int width, int precision, int size);
int write_num(int i, char buffer[], int flags, int width, int precision,
	int length, char p, char ch);
int write_pointer(char buffer[], int i, int length,
	int width, int flag, char p, char ch, int c);

int write_unsignd(int n, int i, char buffer[],
	int flag, int width, int precision, int size);

void print_buffer(char buffer[], int *index);

int is_printable(char);
int hex(char, char[], int);
int is_digit(char);

long int convert_size_number(long int num, int size);
long int convert_size_unsignd(unsigned long int num, int size);

#endif /* MAIN_H */
