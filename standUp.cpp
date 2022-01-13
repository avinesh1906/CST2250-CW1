/* 
    standUp.cpp
    Author: M00776456
    Created: 06/01/22
    Updated: 13/01/22
 */

#include "events.h"
#include "standUp.h"

#include <iostream>
#include <algorithm>

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

    if (seatTrack->size() != 0){
        std::cout << "Seats already booked: " << std::endl;
        // display the seat track 
        for (size_t i = 0; i < seatTrack->size() - 1; i++){
            std::cout << seatTrack->at(i) << ", ";
        }
        std::cout << seatTrack->at(seatTrack->size() -1 ) << std::endl;
    } else {
        std::cout << "No seat already booked" << std::endl;
    }
    // choose seat number to book
    for (int i = 1; i <= seatToBeBooked; i++){
        do {
            std::cout << "Enter seat number to be booked: ";
            std::cin >> seatNo;
            if (std::count(seatTrack->begin(), seatTrack->end(), seatNo)){
                std::cout << "Seat No " << seatNo << " already booked." 
                          << std::endl;
            } else if (seatNo < 1 || seatNo > 200) {
                std::cout << "Error. Choose a seat between 1 to 200 inclusive." 
                          << std::endl;
            }
        } while((std::count(seatTrack->begin(), seatTrack->end(), seatNo) 
                || (seatNo < 1 || seatNo > 200)));
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
    if (seatTrack->size() != 0){
        std::cout << "Seats already booked: " << std::endl;
        // display the seat track 
        for (size_t i = 0; i < seatTrack->size() - 1; i++){
            std::cout << seatTrack->at(i) << ", ";
        }
        std::cout << seatTrack->at(seatTrack->size() -1 ) << std::endl;
    } else {
        std::cout << "No seat already booked" << std::endl;
    }
    // choose seat number to cancel
    for (int i = 1; i <= seatsToCancel; i++){
        do {
            std::cout << "Enter seat number to be cancelled: ";
            std::cin >> seatNo;
            if (!std::count(seatTrack->begin(), seatTrack->end(), seatNo)){
                std::cout << "Seat No " << seatNo 
                          << " is not on the booking list." << std::endl;
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

    if (seatTrack->size() == 0){
        return getName() + " do not have any booked seat.\n" 
            + "A total of " + std::to_string(getAvailableSeat()) + 
            " available seats out of " + std::to_string(getMaxCapacity()) 
            + " seats. \n";
    } else {
        // print the seat track
        for (size_t i = 0; i < seatTrack->size() - 1; i++){
            returnString += std::to_string(seatTrack->at(i)) + ", ";
        }

        returnString += std::to_string(seatTrack->at(seatTrack->size() -1 ));
        return getName() + " has the following booked seats: \n" 
            + returnString + "\n" + "A total of " 
            + std::to_string(getAvailableSeat()) + " available seats out of " 
            + std::to_string(getMaxCapacity()) + " seats. \n";
    }
    
}