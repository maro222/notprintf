#include "main.h"
/**
 * convert - func converts
 * @num: number of digits
 * @base:number base
 * @flags:int flags
 * @params:parametars
 * Return: pointer
*/
char *convert(long int num, int base, int flags, params_t *params)
{
static char *arr;
static char buff[50];
char sign = 0;
char *p;
unsigned long n = num;
(void)params;

if (!(flags && CONVERT_UNSIGNED) && num < 0)
{
n = -num;
sign = '-';
arr = flags & CONVERT_LOWERCASE ? "0123456789abcdef" : "123456789ABCDEF";
p = &buff[49];
*p = '\0';

do {
*--p = arr[n % base];
n /= base;
} while (n != 0);
}
if (sign)
*--p = sign;
return (p);
}
/**
 * print_unsigned - func print unsigned
 * @ap: pars list
 * @params: paramerars
 * Return: printed num
*/
int print_unsigned(va_list ap, params_t *params)
{
unsigned long l;
if (params->l_modifier)
l = (unsigned long)va_arg(ap, unsigned long);
else if (params->h_modifier)
l = (unsigned short int)va_arg(ap, unsigned int);
else
l = (unsigned int)va_arg(ap, unsigned int);
params->unsign = 1;
return (print_number(convert(l, 10, CONVERT_UNSIGNED, params), params));
}
/**
 * print_address - func print address
 * @ap: pars list
 * @params: parametars
 * Return: number
*/
int print_address(va_list ap, params_t *params)
{
unsigned long int n = va_arg(ap, unsigned long int);
char *s;
if (!n)
return (_puts("(nil)"));

s = convert(n, 16, CONVERT_UNSIGNED | CONVERT_LOWERCASE, params);
*--s = 'x';
*--s = '0';
return (print_number(s, params));
}
