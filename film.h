#ifndef __FILM_H_
#define __FILM_H_

/* 
    film.h
    Author: M00776456
    Created: 06/01/22
    Updated: 13/01/22
 */

#include "events.h"
#include "struct.h"

// Film class - Derived from event
class Film : public Event {
    private:
        std::string type;

    public:
        Film();
        Film(details* array);

        void setType(std::string filmType);
        std::string getType();
        
        std::string  description();
        void booking(int seatToBeBooked);
        void cancel(int seatsToCancel);
};

#endif