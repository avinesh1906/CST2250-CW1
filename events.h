#ifndef __EVENTS_H_
#define __EVENTS_H_

#include <string>
#include <vector>

class Event {
    private:
        int id;
        std::string name;
        int maxCapacity;
        int availableSeat;
    
    public:
        //explicit constructor
        Event(int id);

        //deconstructor
        virtual ~Event();

        //member functions
        std::string description();

        //base class
        virtual void booking() = 0;
};

class Live : public Event {
    public:
        void booking();
};

class StandUp : public Event {
    private:
        std::vector <int> seatTrack;

    public:
        void booking();
};

#endif