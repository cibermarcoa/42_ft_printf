#include "ft_printf.h"

int main(void)
{
    long a = printf(" %u ", -2);
    printf("\n");
    long b = ft_printf(" %u ", -2);
    printf("\n");
    if (a == b)
        printf("iguales");
    return (0);
}
