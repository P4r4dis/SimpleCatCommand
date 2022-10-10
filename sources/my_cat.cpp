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

bool	open_files(std::string &file)
{
	std::fstream	fs_file;
	
	fs_file.open(file.data(), std::fstream::in);
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

// bool	open_files2(std::fstream &fs_file, std::string &file)
// {
// 	fs_file.open(file.data(), std::fstream::in);
// 	std::cout << file << std::endl;
// 	if (fs_file.is_open())
// 	{
// 		std::cout << std::boolalpha << "DEBUG : " << fs_file.is_open() << std::endl;
// 		return fs_file.is_open();

// 	} else
// 	{
// 		std::cout << std::boolalpha << "DEBUG : " << fs_file.is_open() << std::endl;
// 		return fs_file.is_open();
// 	}
// }