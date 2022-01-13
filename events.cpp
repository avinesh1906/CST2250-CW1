/* 
    events.cpp
    Author: M00776456
    Created: 20/12/21
    Updated: 13/01/22
 */

#include "events.h"
#include <string>

// constructor for Event class
Event::Event()
{

}

Event::Event(details* array)
{
    setRef(array->ref);
    setName(array->name);
    availableSeatPtr(&(array->availableSeat));
    setMaxCapacity(array->seatCapacity);
}

// Deconstructor for Event class
Event::~Event()
{

}

/* Setters */
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

/* getters */

int Event::getAvailableSeat(){
    return *(availableSeat);
}

std::string Event::getName(){
    return name;
}

int Event::getRef()
{
    return ref;
}

int Event::getMaxCapacity(){
    return maxCapacity;
}
