#include "events.h"
#include <string>

Event::Event(int id)
{
    this->id = id;
}

Event::~Event()
{

}

std::string Event::description(){
    return name + "has " +  std::to_string(availableSeat) +  " available seats and having a maximum capacity of "  + std::to_string(maxCapacity);
}

