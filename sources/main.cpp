#include "../includes/my_cat.hpp"

int main(int ac, char **av)
{
    if (!ac)
        return 0;
    my_putchar(av[1][0]);
    return 0;
}