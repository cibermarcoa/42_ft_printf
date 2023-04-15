#include "ft_printf.h"

int main()
{
    int a = 42;
    char *b = "hello";
    char c = 'c';
    int length = 0;
    //ft_printf("%d %s %c asasassaan naa", a, b, '!');
    length += ft_printf("%c   qwer   %c", c, c);
    printf("%d", length);
    return (0);
}

