#include "../includes/my_cat.hpp"



int main(int ac, char **av)
{
    bool    result;
    int     i;

    i = 1;
    if (check_nb_params(ac) == EXIT_FAILURE)
        return EXIT_FAILURE;
    while (av[i])
    {
        std::fstream			f_stream;

		result = open_files(f_stream, av[i]);
    	if (result)
			command_cat(f_stream);
        else
            error_handle(av[i]);
        close_file(f_stream);
        i++;
    }
    return EXIT_SUCCESS;
}