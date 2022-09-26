#include <unistd.h>
#include <stdio.h>


// void	my_putchar(char c) {
//     if (&c == NULL)
//         return ;
// 	write(1, &c, 1);
// }

int main(int ac, char **av)
{
    // my_putchar(av[1][0]);
    printf("result ac %d", ac);
    return 0;
}