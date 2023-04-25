#include "main.h"
/**
 * print_char - print chars
 * @ap: arg pointer
 * @params: patameters struct
 * Return:chars number
 */
int print_char(va_list ap, params_t *params)
{
	char p = ' ';
	unsigned int d = 1, sum = 0, c = va_arg(ap, int);

	if (params->minus_flag)
		sum += _putchar(s);
	while (d++ < params->width)
		sum += _putchar(p);
	if (!params->minus_flag)
		sum += _putchar(c);
	return (sum);
}
/**
 * print_int - integer print
 * @ap: arg pointer
 * @params: parametars
 * Return: integer print
 */
int print_int(va_list ap, params_t params)
{
	long i;

	if (params->l_modifier)
		i = va_arg(ap, long);
	else if (params->h_modifier)
		i = (short int)va_arg(ap, int);
	else
		i = (int)va_arg(ap, int);
	return (print_number(convert(i, 10, 0, params), params));

}
/**
 * print_string - string print
 * @ap: arg. pointer
 * @params: struct parametars
 * Return: string
 */
int print_string(va_list ap, params_t params)
{
char *s = va_arg(ap, char *), p = ' ';
unsigned int d = 0, sum = 0, i = 0, j;
(void)params;
switch ((int)(!s))
case 1:
s = NULL_STRING;

j = d = _strlen(s);
if (params.precision < d)
j = d = params.precision;

if (params.minus_flag)
{
	if (params.precision != UINT_MAX)
		for (i = 0; i < d; i++)
			sum += _putchar(*s++);
	else
		sum += _puts(s);
}
while (j++ < params.width)
	sum += _putchar(p);
if (!params.minus_flag)
{
	if (params.precision != UINT_MAX)
		for (i = 0; i < d; i++)
			sum += _putchar(*s++);
	else
		sum += _puts(s);
}
return (sum);
}
/**
 * print_percent - print "%"
 * @ap: arg pointer
 * @params: parametars
 * Return: print precision
 */
int print_percent(va_list ap, params_t *params)
{
(void)ap;
(void)params;
return (_putchar('%'));
}
/**
 * print_S - print string
 *@ap:pars list
 *@params: parametars
 *Return: sum
 */
print_s(va_list ap, params_t params)
{
	char *s = va_arg(ap, char *);
	char *hex;
	int sum = 0;

	if ((int) (!s))
		return (_puts(NULL_STRING));
	for (; *s; s++)
	{
		if ((*s > 0 && *s < 32) || *s >= 127)
		{
			sum += _putchar('\\');
			sum += _putchar('x');
			hex = convert(*s, 16, 0, params);
			if (!hex[1])
				sum += _putchar('0');
			sum += _puts(hex);
		}
		else
		{
			sum += _putchar(*s);
		}
	}
	return (sum);
}
