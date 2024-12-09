
#include <string>
#include <iostream>

#include "functions.h"

int main (int number_params, char * params[])
{
    std::pair<std::string,std::string> input_output_names = read_names_of_files (number_params, params);
    // std::pair<std::string,std::string>  read_names_of_files (int number_params, char * params[]);

    std::cout << "input file name:  " << input_output_names.first << std::endl;
    std::cout << "output file name: " << input_output_names.second << std::endl;

    // if (not input_output_names.first.empty() and not input_output_names.second.empty())
    // {
        // OK
        // graph conflicts = read_conflicts(input_output_names.first);
        // colour_nodes(conflicts);
        // print_colours(conflicts, input_output_names.second);

    // }
    // else
    // {
        // help();
    // }

    return 0;
}
