#include "main.h"
/**
 * print_hex - func print hex_numbers
 * @ap:pars list
 * @params:parametars
 * Return: hex num
*/
int print_hex(va_list ap, params_t *params)
{
unsigned long l;
int c = 0;
char *s;

if (params->l_modifier)
l = (unsigned long)va_arg(ap, unsigned long);
else if (params->h_modifier)
l = (unsigned short int)va_arg(ap, unsigned int);
else
l = (unsigned int)va_arg(ap, unsigned int);
s = convert(l, 16, CONVERT_UNSIGNED | CONVERT_LOWERCASE, params);
if (params->hashtag_flag && l)
{
*--s = 'x';
*--s = '0';
}
params->unsign = 1;
return (c += print_number(s, params));

}
/**
 * print_HEX - func print HEX_numbers
 * @ap: pars list
 * @params: parametars
 * Return: HEX num
*/
int print_Hex(va_list ap, params_t *params)
{
unsigned long l;
int c = 0;
char *s;

if (params->l_modifier)
l = (unsigned long)va_arg(ap, unsigned long);
else if (params->h_modifier)
l = (unsigned short int)va_arg(ap, unsigned int);
else
l = (unsigned int)va_arg(ap, unsigned int);
s = convert(l, 16, CONVERT_UNSIGNED, params);
if (params->hashtag_flag && l)
{
*--s = 'X';
*--s = '0';
}
params->unsign = 1;
return (c += print_number(s, params));
}
/**
 * print_binary - func print binary_numbers
 * @ap: pars list
 * @params: parametars
 * Return: binary num
*/
int print_binary(va_list ap, params_t *params)
{
unsigned int n = va_arg(ap, unsigned int);
char *s = convert(n, 2, CONVERT_UNSIGNED, params);
int c = 0;
if (params->hashtag_flag && n)
*--s = '0';
params->unsign = 1;
return (c += print_number(s, params));
}
/**
 * print_octal -func print binary_numbers
 * @ap:pars list
 * @params:parametars
 * Return: octal num
*/
int print_octal(va_list ap, params_t *params)
{
unsigned long i;
char *s;
int c = 0;
if (params->l_modifier)
i = (unsigned long)va_arg(ap, unsigned long);
else if (params->h_modifier)
i = (unsigned short int)va_arg(ap, unsigned int);
else
i = (unsigned int)va_arg(ap, unsigned int);

s = convert(i, 8, CONVERT_UNSIGNED, params);

if (params->hashtag_flag && i)
*--s = '0';
params->unsign = 1;

return (c += print_number(s, params));
}
