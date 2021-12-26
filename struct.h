#ifndef __STRUCT_H_
#define __STRUCT_H_

#include <string>
#include <vector>

// User defined datatype
struct details
{
    int ref;
    std::string name;
    int seatCapacity;
    int availableSeat;
    std::vector <int> seatTrack;
    std::string filmType;
};

#endif