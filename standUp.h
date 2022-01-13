#ifndef __STANDUP_H_
#define __STANDUP_H_

/* 
    standUp.h
    Author: M00776456
    Created: 06/01/22
    Updated: 13/01/22
 */

#include "events.h"
#include "struct.h"
#include <vector>

// StandUp class - Derived from event
class StandUp : public Event {
    private:
        std::vector <int> *seatTrack;

    public:
        StandUp();
        StandUp(details* array);

        void setSeatTrack(std::vector <int> *list);
        std::string  description();

        void booking(int seatToBeBooked);
        void seatToBook(int seatToBeBooked);

        void cancel(int seatsToCancel);
        void seatToUnbook(int seatsToCancelst);
};

#endif