#ifndef STRUCTURES_H 
#define STRUCTURES_H 

#include <vector>
#include <string>
#include <map>

struct graph
{
    struct node
    {
        unsigned int colour = 0;
        std::vector<std::string> neighbours;
    };

    std::map<std::string, node> nodes;
    unsigned number_of_colours = 0;
};

#endif
