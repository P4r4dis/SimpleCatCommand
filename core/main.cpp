#include "../includes/my_cat.hpp"

int main(int ac, char **av)
{
    if (check_nb_params(ac) == EXIT_FAILURE)
        return EXIT_FAILURE;
    if(av)
        error_handle(av[1]);
    return 0;
}