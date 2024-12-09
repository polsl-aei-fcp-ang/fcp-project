
#include <iostream>
#include <fstream>

#include "functions.h"
#include "structures.h"

void colour_nodes(graph & g)
{
    auto number_of_nodes_without_colour = g.nodes.size();

    unsigned int colour = 0;
    while (number_of_nodes_without_colour > 0)
    {
        ++colour;
        for (auto & [name, node_info] : g.nodes)
        {
            auto node_colour = node_info.colour;
            if (node_colour == 0)
            {
                bool colouring_possible = true;
                for (const std::string & neighbour : node_info.neighbours)
                {
                    auto neighbour_colour = g.nodes[neighbour].colour;
                    if (neighbour_colour == colour)
                        colouring_possible = false;
                }
                if (colouring_possible)
                {
                    node_info.colour = colour;
                    --number_of_nodes_without_colour;
                }
            }
        }
    }
}

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
