#include "events.h"
#include "menu.h"
#include <iostream>

int main()
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
            all();
        } else if (option != 5) {
            std::cout << std::endl << "Invalid choice. Please enter 1,2,3 or 4" << std::endl;
        }
    } while (option != 5);

    std::cout << "Bye Bye" << std::endl;

    return 0;
}