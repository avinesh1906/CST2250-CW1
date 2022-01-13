#ifndef __STRUCT_H_
#define __STRUCT_H_

/* 
    struct.h
    Author: M00776456
    Created: 22/12/21
    Updated: 13/01/22
 */

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