#include "main.h"
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#include "functions.h"

<<<<<<< HEAD
void print_buffer(char buffer[], int *buff_ind);
=======
/**
 * printReference - prints an identifier
 * @amp: the character to be printed. Comes after %
 * @arg: argument for the identifier
 *
 * Return: the number of characters printed
 */

int printReference(char amp, va_list arg)
{
	int i;

	referenceLetter functions[] = {
		{"c", printChar},
		{"s", printString},
		{"d", printInteger},
		{"i", printInteger},
		{"u", printUnsignedInteger},
		{"b", printUnsignedIntToBinary},
		{"o", printOctal},
		{"x", printHexadecimal},
		{"X", printHEXADECIMAL},
		{"S", printSTRING},
		{"p", printPointer},
		{NULL, NULL}
	};

	for (i = 0; functions[i].reference != NULL; i++)
	{
		if (*(functions[i].reference) == amp)
			return (functions[i].function(arg));
	}
	return (0);
}
>>>>>>> 9a239f9e8c5e86b44637bd8e5ef030fb015404b1

/**
 * _printf - Printf function
 * @format: format.
 * Return: Printed chars.
 */
int _printf(const char *format, ...)
{
	int i, printed = 0, printed_chars = 0;
	int flags, width, precision, size, buff_ind = 0;
	va_list list;
	char buffer[BUFF_SIZE];

	if (format == NULL)
		return (-1);

	va_start(list, format);

	for (i = 0; format && format[i] != '\0'; i++)
	{
		if (format[i] != '%')
		{
<<<<<<< HEAD
			buffer[buff_ind++] = format[i];
			if (buff_ind == BUFF_SIZE)
				print_buffer(buffer, &buff_ind);
			/* write(1, &format[i], 1);*/
			printed_chars++;
		}
		else
		{
			print_buffer(buffer, &buff_ind);
			flags = get_flags(format, &i);
			width = get_width(format, &i, list);
			precision = get_precision(format, &i, list);
			size = get_size(format, &i);
			++i;
			printed = handle_print(format, &i, list, buffer,
				flags, width, precision, size);
			if (printed == -1)
				return (-1);
			printed_chars += printed;
		}
	}

	print_buffer(buffer, &buff_ind);

	va_end(list);

	return (printed_chars);
=======
			write(1, &format[i], 1);
			character++;
		}
		else
		{
			i++;
			if (format[i] == '\0')
				return (-1);
			reference = printReference(format[i], arg);
			if (reference == -1)
				return (-1);
			character += reference;
		}
	}

	va_end(arg);

	return (character);
>>>>>>> 9a239f9e8c5e86b44637bd8e5ef030fb015404b1
}

/**
 * print_buffer - Prints the contents of the buffer if it exist
 * @buffer: Array of chars
 * @buff_ind: Index at which to add next char, represents the length.
 */
void print_buffer(char buffer[], int *buff_ind)
{
	if (*buff_ind > 0)
		write(1, &buffer[0], *buff_ind);

	*buff_ind = 0;
}

