#ifndef __FILM_H_
#define __FILM_H_

#include "events.h"
#include "struct.h"

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