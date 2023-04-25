#include "main.h"
#include <string.h>
#include "functions.h"

/**
 * printChar - prints a character to stdout
 * @arg: argument
 *
 * Return: number of characters printed
 */

int printChar(va_list arg)
{
	char c = (char) va_arg(arg, int);

	return (write(1, &c, 1));
}

/**
 * printstring - prints a lower case 's' string
 * @arg: argument
 *
 * Return: number of characters printed
 */

int printstring(va_list arg)
{
	char *str = va_arg(arg, char *);
	int len;

	if (str == NULL)
		str = "(Nill)";
	if (*str == '\0')
		return (-1);

	len = strlen(str);

	return (write(1, str, len));
}


/**
 * printInteger - prints an integer
 * @arg: argument
 *
 * Return: number of characters printed
 */

int printInteger(va_list arg)
{
	int num = va_arg(arg, int);
	int c = 0;
	int tmp = num;
	int div = 1;
	char x;

	if (num < 0)
	{
		x = '-';
		c += _write(x);
		num = -num;
	}

	while (tmp)
	{
		c++;
		tmp /= 10;
	}

	if (num == 0)
	{
		c++;
		_write('0');
	}
	else
	{
		while (num / div > 9)
		{
			div *= 10;
		}
		while (div != 0)
		{
			c++;
			_write(num / div + '0');
			num %= div;
			div /= 10;
		}
	}
	return (c);
}

/**
 * printUnsignedInteger - prints an unsigned integer
 * @arg: argument
 *
 * Return: number of characters printed
 */

int printUnsignedInteger(va_list arg)
{
	int num = va_arg(arg, int);
	int c = 0;
	unsigned int tmp = num;
	unsigned int div = 1;

	while (tmp)
	{
		c++;
		tmp /= 10;
	}

	if (num == 0)
	{
		c++;
		_write('0');
	}
	else
	{
		while (num / div > 9)
		{
			div *= 10;
		}
		while (div != 0)
		{
			c++;
			_write(num / div + '0');
			num %= div;
			div /= 10;
		}
	}
	return (c);
}

/**
 * printSTRING - prints a upper case 'S' string
 * @arg: argument
 *
 * Return: number of characters printed
 */

int printSTRING(va_list arg)
{
	int i;
	char *str = va_arg(arg, char *);
	int len;

	if (str == NULL)
		str = "(NULL)";
	if (*str == '\0')
		return (-1);

	len = _strlen(str);

	for (i = 0; i < len; i++)
	{
		if (str[i] >= 'a' && str[i] <= 'z')
			str[i] -= 32;
	}

	return (write(1, str, len));
}
