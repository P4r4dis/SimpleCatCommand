#ifndef __TEST_HPP__
#   define __TEST_HPP__

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <criterion/logging.h>
#include <unistd.h>
#include <iostream>
#include <ostream>

void    redirect_all_stdout(void);
int     error(void);
int     check_params(unsigned int ac);



#endif // !__TEST_HPP__