#include "events.h"
#include "live.h"

// Live class constructor
Live::Live(details* array) : Event(array)
{

}

Live::Live() : Event()
{

}

// Description for live events
std::string Live::description(){

   return getName() + " has " +  std::to_string(getAvailableSeat()) +  " available seats out of " + std::to_string(getMaxCapacity()) + " seats." ;

}

// Booking for live event
void Live::booking(int seatToBeBooked)
{
    setAvailableSeat(getAvailableSeat() - seatToBeBooked);
}

// cancel the live event
void Live::cancel(int seatsToCancel)
{
    // increase available seat
    setAvailableSeat(getAvailableSeat() + seatsToCancel);

}
