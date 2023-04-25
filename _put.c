#include "main.h"

/**
 * _puts - return the length of a string and print it to stdout
 * @str: input string
 *
 * Return: nothing
 */

int _puts(char *str)
{
	char *ch = str;

	while (*str)
		_putchar(*str++);
	return (str - ch);
}

/**
 * _putchar - print each character send to it by _puts to stdout
 *
 * @c: character to be print
 * Return: 1 on success, -1 on failure
 */

int _putchar(int c)
{
	static int i;
	static char buffer[OUTPUT_BUF_SIZE];

	if (c == BUF_FLUSH || i >= OUTPUT_BUF_SIZE)
	{
		write(1, buffer, i);
		i = 0;
	}
	if (c != BUF_FLUSH)
		buffer[i++] = c;
	return (1);
}
