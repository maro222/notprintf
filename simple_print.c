#include "main.h"

/**
 * print_from_to - print chars in range
 * @start: start point
 * @stop: stop point
 * @except: exceptions
 * Return: sum
 */
int print_from_to(char *start, char *stop, char *except)
{
int sum = 0;

while (start <= stop)
{
if (start != except)
sum += _putchar(*start);
start++;
}
return (sum);
}

/**
 * print_rev - func print reverse
 * @ap: list of args
 * @params: parameters
 * Return: reversed string
 */
int print_rev(va_list ap, params_t *params)
{
int len, sum = 0;
char *s = va_arg(ap, char*);
(void)params;
if (s)
{
for (len = 0; *s; s++)
len++;
s--;
for (; len > 0; s--, len--)
sum += _putchar(*s);
}
return (sum);
}

/**
 * print_rot13 - print in rot13
 * @ap: arg list
 * @params: parameters
 * Return: rot13 string
 */
int print_rot13(va_list ap, params_t *params)
{
int i = 0, idx = 0;
int cou = 0;
char arr[] =
"NOPQRSTUVWXYZABCDEFGHIJKLM     nopqrstuvwxyzabcdefghijklm";
char *a = va_arg(ap, char *);
(void)params;

while (a[i])
{
if ((a[i] >= 'A' && a[i] <= 'Z') || (a[i] >= 'a' && a[i] <= 'z'))
{
idx = a[i] - 65;
cou += _putchar(arr[idx]);
}
else
cou += _putchar(a[i]);
i++;
}
return (cou);
}
