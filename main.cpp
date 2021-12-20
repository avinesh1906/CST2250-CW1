#include "main.h"
#include "events.h"

#include <iostream>
#include <string>
#include <vector>

struct details
{
    int id;
    std::string name;
    std::string seatCapacity;
    std::string availableSeat;
    std::vector <int> seatAllocated;
};


int main()
{
    details liveDetails, standUpDetails, filmDetails;
    int option;

    // SHOULD USE dynamically allocated structure to read/save to a file (week7-lab5))

    liveDetails.id = 1; 
    liveDetails.name = "Live";
    liveDetails.seatCapacity = 300;
    liveDetails.availableSeat = 294;
    liveDetails.seatAllocated = {};

    standUpDetails.id = 2; 
    standUpDetails.name = "Stand Up";
    standUpDetails.seatCapacity = 200;
    standUpDetails.availableSeat = 194;
    standUpDetails.seatAllocated = {1, 2, 50, 121, 195,200};

    filmDetails.id = 3; 
    filmDetails.name = "Film";
    filmDetails.seatCapacity = 200;
    filmDetails.availableSeat = 175;
    filmDetails.seatAllocated = {};

    option = menu();
    if (option == 1) {
        std::cout << std::endl << "You choose Live event" << std::endl;
        // call function live
        live(); 
    } else if (option == 2) {
        std::cout << std::endl << "You choose Stand Up event" << std::endl;
        // call function standUp
        standUp(); 
    } else if (option == 3) {
        std::cout << std::endl << "You choose film event" << std::endl;
        // call function film
        film();
    } else if (option == 4) {
        std::cout << "List details of all events" << std::endl;
        // call function all
        all(liveDetails, standUpDetails, filmDetails);
    } else {
        std::cout << "Bye Bye" << std::endl;
        return 0;
    }

}

int menu()
{
    int option;
    do {
        std::cout << std::endl << "******** Main Menu ********" << std::endl;
        std::cout << "1: Live event" << std::endl;
        std::cout << "2. Stand Up" << std::endl;
        std::cout << "3. Film " << std::endl;
        std::cout << "4. List details for all events " << std::endl;
        std::cout << "5. Quit " << std::endl;
        std::cin >> option;

        if (option != 1 || option != 2 || option != 3 || option != 4 || option != 5 ) {
            std::cout << std::endl << "Invalid choice. Please enter 1,2,3,4 or 5" << std::endl;
        }

    } while (option != 5);

    return option;    
}   

void all(details liveDetails, details standUpDetails, details filmDetails)
{

}