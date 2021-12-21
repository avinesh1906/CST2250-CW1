#include "events.h"
#include <string>
#include <iostream>

Event::Event(details* array)
{
    this->name = array->name;
    this->availableSeat = array->availableSeat;
    this->maxCapacity = array->seatCapacity;
}

Event::~Event()
{

}

std::string Event::description(){
    return name + " has " +  std::to_string(availableSeat) +  " available seats";
}

std::string Event::getName(){
    return name;
}

Live::Live(details* array) : Event(array)
{
    
}

void Live::booking()
{
    int seatToBeBooked;
    std::cout << maxCapacity << std::endl;
    std::cout << availableSeat << std::endl;
    if (maxCapacity > availableSeat){
        std::cout << "You can book " << std::endl;
        do {
            std::cout << "How much seat to book? " << std::endl;
            std::cin >> seatToBeBooked;
            if ((availableSeat - seatToBeBooked) < 0) {
                std::cout << "Error. Maximum Seat Capacity reached." << std::endl;
            }
        } while ((availableSeat - seatToBeBooked) < 0);
        
    } else {
        std::cout << "No more seats available " << std::endl;
    }

    availableSeat -= seatToBeBooked;
    std::cout << availableSeat << std::endl;
    
}
