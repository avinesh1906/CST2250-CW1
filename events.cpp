#include "events.h"
#include <string>
#include <iostream>
#include <algorithm>
#include <vector>

// constructor for Event class
Event::Event(details* array)
{
    setRef(array->ref);
    setName(array->name);
    setAvailableSeat(&(array->availableSeat));
    setMaxCapacity(array->seatCapacity);
}

void Event::setName(std::string Name)
{
    name = Name;
}

void Event::setRef(int Ref)
{
    ref = Ref;
}

void Event::setMaxCapacity(int capacity){
    maxCapacity = capacity;
}

void Event::setAvailableSeat(int* availableseat){
    availableSeat = availableseat;
}

int Event::getAvailableSeat(){
    return *(availableSeat);
}

Event::Event()
{

}

// Deconstructor for Event class
Event::~Event()
{

}

// get the name of the event
std::string Event::getName(){
    return name;
}

// get the reference of the event
int Event::getRef()
{
    return ref;
}

// get the maximum capacity of the event
int Event::getMaxCapacity(){
    return maxCapacity;
}

// Live class constructor
Live::Live(details* array) : Event(array)
{

}

Live::Live() : Event()
{

}

// Description for live events
void Live::description(){

    std::cout <<  getName() + " has " +  std::to_string(*(availableSeat)) +  " available seats out of " + std::to_string(getMaxCapacity()) + " seats." << std::endl;
    
}

// Booking for live event
void Live::booking()
{
    int seatToBeBooked = 0;
    std::cout <<"Theatre maximum capacity: " <<  getMaxCapacity() << std::endl;
    std::cout << "Number of seats available for booking: " << *(availableSeat) << std::endl;
    // check if available seat is less than maximum seating capacity
    if (getMaxCapacity() > *(availableSeat)){
        std::cout << "You can proceed with booking " << std::endl;
        do {
            std::cout << std::endl << "How much seat to book? " << std::endl;
            std::cin >> seatToBeBooked;
            if ((*(availableSeat) - seatToBeBooked) < 0) {
                std::cout << "Error. Maximum Seat Capacity reached." << std::endl;
            }
        } while ((*(availableSeat) - seatToBeBooked) < 0);
        
    } else {
        std::cout << "No more seats available " << std::endl;
    }
    // deduct the seat booked from available seat
    *(availableSeat) -= seatToBeBooked;

}

// cancel the live event
void Live::cancel()
{
    int seatsToCancel = 0;
    std::cout << "Number of seats already booked: " << (getMaxCapacity() - *(availableSeat)) << std::endl;
    if (*(availableSeat) != getMaxCapacity()){
        std::cout << "You can proceed with cancellation" << std::endl;
        do {
            std::cout << "How many booking to cancel? " << std::endl;
            std::cin >> seatsToCancel;
            if ((*(availableSeat) + seatsToCancel) > getMaxCapacity()){
                std::cout << "Error. Cannot proceed with cancellation" << std::endl;
            }

        } while ((*(availableSeat) + seatsToCancel) > getMaxCapacity());
    } else {
        std::cout << "There is no booking to cancel" << std::endl;
    }
    // increase available seat
    *(availableSeat) += seatsToCancel;

}

// StandUp event constructor
StandUp::StandUp(details* array) : Event(array)
{
    seatTrack = &(array->seatTrack);
}

StandUp::StandUp() : Event()
{

}

// book stand Up event
void StandUp::booking()
{

    int seatToBeBooked = 0;
    int seatNo;
    std::cout <<"Theatre maximum capacity: " <<  getMaxCapacity() << std::endl;
    std::cout << "Number of seats available for booking: " <<  *(availableSeat) << std::endl;
    std::cout << "Seats already booked: " << std::endl;
    // display the seat track 
    for (long unsigned int i = 0; i < seatTrack->size() - 1; i++){
        std::cout << seatTrack->at(i) << ", ";
    }
    std::cout << seatTrack->at(seatTrack->size() -1 ) << std::endl;
    if (getMaxCapacity() > *(availableSeat)){
        std::cout << "You can proceed with booking " << std::endl;
        do {
            std::cout << std::endl << "How much seat to book? " << std::endl;
            std::cin >> seatToBeBooked;
            if ((*(availableSeat) - seatToBeBooked) < 0) {
                std::cout << "Error. Maximum Seat Capacity reached." << std::endl;
            }
        } while ((*(availableSeat) - seatToBeBooked) < 0);
        
    } else {
        std::cout << "No more seats available " << std::endl;
    }
    
    // choose seat number to book
    for (int i = 1; i <= seatToBeBooked; i++){
        do {
            std::cout << "Enter seat number to be booked: ";
            std::cin >> seatNo;
            if (std::count(seatTrack->begin(), seatTrack->end(), seatNo)){
                std::cout << "Seat No " << seatNo << " already booked." << std::endl;
            }
        } while(std::count(seatTrack->begin(), seatTrack->end(), seatNo));
        seatTrack->push_back(seatNo);
    }

    // decrease available seat
    *(availableSeat) -= seatToBeBooked;

}

