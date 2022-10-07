#include "../includes/my_cat.hpp"

int main(int ac, char **av)
{
    if (check_nb_params(ac) == EXIT_FAILURE)
        return EXIT_FAILURE;
    if(av)
        error_handle(av[1]);
    std::cout << "RESULT AV = " << av[1] << std::endl;
    std::string test = "Makefiles";
    std::cout << "var test before .data() : " << test << std::endl;
    std::cout << "var test after .data() : " << test.data() << std::endl;
    is_open_files(open_files(test.data()));

    return 0;
}