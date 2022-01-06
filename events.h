#ifndef __EVENTS_H_
#define __EVENTS_H_

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
        Event();
        //explicit constructor
        Event(details* array);
        //deconstructor
        virtual ~Event();

        //member functions
        virtual std::string description() = 0;

        void setName(std::string name);
        std::string getName();

        void setRef(int ref);
        int getRef();

        void setMaxCapacity(int maxCapacity);
        int getMaxCapacity();

        void availableSeatPtr(int* availableseat);
        void setAvailableSeat(int availableSeat);
        int getAvailableSeat();

        //base class
        virtual void booking(int seatToBeBooked) = 0;
        virtual void cancel(int seatsToCancel) = 0;
        
};


// Film class - Derived from event
class Film : public Event {
    private:
        std::string type;

    public:
        Film();
        Film(details* array);
        std::string  description();
        void booking(int seatToBeBooked);
        void cancel(int seatsToCancel);
        void setType(std::string filmType);
        std::string getType();
};

#endif