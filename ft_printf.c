#include "ft_printf.h"

int ft_printf(const char *str, ...) {
    int i;
    int len;
    va_list args;

    i = 0;
    len = 0;
    va_start(args, str);
    while (str[i]) {
        if (str[i] == '%') {
            len += ft_print_format(args, str[i + 1]);
            i++;
        } else
            len += ft_print_chr(str[i]);
        i++;
    }
    va_end(args);
    return (len);
}
