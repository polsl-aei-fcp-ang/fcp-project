
#include <string>
#include <iostream>

#include "functions.h"
#include "structures.h"

int main (int number_params, char * params[])
{
    std::pair<std::string,std::string> input_output_names = read_names_of_files (number_params, params);
    // std::pair<std::string,std::string>  read_names_of_files (int number_params, char * params[]);

    // std::cout << "input file name:  " << input_output_names.first << std::endl;
    // std::cout << "output file name: " << input_output_names.second << std::endl;

    if (not input_output_names.first.empty() and not input_output_names.second.empty())
    {
        // OK
        graph conflicts = read_conflicts(input_output_names.first);
        // graph read_conflicts (const std::string & input_file_name);

        print(conflicts);
        // void print(const graph & g);

        colour_nodes(conflicts);
        // void colour_nodes(graph & g);
        print(conflicts);


        print_colours(conflicts, input_output_names.second);
        //  void print_colours (const graph & g, const std::string & output_file_name);
    }
    else
    {
      help(params);
      // void help(char * params[]);
    }

    return 0;
}
