
#include <iostream>
#include <fstream>

#include "functions.h"
#include "structures.h"

void print(const graph & g)
{
    for (const auto & [name, node_info] : g.nodes)   // vertex is a node, node is a vertex
    {
        std::cout << name << " (" << node_info.colour << ") : ";
        for (const auto & s : node_info.neighbours)
            std::cout << s << " ";
        std::cout << std::endl;
    }
}

graph read_conflicts(const std::string& input_file_name)
{
    graph result;

    std::ifstream file (input_file_name);

    std::string left, right;
    while (file >> left >> right)
    {
        result.nodes[left].neighbours.push_back(right);
        result.nodes[right].neighbours.push_back(left);
    }

    return result;
}


void help(char * params[])
{
    std::cout << "usage:" << std::endl;
    std::cout << params[0] << " input_file_name output_file_name" << std::endl;
}

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
