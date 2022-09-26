
#include "./include_test/test.hpp"
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

Test(errors, exit_code, .init=redirect_all_stdout)
{
	error();
	cr_assert_stderr_eq_str("error");
}


Test (check_if_no_params, result_is_null_params, .init=redirect_all_stdout)
{
	unsigned int ac = 1; // just binary without parameters as arguments

	check_if_no_params(ac);
	cr_assert_stderr_eq_str("my_cat : Usage : ./my_cat file [...]");
}
