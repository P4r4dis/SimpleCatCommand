#include "./include_test/test.hpp"
#include "../includes/my_cat.hpp"

Test (check_nb_params, result_with_null_param, .init=redirect_all_stdout)
{
	const unsigned int ac0 = 0; // just binary without parameters as arguments
	unsigned int result = check_nb_params(ac0); 

	cr_assert(ac0 < 2, "The ac result is %d, EXPECTED ac < 2", ac0);
	cr_assert_stderr_eq_str("my_cat : Usage : ./my_cat file [...]\n",
	"STDERR don't matches. EXPECTED : my_cat : Usage : ./my_cat file [...]\n");
	cr_assert(result == 1, "The result is %d, EXPECTED EXIT_FAILURE or %d", result, EXIT_FAILURE);
}

Test (check_nb_params, result_with_one_param, .init=redirect_all_stdout)
{
	const unsigned int ac1 = 1; 
	unsigned int result = check_nb_params(ac1);

	cr_assert(ac1 < 2, "The ac result is %d, EXPECTED ac < 2", ac1);
	cr_assert_stderr_eq_str("my_cat : Usage : ./my_cat file [...]\n",
	"STDERR don't matches. EXPECTED : my_cat : Usage : ./my_cat file [...]\n");
	cr_assert(result == 1, "The result is %d, EXPECTED EXIT_FAILURE or %d", result, EXIT_FAILURE);
}

Test (check_nb_params, result_with_params, .init=redirect_all_stdout)
{
	const unsigned int ac = 2; 
	unsigned int result = check_nb_params(ac);

	cr_assert(ac >= 2, "The ac result is %d, EXPECTED ac >= 2", ac);
	cr_assert_stderr_eq_str("", "STDERR don't matches. EXPECTED : (void)");
	cr_assert(result == 0, "The result is %d, EXPECTED EXIT_SUCCESS or %d", result, EXIT_SUCCESS);
}

Test (check_nb_params, result_with_several_params, .init=redirect_all_stdout)
{
	const unsigned int ac = 3; 
	unsigned int result = check_nb_params(ac);

	cr_assert(ac >= 2, "The ac result is %d, EXPECTED ac >= 2", ac);
	cr_assert_stderr_eq_str("", "STDERR don't matches. EXPECTED : (void)");
	cr_assert(result == 0,
	"The result is %d, EXPECTED EXIT_SUCCESS or %d", result, EXIT_SUCCESS);
}

Test (check_nb_params, result_with_several_params2, .init=redirect_all_stdout)
{
	const unsigned int ac = 5; 
	unsigned int result = check_nb_params(ac);

	cr_assert(ac >= 2, "The ac result is %d, EXPECTED ac >= 2", ac);
	cr_assert_stderr_eq_str("", "STDERR don't matches. EXPECTED : (void)");
	cr_assert(result == 0,
	"The result is %d, EXPECTED EXIT_SUCCESS or %d", result, EXIT_SUCCESS);
}
//////////////////////////////////////////////////////////////////////////////////

Test(error_handle, result_error_handle_with_file, .init=redirect_all_stdout)
{
	char				file[] = "File.txt";
	unsigned int		result = error_handle(file);

	cr_assert_stderr_eq_str("my_cat : File.txt : No such file or directory\n",
							"STDERR don't matches, EXPECTED :\nmy_cat : %s : No such file or directory\n",
							file);
	cr_assert(result == 0, "The result is %d, EXPECTED EXIT_SUCCESS or %d", result, EXIT_SUCCESS);

}

Test(error_handle, result_error_handle_without_file, .init=redirect_all_stdout)
{
	char				*file = nullptr;
	unsigned int		result = error_handle(file);

	cr_assert_stderr_eq_str("",
							"Output don't matches, none output is EXPECTED.",
							file);
	cr_assert(result == 1, "The result is %d, EXPECTED EXIT_FAILURE or %d", result, EXIT_FAILURE);
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

Test(open_files, result_file_not_open, .init = cr_redirect_stdout) {
	std::string 	file = "Makefiles";
	bool			result = is_open_files(open_files(file.data()));


	cr_assert(result == false,
			"FILE %s IS OPENED, The is result :\n%d or TRUE\n"
			"EXPECTED :\n0 or FALSE",
			file.data(),
			result);
}

Test(open_files, result_file_open, .init = cr_redirect_stdout)
{
	std::string 	file = "Makefile";
	bool			result = is_open_files(open_files(file.data()));

	cr_assert(result == true,
			"FILE %s NOT OPENED, The result is :\n%d or FALSE\n"
			"EXPECTED :\n1 or TRUE",
			file.data(),
			result);
}

Test(open_files, result_files_open, .init = cr_redirect_stdout)
{
	std::vector<std::string>	files = {"Makefile","tests/t.cpp"}; 
	bool						result;
	long unsigned int			i = 0;

	while (i < files.size())
	{
		result = is_open_files(open_files(files[i].data()));
		cr_assert(result == true,
		"FILE %s NOT OPENED, The result is :\n%d or FALSE\n"
		"EXPECTED :\n1 or TRUE",
		files[i].data(),
		result);
		i++;
	} 	
}
////////////////////////////////////////////////////////////////////////////
