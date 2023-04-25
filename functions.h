#ifndef _FUNCTIONS_H_
#define _FUNCTIONS_H_

typedef struct {
	char *reference;
	int (*function)(va_list);
} referenceLetter;

int _write(int c);
int _strlen(char *s);
int printChar(va_list arg);
int printString(va_list arg);
int printInteger(va_list arg);
int printUnsignedInteger(va_list arg);
int printUnsignedIntToBinary(va_list arg);
int printOctal(va_list arg);
int printHexadecimal(va_list arg);
int printHEXADECIMAL(va_list arg);
int printSTRING(va_list arg);
int printPointer(va_list arg);

#endif
