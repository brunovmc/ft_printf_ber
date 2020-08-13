#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>


int		ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int		ft_printf(const char *str, ...)
{
    int count;
    va_list args;
    char w;


    count = 0;
    va_start(args, str);
    while (*str)
    {

        if (*str == '%')
        {
            str++;
            if (*str == 'c')
            {
                w = va_arg(args, int);
                count += ft_putchar(w);
                str++;
            }
        }
        count += ft_putchar(*str);
        str++;
    }
    return (count);
}

int main()
{
    int i;

    i = ft_printf("%c\n", 'k');
    printf("%d %s", i, "teste");
    return (0);
}
