#ifndef __LIVE_H_
#define __LIVE_H_

/* 
    live.h
    Author: M00776456
    Created: 06/01/22
    Updated: 13/01/22
 */

#include "events.h"
#include "struct.h"

// Live class - Derived from event
class Live : public Event {
    public:
        Live(details* array);
        Live();
        
        std::string  description();
        void booking(int seatToBeBooked);
        void cancel(int seatsToCancel);
};

#endif