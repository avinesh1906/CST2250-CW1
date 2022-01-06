#include "events.h"
#include <string>
#include <iostream>
#include <algorithm>
#include <vector>

#include "live.h"

// constructor for Event class
Event::Event(details* array)
{
    setRef(array->ref);
    setName(array->name);
    availableSeatPtr(&(array->availableSeat));
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

void Event::availableSeatPtr(int* seatPtr){
    availableSeat = seatPtr;
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

// StandUp event constructor
StandUp::StandUp(details* array) : Event(array)
{
    setSeatTrack(&(array->seatTrack));
}

StandUp::StandUp() : Event()
{

}

void StandUp::setSeatTrack(std::vector <int> *list)
{
    seatTrack = list;
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
std::string  StandUp::description(){
    std::string returnString = "";

    // print the seat track
    for (size_t i = 0; i < seatTrack->size() - 1; i++){
        returnString += std::to_string(seatTrack->at(i)) + ", ";
    }

    returnString += std::to_string(seatTrack->at(seatTrack->size() -1 ));
    return getName() + " has the following booked seats: \n" + returnString + "\n" 
    + "A total of " + std::to_string(getAvailableSeat()) + " available seats out of " 
    + std::to_string(getMaxCapacity()) + " seats. \n";
}

Film::Film(details* array) : Event(array)
{
    setType(array->filmType);
}

Film::Film() : Event()
{

}

void Film::setType(std::string filmType)
{
    type = filmType; 
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
std::string Film::description()
{
    return "Film " + getName() + " of film type " 
    + getType() + " has " + std::to_string(getAvailableSeat()) + " available seats out of " 
    +  std::to_string(getMaxCapacity()) + " seats.";

}

// return film type
std::string Film::getType()
{
    return type;
}