#ifndef __MY_CAT_HPP__
#   define __MY_CAT_HPP__

#include <unistd.h>
#include <iostream>
#include <ostream>
#include <memory>
#include <fstream>

unsigned int    check_nb_params(unsigned int ac);
unsigned int    error_handle(char *str);
std::fstream    open_files(char *file);
bool	        is_open_files(std::fstream fs_file);

#endif // !__MY_CAT_HPP__