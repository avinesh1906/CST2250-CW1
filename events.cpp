#include "events.h"
#include <string>
#include <iostream>
#include <algorithm>
#include <vector>

Event::Event(details* array)
{
    this->ref = array->ref;
    this->name = array->name;
    this->availableSeat = &(array->availableSeat);
    this->maxCapacity = array->seatCapacity;
}

Event::~Event()
{

}

void Live::description(){

    std::cout <<  name + " has " +  std::to_string(*(availableSeat)) +  " available seats" << std::endl;
    
}

std::string Event::getName(){
    return name;
}

int Event::getRef()
{
    return ref;
}

Live::Live(details* array) : Event(array)
{

}

int Live::booking()
{
    int seatToBeBooked = 0;
    std::cout <<"Theatre maximum capacity: " <<  maxCapacity << std::endl;
    std::cout << "Number of seats available for booking:: " << *(availableSeat) << std::endl;
    if (maxCapacity > *(availableSeat)){
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
    return seatToBeBooked;
}

int Live::cancel()
{
    int seatsToCancel = 0;
    std::cout << "Number of seats already booked: " << (maxCapacity - *(availableSeat)) << std::endl;
    if (*(availableSeat) != maxCapacity){
        std::cout << "You can proceed with cancellation" << std::endl;
        do {
            std::cout << "How many booking to cancel? " << std::endl;
            std::cin >> seatsToCancel;
            if ((*(availableSeat) + seatsToCancel) > maxCapacity){
                std::cout << "Error. Cannot proceed with cancellation" << std::endl;
            }

        } while ((*(availableSeat) + seatsToCancel) > maxCapacity);
    } else {
        std::cout << "There is no booking to cancel" << std::endl;
    }

    *(availableSeat) += seatsToCancel;
    return seatsToCancel;
}

StandUp::StandUp(details* array) : Event(array)
{
    seatTrack = &(array->seatTrack);
}

int StandUp::booking()
{

    int seatToBeBooked = 0;
    int seatNo;
    std::cout <<"Theatre maximum capacity: " <<  maxCapacity << std::endl;
    std::cout << "Number of seats available for booking: " <<  *(availableSeat) << std::endl;
    std::cout << "Seats already booked: " << std::endl;
    for (int i = 0; i < seatTrack->size() - 1; i++){
        std::cout << seatTrack->at(i) << ", ";
    }
    std::cout << seatTrack->at(seatTrack->size() -1 ) << std::endl;
    if (maxCapacity > *(availableSeat)){
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

    *(availableSeat) -= seatToBeBooked;
    return seatToBeBooked;
}

int StandUp::cancel()
{
    int seatsToCancel = 0;
    int seatNo;
    std::cout << "Number of seats already booked: " << maxCapacity - *(availableSeat) << std::endl;
    std::cout << "Seats already booked: " << std::endl;
    for (int i = 0; i < seatTrack->size() - 1; i++){
        std::cout << seatTrack->at(i) << ", ";
    }
    std::cout << seatTrack->at(seatTrack->size() -1 ) << std::endl;
    if (*(availableSeat) != maxCapacity){
        std::cout << "You can proceed with cancellation" << std::endl;
        do {
            std::cout << "How many booking to cancel? " << std::endl;
            std::cin >> seatsToCancel;
            if ((*(availableSeat) + seatsToCancel) > maxCapacity){
                std::cout << "Error. Cannot proceed with cancellation" << std::endl;
            }

        } while ((*(availableSeat) + seatsToCancel) > maxCapacity);
    } else {
        std::cout << "There is no booking to cancel" << std::endl;
        return 1;
    }

    for (int i = 1; i <= seatsToCancel; i++){
        do {
            std::cout << "Enter seat number to be cancelled: ";
            std::cin >> seatNo;
            if (!std::count(seatTrack->begin(), seatTrack->end(), seatNo)){
                std::cout << "Seat No " << seatNo << " is not on the booking list." << std::endl;
            }
        } while(!std::count(seatTrack->begin(), seatTrack->end(), seatNo));
        
        for (int i = 0; i < seatTrack->size(); i++){
            if (seatNo == seatTrack->at(i)){
                seatTrack->erase(seatTrack->begin() + i);
            }
        
        }   
    }

    *(availableSeat) += seatsToCancel;
    return 0;
}

void StandUp::description(){
    std::cout << name << " has the following booked seats: " << std::endl;
    for (int i = 0; i < seatTrack->size() - 1; i++){
        std::cout << seatTrack->at(i) << ", ";
    }
    std::cout << seatTrack->at(seatTrack->size() -1 ) << std::endl;
    std::cout << "A total of " << *(availableSeat) << " available seats out of " << maxCapacity << " seats." << std::endl;
    
}

Film::Film(details* array) : Event(array)
{
    this->type = array->filmType;
}

int Film::booking()
{
    int seatToBeBooked = 0;
    std::cout <<"Theatre maximum capacity: " <<  maxCapacity << std::endl;
    std::cout << "Number of seats available for booking: " <<  *(availableSeat) << std::endl;
    if (maxCapacity > *(availableSeat)){
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
    return seatToBeBooked;
}

int Film::cancel()
{
    int seatsToCancel = 0;
    std::cout << "Number of seats already booked: " << maxCapacity - *(availableSeat) << std::endl;
    if (*(availableSeat) != maxCapacity){
        std::cout << "You can proceed with cancellation" << std::endl;
        do {
            std::cout << "How many booking to cancel? " << std::endl;
            std::cin >> seatsToCancel;
            if ((*(availableSeat) + seatsToCancel) > maxCapacity){
                std::cout << "Error. Cannot proceed with cancellation" << std::endl;
            }

        } while ((*(availableSeat) + seatsToCancel) > maxCapacity);
    } else {
        std::cout << "There is no booking to cancel" << std::endl;
    }

    *(availableSeat) += seatsToCancel;
    return seatsToCancel;
}

void Film::description()
{
    std::cout << "Film " << name << " of film type " 
    << type << " has " << *(availableSeat) << " available seats out of " 
    << maxCapacity << " seats." << std::endl;

}