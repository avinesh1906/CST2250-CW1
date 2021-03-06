/* 
    film.cpp
    Author: M00776456
    Created: 06/01/22
    Updated: 13/01/22
 */

#include "events.h"
#include "film.h"

// constructor
Film::Film() : Event()
{

}

Film::Film(details* array) : Event(array)
{
    setType(array->filmType);
}

// setter 
void Film::setType(std::string filmType)
{
    type = filmType; 
}

// return film type
std::string Film::getType()
{
    return type;
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
    return "Film " + getName() + " of film type " + getType() +
            " has " + std::to_string(getAvailableSeat()) + 
            " available seats out of " +  std::to_string(getMaxCapacity()) + 
            " seats.";

}
