

#include "functions.h"

std::pair<std::string, std::string> read_names_of_files(int number_params, char * params[])
{
    if (number_params == 3)
    {
        std::string input_file_name {params[1]};
        std::string output_file_name {params[2]};

        return {input_file_name, output_file_name};
    }
    else
        return {};
}