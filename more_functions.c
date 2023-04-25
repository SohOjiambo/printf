#include "main.h"
#include <stdlib.h>
#include "functions.h"

/**
 * printUnsignedIntToBinary - converts unsigned integer to binary
 * @arg: argument
 *
 * Return: number of characters printed
 */

int printUnsignedIntToBinary(va_list arg)
{
	int binary_No = 0;
	int base = 1;
	unsigned int num, unsigned_num;

	num = va_arg(arg, unsigned int);
	unsigned_num = num;

	while (unsigned_num > 0)
	{
		binary_No += (unsigned_num % 2) * base;
		unsigned_num /= 2;
		base *= 10;
	}
	return (binary_No);
}

/**
 * printOctal - prints an octal number
 * @arg: argument
 *
 * Return: number of digits printed -1 if malloc fails
 */

int printOctal(va_list arg)
{
	unsigned int num = va_arg(arg, unsigned int);
	unsigned int tmp = num;
	int c = 0, i;
	int *octalNum = NULL;

	while (tmp != 0)
	{
		c++;
		tmp /= 8;
	}

	octalNum = malloc(c * sizeof(int));

	if (octalNum == NULL)
		return (-1);

	for (i = 0; i < c; i++)
	{
		octalNum[i] = num % 8;
		num /= 8;
	}
	for (i = c - 1; i >= 0; i--)
	{
		_write(octalNum[i] + '0');
	}
	free(octalNum);

	return (c);
}

/**
 * printHexadecimal - prints an 'a' hexadecimal number.
 * @arg: argument
 *
 * Return: the number of digits printed or -1 if malloc fails
 */

int printHexadecimal(va_list arg)
{

	unsigned int num = va_arg(arg, unsigned int);
	int count = 0, reminder, i;
	char *hexNum = malloc(sizeof(char));

	if (hexNum == NULL)
		return (-1);

	if (num == 0)
	{
		count++;
		hexNum[0] = '0';
	}
	else
	{
		while (num != 0)
		{
			reminder = num % 16;

			if (reminder < 10)
				hexNum[count] = reminder + 48;
			else
				hexNum[count] = reminder + 55;
			num /= 16;
			count++;

			hexNum = realloc(hexNum, sizeof(char) * (count + 1));
			if (hexNum == NULL)
			return (-1);
		}
	}

	for (i = count - 1; i >= 0; i--)
		_write(hexNum[i]);

	free(hexNum);

	return (count);
}


/**
 * printHEXADECIMAL - prints an 'A' hexadecimal number.
 * @arg: argument
 *
 * Return: the number of digits printed
 */
int printHEXADECIMAL(va_list arg)
{
	unsigned int num = va_arg(arg, unsigned int);
	int count = 0, reminder, i;
	char *hexNum = malloc(sizeof(char));

	if (hexNum == NULL)
		return (-1);
	if (num == 0)
	{
		count++;
		hexNum[0] = '0';
	}
	else
	{
		while (num != 0)
		{
			reminder = num % 16;
			if (reminder < 10)
				hexNum[count] = reminder + 48;
			else
				hexNum[count] = reminder + 55;
			if (hexNum[count] >= 'a' && hexNum[count] <= 'f')
				hexNum[count] -= 32;
			num /= 16;
			count++;
			hexNum = realloc(hexNum, sizeof(char) * (count + 1));
			if (hexNum == NULL)
				return (-1);
		}
	}

	for (i = count - 1; i >= 0; i--)
		_write(hexNum[i]);

	free(hexNum);

	return (count);
}

/**
 * printPointer - prints the value of a pointer
 * @arg: argument
 *
 * Return: number of characters printed
 */

int printPointer(va_list arg)
{
	void *ptr = va_arg(arg, void *);

	unsigned long int address = (unsigned long int) ptr;
	unsigned int quotient;
	int i = 0, j;
	char *hexadecimal = malloc(sizeof(char) * 100);

	if (ptr == NULL)
	{
		_write('(');
		_write('n');
		_write('i');
		_write('l');
		_write(')');
		return (5);
	}


	if (hexadecimal == NULL)
		return (-1);

	while (address != 0)
	{
		quotient = address % 16;
		if (quotient < 10)
			hexadecimal[i++] = 48 + quotient;
		else
			hexadecimal[i++] = 55 + quotient;
		address /= 16;
	}

	_write('0');
	_write('x');

	for (j = i - 1; j >= 0; j--)
		_write(hexadecimal[j]);

	free(hexadecimal);

	return (i + 2);
}
