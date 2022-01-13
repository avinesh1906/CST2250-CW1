/* 
    live.cpp
    Author: M00776456
    Created: 06/01/22
    Updated: 13/01/22
 */

#include "live.h"
#include "events.h"

// Live class constructor
Live::Live() : Event()
{

}

Live::Live(details* array) : Event(array)
{

}

// Booking for live event
void Live::booking(int seatToBeBooked)
{
    setAvailableSeat(getAvailableSeat() - seatToBeBooked);
}

// cancel the live event
void Live::cancel(int seatsToCancel)
{
    setAvailableSeat(getAvailableSeat() + seatsToCancel);
}

// Description for live events
std::string Live::description(){

   return getName() + " has " +  std::to_string(getAvailableSeat()) 
        +  " available seats out of " + std::to_string(getMaxCapacity()) 
        + " seats." ;

}
