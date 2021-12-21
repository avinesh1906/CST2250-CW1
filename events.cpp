#include "events.h"
#include <string>

Event::Event(details* array)
{
    this->id = array->id;
    this->name = array->name;
    this->maxCapacity = array->seatCapacity;
    this->availableSeat = array->availableSeat;

}

Event::~Event()
{

}

std::string Event::description(){
    return name + " has " +  std::to_string(availableSeat) +  " available seats and having a maximum capacity of "  + std::to_string(maxCapacity);
}

std::string Event::getName(){
    return name;
}

Live::Live(details* array) : Event(array)
{

}

void Live::booking()
{
    
}