#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <string>
#include "structures.h"

void print_colours (const graph & g, const std::string & output_file_name);

void colour_nodes(graph & g);

void print(const graph & g);

graph read_conflicts (const std::string & input_file_name);

void help(char * params[]);

std::pair<std::string,std::string>  read_names_of_files (int number_params, char * params[]);

#endif
