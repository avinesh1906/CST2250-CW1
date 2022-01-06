#include "events.h"
#include <string>

#include "live.h"

// constructor for Event class
Event::Event(details* array)
{
    setRef(array->ref);
    setName(array->name);
    availableSeatPtr(&(array->availableSeat));
    setMaxCapacity(array->seatCapacity);
}

void Event::setName(std::string Name)
{
    name = Name;
}

void Event::setRef(int Ref)
{
    ref = Ref;
}

void Event::setMaxCapacity(int capacity){
    maxCapacity = capacity;
}

void Event::availableSeatPtr(int* seatPtr){
    availableSeat = seatPtr;
}

void Event::setAvailableSeat(int availableseat){
    *availableSeat = availableseat;
}

int Event::getAvailableSeat(){
    return *(availableSeat);
}

Event::Event()
{

}

// Deconstructor for Event class
Event::~Event()
{

}

// get the name of the event
std::string Event::getName(){
    return name;
}

// get the reference of the event
int Event::getRef()
{
    return ref;
}

// get the maximum capacity of the event
int Event::getMaxCapacity(){
    return maxCapacity;
}
