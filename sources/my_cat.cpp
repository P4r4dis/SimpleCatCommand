#include "../includes/my_cat.hpp"

unsigned int		check_nb_params(unsigned int ac)
{
	if (ac < 2)
	{
		std::cerr << "my_cat : Usage : ./my_cat file [...]" << std::endl;
		return EXIT_FAILURE;
	}
	return EXIT_SUCCESS;
}