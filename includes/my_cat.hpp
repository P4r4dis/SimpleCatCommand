#ifndef __MY_CAT_HPP__
#   define __MY_CAT_HPP__

#include <unistd.h>
#include <iostream>
#include <ostream>
#include <memory>
#include <fstream>
#include <utility>
#include <vector>

unsigned int    check_nb_params(unsigned int ac);
unsigned int    error_handle(char *str);
bool	        open_files(std::fstream &fs_file, std::string file);
void        	command_cat(std::fstream &f_stream);
bool			close_files(std::fstream &fs_file);


#endif // !__MY_CAT_HPP__