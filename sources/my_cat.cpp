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

unsigned int    	error_handle(char *str)
{
	if (!str)
		return EXIT_FAILURE;
	else
	{
		std::cerr << "my_cat : " << str << " : No such file or directory" << std::endl;
        return EXIT_SUCCESS;
	}
}

bool				open_files(std::fstream &fs_file, std::string file)
{	
	fs_file.open(file.data(), std::fstream::in);
	return fs_file.is_open();
}

void				command_cat(std::fstream &f_stream)
{
	std::string		buffer;
	char			delimiter;

	delimiter = '\0';	
	while (std::getline(f_stream, buffer, delimiter))
	{
		std::cout << buffer << std::endl << std::flush;
		f_stream.close();
	}
}