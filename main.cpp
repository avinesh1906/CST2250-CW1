#include "main.h"
#include "events.h"

#include <iostream>
#include <string>
#include <vector>


int liveSize = 2;
int standUpSize = 2;
details* liveEvent = new details[liveSize];
details* standUpEvent = new details[standUpSize];
int main()
{
    // details liveDetails, standUpDetails, filmDetails;
    int option;
    int eventMenuChoice;
    int eventChoice;
    // SHOULD USE dynamically allocated structure to read/save to a file (week7-lab5))
    
    // dynamically allocated array
    
    

    // for (int i = 0; i < liveSize; i++){
    //     // pass array by reference
    //     enterDetails(&liveEvent[i], "live");
    // }

    liveEvent[0].name = "Komiko";
    liveEvent[0].availableSeat = 294;
    liveEvent[0].seatCapacity = 300;

    liveEvent[1].name = "Mr Bean";
    liveEvent[1].availableSeat = 150;
    liveEvent[1].seatCapacity = 300;

    standUpEvent[0].name = "90 Favelas";
    standUpEvent[0].availableSeat = 195;
    standUpEvent[0].seatCapacity = 200;
    standUpEvent[0].seatTrack = {1,50,150,25,15};

    standUpEvent[1].name = "DSP Music";
    standUpEvent[1].availableSeat = 197;
    standUpEvent[1].seatCapacity = 200;
    standUpEvent[1].seatTrack = {1,75,126};

    mainMenu();


}

int mainMenu()
{
    int option;
    int eventMenuChoice;
    int eventChoice;
    std::vector <Event*> events;
    do {
        std::cout << std::endl << "******** Main Menu ********" << std::endl;
        std::cout << "1: Live event" << std::endl;
        std::cout << "2. Stand Up" << std::endl;
        std::cout << "3. Film " << std::endl;
        std::cout << "4. List details for all events " << std::endl;
        std::cout << "5. Quit " << std::endl;
        std::cout << std::endl << "Enter your choice: " ;
        std::cin >> option;

        if (option == 1) {    
            std::cout << std::endl << "******** Live Event ********" << std::endl;      
            for (int i = 0; i < liveSize; i++){
                std::cout << (i+1) << ": ";
                printName(&liveEvent[i]);
            }
            std::cout << "Choose your event: ";

            do {
                std::cin >> eventChoice;

                if (eventChoice < 1 && eventChoice > liveSize) {
                    std::cout << "Invalid choice.";
                }
            } while (eventChoice < 1 && eventChoice > liveSize);

            events.push_back(new Live(&liveEvent[eventChoice - 1]));
            // call function live
            live(events[0], &liveEvent[eventChoice - 1]); 

        } else if (option == 2) {
            std::cout << std::endl << "******** Live Event ********" << std::endl;      
            for (int i = 0; i < standUpSize; i++){
                std::cout << (i+1) << ": ";
                printName(&standUpEvent[i]);
            }
            std::cout << "Choose your event: ";

            do {
                std::cin >> eventChoice;

                if (eventChoice < 1 && eventChoice > standUpSize) {
                    std::cout << "Invalid choice.";
                }
            } while (eventChoice < 1 && eventChoice > standUpSize);

            events.push_back(new StandUp(&standUpEvent[eventChoice - 1]));
            standUp(events[0], &standUpEvent[eventChoice - 1]);
        } else if (option == 3) {
            std::cout << std::endl << "You choose film event" << std::endl;
            // call function film
            // film();
        } else if (option == 4) {
            std::cout << std::endl << "List details for all events" << std::endl;
            // call function all
            // all(liveDetails, standUpDetails, filmDetails);
        } else {
            std::cout << "Bye Bye" << std::endl;
            delete[] liveEvent;
            return 0;
        }

            if (option <= 1 && option >= 5 ) {
                std::cout << std::endl << "Invalid choice. Please enter 1,2,3,4 or 5" << std::endl;
            }

    } while (option <= 1 && option >= 5);

    return option;    
}   

void all(details liveDetails, details standUpDetails, details filmDetails)
{
    std::cout << std::endl << "******** Live Event ********" << std::endl;
    std::cout << "The seat capacity is: " << liveDetails.seatCapacity << std::endl;
    std::cout << "Seats Available: " << liveDetails.availableSeat << std::endl;

    std::cout << std::endl << "******** Stand Up Event ********" << std::endl;
    std::cout << "The seat capacity is: " << standUpDetails.seatCapacity << std::endl;
    std::cout << "Seats Available: " << standUpDetails.availableSeat << std::endl;
    std::cout << "Seats already allocated are as follows: " << std::endl;
    for (int n: standUpDetails.seatTrack ){
        std::cout << n << std::endl;
    }

    std::cout << std::endl << "******** Film Event ********" << std::endl;
    std::cout << "The seat capacity is: " << liveDetails.seatCapacity << std::endl;
    std::cout << "Seats Available: " << liveDetails.availableSeat << std::endl;

}

int menu(){
    int option;
    do {
        std::cout << std::endl << "******** Menu ********" << std::endl;
        std::cout << "1: Booking" << std::endl;
        std::cout << "2. Cancel Booking" << std::endl;
        std::cout << "3. List Details " << std::endl;
        std::cout << "4. Back to menu " << std::endl;
        std::cout << std::endl << "Enter your choice: " << std::endl;
        std::cin >> option;

        if (option <= 1 && option >= 4) {
            std::cout << std::endl << "Invalid choice. Please enter 1,2,3 or 4 " << std::endl;
        }

    } while (option <= 1 && option >= 4);

    return option;    
}

void live(Event* liveDetails, details* array)
{   
    std::cout << "You choose: " << liveDetails->getName() << std::endl;
    int option = menu();

    if (option == 1) {
        std::cout << std::endl << "Booking for Live Event" << std::endl;
        liveDetails->booking();

    } else if (option == 2){
        std::cout << std::endl << "Cancel/Refund Booking" << std::endl;
        liveDetails->cancel();

    } else if (option == 3){
        std::cout << std::endl << "List details and availability for Live Event" << std::endl;
        std::cout << liveDetails->description();
    } else {
        main();
    }

    mainMenu();
}

void standUp(Event* standUpDetails, details* array)
{
    std::cout << "You choose: " << standUpDetails->getName() << std::endl;
    int option = menu();
    int noOfBooking;
    if (option == 1) {
        std::cout << std::endl << "Booking for Standing Event" << std::endl;
        standUpDetails->booking();

    } else if (option == 2){
        std::cout << std::endl << "Cancel/Refund Booking" << std::endl;
    
    } else if (option == 3){
        std::cout << std::endl << "List details and availability for Standing Event" << std::endl;

    } else {
        main();
    }
    mainMenu();
}

void film(details liveDetails)
{
    int option = 0;

    if (option == 1) {
        std::cout << std::endl << "Booking for Film Event" << std::endl;
        
    } else if (option == 2){
        std::cout << std::endl << "Cancel/Refund Booking" << std::endl;
    
    } else if (option == 3){
        std::cout << std::endl << "List details and availability for Film Event" << std::endl;
    } else {
        main();
    }
}

void enterDetails(details* array, std::string eventType){
    if (eventType == "live"){
        array->id = 1;
        array->name = "Komiko";
        array->availableSeat = 294;
        array->seatCapacity = 300;
    }
}

void printName(details* array){
    std::cout << array->name << std::endl;
}