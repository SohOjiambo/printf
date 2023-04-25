#include "main.h"
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#include "functions.h"

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
		{"s", printstring},
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

/**
 * _printf - produces output according to a format
 * @format: character string
 *
 * Return: the number of characters printed or
 * -1 on failure
 */

int _printf(const char *format, ...)
{
	unsigned int i;
	int reference = 0, character = 0;
	va_list arg;

	va_start(arg, format);
	if (format == NULL)
		return (-1);

	for (i = 0; format[i] != '\0'; i++)
	{
		if (format[i] != '%')
		{
			write(1, &format[i], 1);
			character++;
			continue;
		}
		if (format[i + 1] == '%')
		{
			write(1, "%", 1);
			character++;
			i++;
			continue;
		}
		if (format[i + 1] == '\0')
			return (-1);
	}
	reference = printReference(format[i + 1], arg);
	if (reference == -1)
		return (-1);

	character += reference;
	i++;


	va_end(arg);

	return (character);
}