// cancel booking for standup event
void StandUp::cancel()
{
    int seatsToCancel = 0;
    int seatNo;
    std::cout << "Number of seats already booked: " << getMaxCapacity() - *(availableSeat) << std::endl;
    std::cout << "Seats already booked: " << std::endl;
    for (long unsigned int i = 0; i < seatTrack->size() - 1; i++){
        std::cout << seatTrack->at(i) << ", ";
    }
    std::cout << seatTrack->at(seatTrack->size() -1 ) << std::endl;
    if (*(availableSeat) != getMaxCapacity()){
        std::cout << "You can proceed with cancellation" << std::endl;
        do {
            std::cout << "How many booking to cancel? " << std::endl;
            std::cin >> seatsToCancel;
            if ((*(availableSeat) + seatsToCancel) > getMaxCapacity()){
                std::cout << "Error. Cannot proceed with cancellation" << std::endl;
            }

        } while ((*(availableSeat) + seatsToCancel) > getMaxCapacity());
    } else {
        std::cout << "There is no booking to cancel" << std::endl;
    }

    // choose seat number to cancel
    for (int i = 1; i <= seatsToCancel; i++){
        do {
            std::cout << "Enter seat number to be cancelled: ";
            std::cin >> seatNo;
            if (!std::count(seatTrack->begin(), seatTrack->end(), seatNo)){
                std::cout << "Seat No " << seatNo << " is not on the booking list." << std::endl;
            }
        } while(!std::count(seatTrack->begin(), seatTrack->end(), seatNo));
        
        // delete the seat from the vector
        for (long unsigned int i = 0; i < seatTrack->size(); i++){
            if (seatNo == seatTrack->at(i)){
                seatTrack->erase(seatTrack->begin() + i);
            }
        
        }   
    }

    *(availableSeat) += seatsToCancel;

}

// get description of the standUp event
void StandUp::description(){
    std::cout << getName() << " has the following booked seats: " << std::endl;
    // print the seat track
    for (long unsigned int i = 0; i < seatTrack->size() - 1; i++){
        std::cout << seatTrack->at(i) << ", ";
    }
    std::cout << seatTrack->at(seatTrack->size() -1 ) << std::endl;
    std::cout << "A total of " << *(availableSeat) << " available seats out of " << 
    getMaxCapacity() << " seats." << std::endl;
    
}

Film::Film(details* array) : Event(array)
{
    this->type = array->filmType;
}

Film::Film() : Event()
{

}

// booking for film event
void Film::booking()
{
    int seatToBeBooked = 0;
    std::cout <<"Theatre maximum capacity: " <<  getMaxCapacity() << std::endl;
    std::cout << "Number of seats available for booking: " <<  *(availableSeat) << std::endl;
    if (getMaxCapacity() > *(availableSeat)){
        std::cout << "You can proceed with booking " << std::endl;
        do {
            std::cout << std::endl << "How much seat to book? " << std::endl;
            std::cin >> seatToBeBooked;
            if ((*(availableSeat) - seatToBeBooked) < 0) {
                std::cout << "Error. Maximum Seat Capacity reached." << std::endl;
            }
        } while ((*(availableSeat) - seatToBeBooked) < 0);
        
    } else {
        std::cout << "No more seats available " << std::endl;
    }
    *(availableSeat) -= seatToBeBooked;

}

// cancel booking for film event
void Film::cancel()
{
    int seatsToCancel = 0;
    std::cout << "Number of seats already booked: " << getMaxCapacity() - *(availableSeat) << std::endl;
    if (*(availableSeat) != getMaxCapacity()){
        std::cout << "You can proceed with cancellation" << std::endl;
        do {
            std::cout << "How many booking to cancel? " << std::endl;
            std::cin >> seatsToCancel;
            if ((*(availableSeat) + seatsToCancel) > getMaxCapacity()){
                std::cout << "Error. Cannot proceed with cancellation" << std::endl;
            }

        } while ((*(availableSeat) + seatsToCancel) > getMaxCapacity());
    } else {
        std::cout << "There is no booking to cancel" << std::endl;
    }

    *(availableSeat) += seatsToCancel;

}

// desciption for film event
void Film::description()
{
    std::cout << "Film " << getName() << " of film type " 
    << getType() << " has " << *(availableSeat) << " available seats out of " 
    << getMaxCapacity() << " seats." << std::endl;

}

// return film type
std::string Film::getType()
{
    return type;
}