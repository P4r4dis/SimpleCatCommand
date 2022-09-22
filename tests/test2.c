#include <unistd.h>

void	my_putchar(char c) {
	write(1, &c, 1);
}

int main(int ac, char **av)
{
    my_putchar(av[1][0]);
    return 0;
}