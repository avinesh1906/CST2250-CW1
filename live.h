#include "events.h"

// Live class - Derived from event
class Live : public Event {
    public:
        Live(details* array);
        Live();
        std::string  description();
        void booking(int seatToBeBooked);
        void cancel(int seatsToCancel);
};