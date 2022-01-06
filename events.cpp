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

Film::Film(details* array) : Event(array)
{
    setType(array->filmType);
}

Film::Film() : Event()
{

}

void Film::setType(std::string filmType)
{
    type = filmType; 
}

// booking for film event
void Film::booking(int seatToBeBooked)
{
    setAvailableSeat(getAvailableSeat() - seatToBeBooked);

}

// cancel booking for film event
void Film::cancel(int seatsToCancel)
{
    setAvailableSeat(getAvailableSeat() + seatsToCancel);

}

// desciption for film event
std::string Film::description()
{
    return "Film " + getName() + " of film type " 
    + getType() + " has " + std::to_string(getAvailableSeat()) + " available seats out of " 
    +  std::to_string(getMaxCapacity()) + " seats.";

}

// return film type
std::string Film::getType()
{
    return type;
}