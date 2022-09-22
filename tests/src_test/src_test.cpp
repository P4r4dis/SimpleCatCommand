#include <../include_test/test.hpp>

void redirect_all_stdout(void)
{
        cr_redirect_stdout();
        cr_redirect_stderr();
}

int error(void)
{
        write(2, "error", 5); // stdoout = 1 and stderr = 2
        return(0);
}