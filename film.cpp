#include "events.h"
#include "film.h"

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
    +  std::to_string(getMaxCapacity()) + " seats. \n";

}

// return film type
std::string Film::getType()
{
    return type;
}