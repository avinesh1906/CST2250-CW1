#include "menu.h"
#include "events.h"

#include <iostream>
#include <string>
#include <vector>

struct details
{
    int id;
    std::string name;
    std::string seatCapacity;
    std::string availableSeat;
    std::vector <int> seatAllocated;
};


int main()
{
    details liveDetails, standUpDetails, filmDetails;

    // SHOULD USE dynamically allocated structure to read/save to a file (week7-lab5))

    liveDetails.id = 1; 
    liveDetails.name = "Live";
    liveDetails.seatCapacity = 300;
    liveDetails.availableSeat = 294;
    liveDetails.seatAllocated = {};

    standUpDetails.id = 2; 
    standUpDetails.name = "Stand Up";
    standUpDetails.seatCapacity = 200;
    standUpDetails.availableSeat = 194;
    standUpDetails.seatAllocated = {1, 2, 50, 121, 195,200};

    filmDetails.id = 3; 
    filmDetails.name = "Film";
    filmDetails.seatCapacity = 200;
    filmDetails.availableSeat = 175;
    filmDetails.seatAllocated = {};

    
}
