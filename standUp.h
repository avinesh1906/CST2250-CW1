#include "events.h"

#include <vector>

// StandUp class - Derived from event
class StandUp : public Event {
    private:
        std::vector <int> *seatTrack;

    public:
        StandUp();
        StandUp(details* array);
        std::string  description();
        void booking(int seatToBeBooked);
        void cancel(int seatsToCancel);
        void setSeatTrack(std::vector <int> *list);
        void seatToBook(int seatToBeBooked);
        void seatToUnbook(int seatsToCancelst);
};
