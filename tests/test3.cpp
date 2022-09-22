
#include "./include_test/test.hpp"

Test (string, default_value)
{
	std::string s;
	cr_assert_eq (s, "");
}

Test (string, assign)
{
	std::string s;

	s = "test";
	cr_assert_eq (s,"test");
}

Test (string, append)
{
	std::string s("test");

	s += "ing";
	cr_assert_eq (s ,"testing");
}

Test(errors, exit_code, .init=redirect_all_stdout)
{
        error();
        cr_assert_stderr_eq_str("error", "");
}


// Test(my_cat, result_test_param_av)
// {
// 	cr_assert_eq(my_cat(NULL), 0);
// }