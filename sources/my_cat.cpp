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

unsigned int    error_handle(char *str)
{
	if (!str)
		return EXIT_FAILURE;
	else
	{
		std::cerr << "my_cat : " << str << " : No such file or directory" << std::endl;
        return EXIT_SUCCESS;
	}
}

std::fstream	open_files(char *file)
{
	std::fstream	fs_file;
	
	fs_file.open(file, std::fstream::in);
	return fs_file;
}

bool	is_open_files(std::fstream fs_file)
{
	if (fs_file.is_open())
	{
		std::cout << std::boolalpha << "DEBUG : " << fs_file.is_open() << std::endl;
		return fs_file.is_open();

	} else
	{
		std::cout << std::boolalpha << "DEBUG : " << fs_file.is_open() << std::endl;
		return fs_file.is_open();
	}
}
