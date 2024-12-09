#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <string>

graph read_conflicts (const std::string & input_file_name);

void help(char * params[]);

std::pair<std::string,std::string>  read_names_of_files (int number_params, char * params[]);

#endif
