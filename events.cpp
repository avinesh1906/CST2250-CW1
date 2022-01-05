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
    availableSeat = &(array->availableSeat);
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

void Event::setAvailableSeat(int availableseat){
    *availableSeat = availableseat;
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

    std::cout <<  getName() + " has " +  std::to_string(getAvailableSeat()) +  " available seats out of " + std::to_string(getMaxCapacity()) + " seats." << std::endl;
    
}

// Booking for live event
void Live::booking(int seatToBeBooked)
{
    setAvailableSeat(getAvailableSeat() - seatToBeBooked);
}

// cancel the live event
void Live::cancel(int seatsToCancel)
{
    // increase available seat
    setAvailableSeat(getAvailableSeat() + seatsToCancel);

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
void StandUp::booking(int seatToBeBooked)
{
    // decrease available seat
    setAvailableSeat(getAvailableSeat() - seatToBeBooked);
    seatToBook(seatToBeBooked);

}


void StandUp::seatToBook(int seatToBeBooked)
{   
    int seatNo;
    std::cout << "Seats already booked: " << std::endl;
    // display the seat track 
    for (size_t i = 0; i < seatTrack->size() - 1; i++){
        std::cout << seatTrack->at(i) << ", ";
    }
    std::cout << seatTrack->at(seatTrack->size() -1 ) << std::endl;

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
}

// cancel booking for standup event
void StandUp::cancel(int seatsToCancel)
{
    setAvailableSeat(getAvailableSeat() + seatsToCancel);
    seatToUnbook(seatsToCancel);
}

void StandUp::seatToUnbook(int seatsToCancel)
{
    int seatNo;
    std::cout << "Seats already booked: " << std::endl;
    for (long unsigned int i = 0; i < seatTrack->size() - 1; i++){
        std::cout << seatTrack->at(i) << ", ";
    }
    std::cout << seatTrack->at(seatTrack->size() -1 ) << std::endl;
    
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
        for (size_t i = 0; i < seatTrack->size(); i++){
            if (seatNo == seatTrack->at(i)){
                seatTrack->erase(seatTrack->begin() + i);
            }
        
        }   
    }

}

// get description of the standUp event
void StandUp::description(){
    std::cout << getName() << " has the following booked seats: " << std::endl;
    // print the seat track
    for (long unsigned int i = 0; i < seatTrack->size() - 1; i++){
        std::cout << seatTrack->at(i) << ", ";
    }
    std::cout << seatTrack->at(seatTrack->size() -1 ) << std::endl;
    std::cout << "A total of " << getAvailableSeat() << " available seats out of " << 
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
void Film::booking(int seatToBeBooked)
{
    setAvailableSeat(getAvailableSeat() - seatToBeBooked);

}

// cancel booking for film event
void Film::cancel(int seatsToCancel)
{
    setAvailableSeat(getAvailableSeat() + seatsToCancel);

}

// desciption for film event
void Film::description()
{
    std::cout << "Film " << getName() << " of film type " 
    << getType() << " has " << getAvailableSeat() << " available seats out of " 
    << getMaxCapacity() << " seats." << std::endl;

}

// return film type
std::string Film::getType()
{
    return type;
}