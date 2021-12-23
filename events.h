#ifndef __EVENTS_H_
#define __EVENTS_H_

#include <string>
#include <vector>
#include "struct.h"

class Event {
    private:
        int ref;
        std::string name;
        int maxCapacity;
    protected:
        int* availableSeat;
    
    public:
        //explicit constructor
        Event(details* array);

        //deconstructor
        virtual ~Event();

        //member functions
        virtual void description() = 0;
        std::string getName();
        int getRef();
        int getMaxCapacity();

        //base class
        virtual int booking() = 0;
        virtual int cancel() = 0;
        
};

class Live : public Event {
    public:
        Live(details* array);
        void description();
        int booking();
        int cancel();
};

class StandUp : public Event {
    private:
        std::vector <int> *seatTrack;

    public:
        StandUp(details* array);
        void description();
        int booking();
        int cancel();
        // void displaySeat();
        // void allocateSeat(int noOfBooking);
};

class Film : public Event {
    private:
        std::string type;

    public:
        Film(details* array);
        void description();
        int booking();
        int cancel();
        std::string getType();
        // std::string displayFilm();
};

#endif