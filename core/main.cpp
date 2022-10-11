#include "../includes/my_cat.hpp"



int main(int ac, char **av)
{
    if (check_nb_params(ac) == EXIT_FAILURE)
        return EXIT_FAILURE;
    // if(av)
    //     error_handle(av[1]);
    // std::cout << "RESULT AV = " << av[1] << std::endl;
    // std::string test = "file1.txt";
    // std::cout << "var test before .data() : " << test << std::endl;
    // std::cout << "var test after .data() : " << test.data() << std::endl;
    
    // std::vector<std::string>	files = {"file1.txt","file1.txt"}; 
	// std::string					buffer;
	// bool						result;
	// unsigned int				i;
	// std::fstream			f_stream;

	
	// i = 0;
	// while (i < files.size())
	// {
	// 	std::fstream			f_stream;

	// 	result = open_files(f_stream, files[i]);
	// 	std::cout << "result = " << std::boolalpha << result << std::endl;
	// 	if (f_stream.is_open())
	// 	{	
	// 		while (std::getline(f_stream, buffer, '\0')){
	// 			std::cout << buffer << std::flush;
	// 			// cr_assert_stdout_eq_str("test",
	// 			// "STDOUT don't matches. EXPECTED : <file content2>");
	// 		}
	// 	}
	// 	i++;
	// }

    
    bool    result;
    int i = 1;
    while (av[i])
    {
        std::fstream			f_stream;

		result = open_files(f_stream, av[i]);
    	if (result)
		{	
			command_cat(f_stream);
		}
        else
            error_handle(av[i]);
		i++;
		f_stream.close();    
    }
    return 0;
}