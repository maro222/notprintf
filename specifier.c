#include "main.h"
/**
 *get_specifier - find function format
 *@s: string
 *Return: number of bytes
 */
int (*get_specifier(char *s))(va_list ap, params_t *params)
{
specifier_t spec[] = {
	{"c", print_char},
	{"d", print_int},
	{"i", print_int},
	{"s", print_string},
	{"%", print_percent},
	{"b", print_binary},
	{"o", ptint_octal},
	{"u", print_unsigned},
	{"x", print_hex},
	{"X", print_HEX},
	{"p", print_addr},
	{"S", print_S},
	{"r", print_reverse},
	{"R", print_rotate},
	(NULL, NULL)
};
int i = 0;

while (spec[i].specifier[0])
{
if (*s == spec[i].specifier[0])
{
	return (spec[i].f);
}
i++;
}
return (NULL);
}
/**
 * get_print_func - find format
 * @s: the string format
 * @ap: arg pointer
 * @params: parameter struct
 * Return: num of bytes
 */
int get_print_func(char *s, va_list ap, params_t *params)
{

int (*f)(va_list, params_t) = get_specifier(s);

if (f)
return (f(ap, params));
return (0);
}
/**
 * get_flag - get function flag
 * @s:the string format
 * @params: the struct parametars
 * Return: if flag valid
 */
int get_flag(char *s, params_t *params)
{
int i = 0;

switch (*s)
{
	case '+':
		i = params->plus_flag = 1;
		break;
	case ' ':
		i = params->space_flag = 1;
		break;
	case '#':
		i = params->hashtag_flag = 1;
		break;
	case '-':
		i = params->minus_flag = 1;
		break;
	case '0':
		i = params->zero_flag = 1;
	}
return (i);
}
/**
 *get_modifier - find function modifier
 *@s: string
 *@params: struct parameters
 *Return: 1 if valid
 */
int get_modifier(char *s, params_t *params)
{
int i = 0;

switch (*s)
{
	case 'h':
	i = params->h_modifier = 1;
	break;
	case 'l':
	i = params->l_modifier = 1;
	break;
}
return (0);
}
/**
 *get_width - get string width
 *@s: string
 *@params: func. parametars
 *@ap: arg. pointer
 *Return: pointer
 */
char *get_width(char *s, params_t *params, va_list ap)
{
int d = 0;

if (*s == '*')
{
d = va_arg(ap, int);
s++;
}
else
{
while (_isdigit(*s))
	d = d * 10 + (*s++ - '0');
}
params->width = d;
return (s);
}
