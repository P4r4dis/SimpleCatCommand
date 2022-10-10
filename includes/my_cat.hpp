#ifndef __MY_CAT_HPP__
#   define __MY_CAT_HPP__

#include <unistd.h>
#include <iostream>
#include <ostream>
#include <memory>
#include <fstream>
#include <utility>

unsigned int    check_nb_params(unsigned int ac);
unsigned int    error_handle(char *str);
bool	        open_files(std::string &file);

#endif // !__MY_CAT_HPP__