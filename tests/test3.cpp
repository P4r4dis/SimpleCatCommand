#include "./include_test/test.hpp"
#include <signal.h>
/* TEMPLATE:
Tests(functionName, comment[, options])
{
    [CODE]
}*/

// Test (string, default_value)
// {
// 	std::string s;
// 	cr_assert_eq (s, "");
// }

// Test (string, assign)
// {
// 	std::string s;

// 	s = "test";
// 	cr_assert_eq (s,"test");
// }

// Test (string, append)
// {
// 	std::string s("test");

// 	s += "ing";
// 	cr_assert_eq (s ,"testing");
// }

// Test(errors, exit_code, .init=redirect_all_stdout)
// {
// 	error();
// 	cr_assert_stderr_eq_str("error");
// }

// void setup(void) {
//     puts("Runs before the test");
// }

// void teardown(void) {
//     puts("Runs after the test");
// }

Test (check_params, result_with_null_param, .init=redirect_all_stdout)
{
	unsigned int ac0 = 0; // just binary without parameters as arguments
	unsigned int result = check_params(ac0); 

	cr_assert(ac0 < 2, "The ac result is %d, EXPECTED ac < 2", ac0);
	cr_assert_stderr_eq_str("my_cat : Usage : ./my_cat file [...]",
	"STDERR don't matches. EXPECTED : my_cat : Usage : ./my_cat file [...]");
	cr_assert(result == 1, "The result is %d, EXPECTED EXIT_FAILURE or %d", result, EXIT_FAILURE);
}

Test (check_params, result_with_one_param, .init=redirect_all_stdout)
{
	unsigned int ac1 = 1; 
	unsigned int result = check_params(ac1);

	cr_assert(ac1 < 2, "The ac result is %d, EXPECTED ac < 2", ac1);
	cr_assert_stderr_eq_str("my_cat : Usage : ./my_cat file [...]",
	"STDERR don't matches. EXPECTED : my_cat : Usage : ./my_cat file [...]");
	cr_assert(result == 1, "The result is %d, EXPECTED EXIT_FAILURE or %d", result, EXIT_FAILURE);
}

Test (check_params, result_with_params, .init=redirect_all_stdout)
{
	unsigned int ac = 2; 
	unsigned int result = check_params(ac);

	cr_assert(ac >= 2, "The ac result is %d, EXPECTED ac >= 2", ac);
	cr_assert_stderr_eq_str("", "STDERR don't matches. EXPECTED : (void)");
	cr_assert(result == 0, "The result is %d, EXPECTED EXIT_SUCCESS or %d", result, EXIT_SUCCESS);
}

Test (check_params, result_with_several_params, .init=redirect_all_stdout)
{
	unsigned int ac = 3; 
	unsigned int result = check_params(ac);

	cr_assert(ac >= 2, "The ac result is %d, EXPECTED ac >= 2", ac);
	cr_assert_stderr_eq_str("", "STDERR don't matches. EXPECTED : (void)");
	cr_assert(result == 0,
	"The result is %d, EXPECTED EXIT_SUCCESS or %d", result, EXIT_SUCCESS);
}

Test (check_params, result_with_several_params2, .init=redirect_all_stdout)
{
	unsigned int ac = 5; 
	unsigned int result = check_params(ac);

	cr_assert(ac >= 2, "The ac result is %d, EXPECTED ac >= 2", ac);
	cr_assert_stderr_eq_str("", "STDERR don't matches. EXPECTED : (void)");
	cr_assert(result == 0,
	"The result is %d, EXPECTED EXIT_SUCCESS or %d", result, EXIT_SUCCESS);
}