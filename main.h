#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>

<<<<<<< HEAD
int _putchar(char c);
int _strlen(char *s);
int print_char(va_list args);
int print_string(va_list args);
int print_number(va_list args);
int _printf(const char *format, ...);

/**
 * struct dt - struct
 * @type: format type
 * @func: function ptr
 */
typedef struct dt
{
	char type;
	int (*func)(va_list);
} fmt_t;

=======
int _printf(const char *format, ...);

>>>>>>> origin
#endif /* MAIN_H */

