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
    protected:
        int* availableSeat;
    public:
        Event();
        //explicit constructor
        Event(details* array);
        //deconstructor
        virtual ~Event();

        //member functions
        virtual void description() = 0;

        void setName(std::string name);
        std::string getName();

        void setRef(int ref);
        int getRef();

        void setMaxCapacity(int maxCapacity);
        int getMaxCapacity();

        void setAvailableSeat(int* availableSeat);
        int getAvailableSeat();

        //base class
        virtual void booking() = 0;
        virtual void cancel() = 0;
        
};

// Live class - Derived from event
class Live : public Event {
    public:
        Live(details* array);
        Live();
        void description();
        void booking();
        void cancel();
};

// StandUp class - Derived from event
class StandUp : public Event {
    private:
        std::vector <int> *seatTrack;

    public:
        StandUp();
        StandUp(details* array);
        void description();
        void booking();
        void cancel();
};

// Film class - Derived from event
class Film : public Event {
    private:
        std::string type;

    public:
        Film();
        Film(details* array);
        void description();
        void booking();
        void cancel();
        std::string getType();
};

#endif