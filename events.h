#ifndef __EVENTS_H_
#define __EVENTS_H_

/* 
    events.h
    Author: M00776456
    Created: 20/12/21
    Updated: 13/01/22
 */

#include <string>
#include <vector>
#include "struct.h"

// Base class
class Event {
    private:
        int ref;
        std::string name;
        int maxCapacity;
        int* availableSeat;
    public:
        // constructor
        Event();
        //explicit constructor
        Event(details* array);

        //deconstructor
        virtual ~Event();

        // Setters and getters
        void setName(std::string name);
        std::string getName();

        void setRef(int ref);
        int getRef();

        void setMaxCapacity(int maxCapacity);
        int getMaxCapacity();

        void availableSeatPtr(int* availableseat);
        void setAvailableSeat(int availableSeat);
        int getAvailableSeat();

        // virtual functions
        virtual std::string description() = 0;
        virtual void booking(int seatToBeBooked) = 0;
        virtual void cancel(int seatsToCancel) = 0;
        
};

#endif