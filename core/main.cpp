#include "../includes/my_cat.hpp"



int main(int ac, char **av)
{
    if (check_nb_params(ac) == EXIT_FAILURE)
        return EXIT_FAILURE;
    if(av)
        error_handle(av[1]);
    std::cout << "RESULT AV = " << av[1] << std::endl;
    std::string test = "file1.txt";
    std::cout << "var test before .data() : " << test << std::endl;
    std::cout << "var test after .data() : " << test.data() << std::endl;
    
    std::string 	file = "Makefiles";
	std::fstream 	fs;
	bool			result;

	result = open_files(file);
    std::cout << std::boolalpha << result << "?" << std::endl;

    return 0;
}