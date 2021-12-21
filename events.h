#ifndef __EVENTS_H_
#define __EVENTS_H_

#include <string>
#include <vector>
#include "struct.h"

class Event {
    private:
        int id;

    protected:
        std::string name;
        int maxCapacity;
        int availableSeat;
    
    public:
        //explicit constructor
        Event(details* array);

        //deconstructor
        virtual ~Event();

        //member functions
        std::string description();
        std::string getName();

        //base class
        virtual void booking() = 0;
};

class Live : public Event {
    public:
        Live(details* array);
        void booking();
};

// class StandUp : public Event {
//     private:
//         std::vector <int> seatTrack;

//     public:
//         StandUp(details* array);
//         void booking();
// };

// class Film : public Event {
//     private:
//         std::string type;

//     public:
//         Film(details* array);
//         void booking();
// };

#endif