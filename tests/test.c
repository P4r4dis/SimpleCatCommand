#include <criterion/criterion.h>
#include <unistd.h>

void	my_putchar(char c) {
	write(1, &c, 1);
}

Test (simple, test) {
	cr_assert(10, "HelloWorld");
}
