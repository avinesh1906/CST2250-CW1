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

int Live::booking()
{
    int seatToBeBooked = 0;
    std::cout <<"Theatre maximum capacity: " <<  maxCapacity << std::endl;
    std::cout << "Number of seats already booked" << availableSeat << std::endl;
    if (maxCapacity > availableSeat){
        std::cout << "You can proceed with booking " << std::endl;
        do {
            std::cout << std::endl << "How much seat to book? " << std::endl;
            std::cin >> seatToBeBooked;
            if ((availableSeat - seatToBeBooked) < 0) {
                std::cout << "Error. Maximum Seat Capacity reached." << std::endl;
            }
        } while ((availableSeat - seatToBeBooked) < 0);
        
    } else {
        std::cout << "No more seats available " << std::endl;
    }

    availableSeat -= seatToBeBooked;
    return availableSeat;
}

int Live::cancel()
{
    int seatsToCancel = 0;
    std::cout << "Number of seats already booked" << availableSeat << std::endl;
    if (availableSeat != maxCapacity){
        std::cout << "You can proceed with cancellation" << std::endl;
        do {
            std::cout << "How many booking to cancel? " << std::endl;
            std::cin >> seatsToCancel;
            if ((availableSeat + seatsToCancel) > maxCapacity){
                std::cout << "Error. Cannot proceed with cancellation" << std::endl;
            }

        } while ((availableSeat + seatsToCancel) > maxCapacity);
    } else {
        std::cout << "There is no booking to cancel" << std::endl;
    }
    availableSeat += seatsToCancel;
    return availableSeat;
}