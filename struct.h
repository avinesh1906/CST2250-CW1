#ifndef __STRUCT_H_
#define __STRUCT_H_

#include <string>
#include <vector>

struct details
{
    int id;
    std::string name;
    int seatCapacity;
    int availableSeat;
    std::vector <int> seatAllocated;
    std::string filmType;
};

#endif