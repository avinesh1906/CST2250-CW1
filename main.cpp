#include "main.h"
#include "events.h"

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <bits/stdc++.h>

const std::string FILENAME = "file.txt";

int liveSize;
int standUpSize;
int filmSize;
details* liveEvent;
details* standUpEvent;
details* filmEvent;

int main()
{
    determineSize();
    liveEvent = new details[liveSize];
    standUpEvent = new details[standUpSize];
    filmEvent = new details[filmSize];

    try{
        std::ifstream myFile(FILENAME);
        if(myFile.fail()){
            throw 404;
        } else{
            loadFile();
        }
        
    } 
    catch (...) {
        addData();
    }
    mainMenu();


}

int mainMenu()
{
    int option;
    int eventMenuChoice;
    int eventChoice;
    std::vector <Event*> events;

    for (int i = 0; i < liveSize; i++){
        events.push_back(new Live(&liveEvent[i]));
    }
    for (int i = 0; i < standUpSize; i++){
        events.push_back(new StandUp(&standUpEvent[i]));
    }
    for (int i = 0; i < filmSize; i++){
        events.push_back(new Film(&filmEvent[i]));
    }

    for (int i = 0; i < standUpSize; i++){
        sort(standUpEvent[i].seatTrack.begin(),standUpEvent[i].seatTrack.end());
    }

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

            Event* liveClass = new Live(&liveEvent[eventChoice - 1]);
            live(liveClass);
        } else if (option == 2) {
            std::cout << std::endl << "******** StandUp Event ********" << std::endl;      
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

            Event* standUP = new StandUp(&standUpEvent[eventChoice - 1]);
            standUp(standUP);
        } else if (option == 3) {
            std::cout << std::endl << "******** Film Event ********" << std::endl;      
            for (int i = 0; i < filmSize; i++){
                std::cout << (i+1) << ": ";
                printName(&filmEvent[i]);
            }
            std::cout << "Choose your event: ";

            do {
                std::cin >> eventChoice;

                if (eventChoice < 1 && eventChoice > filmSize) {
                    std::cout << "Invalid choice.";
                }
            } while (eventChoice < 1 && eventChoice > filmSize);

            Event* filmFunction = new Film(&filmEvent[eventChoice - 1]);
            // call function live
            film(filmFunction); 
        } else if (option == 4) {
            std::cout << std::endl << "List details for all events" << std::endl;
            int ref = 1;
            for(unsigned i = 0; i < events.size(); i++){
                if (ref == events[i]->getRef()){
                    events[i]->description() ;
                } else {
                    std::cout << std::endl;
                    events[i]->description() ;
                    ref = events[i]->getRef();
                }   
            }
            mainMenu();
        } else {
            std::cout << "Bye Bye" << std::endl;
            
            saveData();

            for (Event* e: events){
                delete e;
            }

            events.clear();

            delete[] liveEvent;
            delete[] standUpEvent;
            delete[] filmEvent;

            liveEvent, standUpEvent, filmEvent = NULL;

            return 0;
        }
        if (option <= 1 && option >= 5 ) {
            std::cout << std::endl << "Invalid choice. Please enter 1,2,3,4 or 5" << std::endl;
        }

    } while (option <= 1 && option >= 5);

    return option;    
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

void live(Event* liveDetails)
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
        liveDetails->description();
    } else {
        main();
    }

    mainMenu();
}

void standUp(Event* standUpDetails)
{
    std::cout << "You choose: " << standUpDetails->getName() << std::endl;
    int option = menu();
    int noOfBooking;
    if (option == 1) {
        std::cout << std::endl << "Booking for Standing Event" << std::endl;
        standUpDetails->booking();

    } else if (option == 2){
        std::cout << std::endl << "Cancel/Refund Booking" << std::endl;
        standUpDetails->cancel();
    } else if (option == 3){
        std::cout << std::endl << "List details and availability for Standing Event" << std::endl;
        standUpDetails->description();
    } else {
        main();
    }
    mainMenu();
}

void film(Event* filmDetails)
{
    std::cout << "You choose: " << filmDetails->getName() << std::endl;
    int option = menu();

    if (option == 1) {
        std::cout << std::endl << "Booking for film Event" << std::endl;
        filmDetails->booking();

    } else if (option == 2){
        std::cout << std::endl << "Cancel/Refund Booking" << std::endl;
        filmDetails->cancel();

    } else if (option == 3){
        std::cout << std::endl << "List details and availability for film Event" << std::endl;
        filmDetails->description();
    } else {
        main();
    }

    mainMenu();
}

void loadFile(){
    std::cout << liveSize << " " << standUpSize << " " << filmSize << std::endl;
    std::ifstream myFile(FILENAME);
    std::string myText;
    int count = 0;
    int ref;
    int tmpRef = 1;
   while (std::getline(myFile, myText)){

        if (myText.find("Ref: ") != std::string::npos){
            ref = std::stoi(myText.substr(myText.find("Ref: ") + 5));
        }
        
        if(ref != tmpRef){
            count = 0;
            tmpRef = ref;
        }
        
        if (ref == 1){
            liveEvent[count].ref = ref;
            if (myText.find("Name: ") != std::string::npos){
                liveEvent[count].name = (myText.substr(myText.find("Name: ") + 6)); 
            }
            if (myText.find("SeatCapacity: ") != std::string::npos){
                liveEvent[count].seatCapacity = std::stoi(myText.substr(myText.find("SeatCapacity: ") + 14));
            }
            if (myText.find("AvailableSeat: ") != std::string::npos){
                liveEvent[count].availableSeat = std::stoi(myText.substr(myText.find("AvailableSeat: ") + 15));
            }
        } else if (ref == 2){
            standUpEvent[count].ref = ref;
            if (myText.find("Name: ") != std::string::npos){
                standUpEvent[count].name = (myText.substr(myText.find("Name: ") + 6));
            }
            if (myText.find("SeatCapacity: ") != std::string::npos){
                standUpEvent[count].seatCapacity = std::stoi(myText.substr(myText.find("SeatCapacity: ") + 14));
            }
            if (myText.find("AvailableSeat: ") != std::string::npos){
                standUpEvent[count].availableSeat = std::stoi(myText.substr(myText.find("AvailableSeat: ") + 15));
            }
            if (myText.find("SeatTrack: ") != std::string::npos){
                int tmpTrack = std::stoi(myText.substr(myText.find("SeatTrack: ") + 11));
                standUpEvent[count].seatTrack.push_back(tmpTrack);
            }
        } else if (ref == 3){
            filmEvent[count].ref = ref;
            if (myText.find("Name: ") != std::string::npos){
                filmEvent[count].name = (myText.substr(myText.find("Name: ") + 6));
            }
            if (myText.find("AvailableSeat: ") != std::string::npos){
                filmEvent[count].availableSeat = std::stoi(myText.substr(myText.find("AvailableSeat: ") + 15));
            }
            if (myText.find("SeatCapacity: ") != std::string::npos){
                filmEvent[count].seatCapacity = std::stoi(myText.substr(myText.find("SeatCapacity: ") + 14));
            }
            if (myText.find("FilmType: ") != std::string::npos){
                filmEvent[count].filmType = (myText.substr(myText.find("FilmType: ") + 10));
            }
        } 
        if (myText.empty()){
            count += 1;
        }
    }
    myFile.close();
}

void addData(){
    std::cout << "Adding" << std::endl;
    std::ofstream MyFile(FILENAME);

    liveEvent[0].ref = 1;
    liveEvent[0].name = "TomorrowIsland";
    liveEvent[0].availableSeat = 294;
    liveEvent[0].seatCapacity = 300;

    liveEvent[1].ref = 1;
    liveEvent[1].name = "Major Lazer";
    liveEvent[1].availableSeat = 150;
    liveEvent[1].seatCapacity = 300;

    liveEvent[2].ref = 1;
    liveEvent[2].name = "Artbat";
    liveEvent[2].availableSeat = 50;
    liveEvent[2].seatCapacity = 300;

    standUpEvent[0].ref = 2;
    standUpEvent[0].name = "Komiko";
    standUpEvent[0].availableSeat = 195;
    standUpEvent[0].seatCapacity = 200;
    standUpEvent[0].seatTrack = {1,15,25,50,150};

    standUpEvent[1].ref = 2;
    standUpEvent[1].name = "Comedy Show";
    standUpEvent[1].availableSeat = 197;
    standUpEvent[1].seatCapacity = 200;
    standUpEvent[1].seatTrack = {1,75,126};

    filmEvent[0].ref = 3;
    filmEvent[0].name = "Spiderman: Work From Home";
    filmEvent[0].availableSeat = 75;
    filmEvent[0].seatCapacity = 200;
    filmEvent[0].filmType = "3D";

    filmEvent[1].ref = 3;
    filmEvent[1].name = "Avengers: Age of Covid";
    filmEvent[1].availableSeat = 50;
    filmEvent[1].seatCapacity = 200;
    filmEvent[1].filmType = "2D";
    
    
    for (int i = 0; i < liveSize; i++){
        MyFile << "Ref: " << liveEvent[i].ref << "\n";
        MyFile << "Name: " << liveEvent[i].name << "\n";
        MyFile << "SeatCapacity: " << liveEvent[i].seatCapacity << "\n";
        MyFile << "AvailableSeat: " << liveEvent[i].availableSeat << "\n";
        MyFile << "\n";
    }

    for (int i = 0; i < standUpSize; i++){
        MyFile << "Ref: " << standUpEvent[i].ref << "\n";
        MyFile << "Name: " << standUpEvent[i].name << "\n";
        MyFile << "SeatCapacity: " << standUpEvent[i].seatCapacity << "\n";
        MyFile << "AvailableSeat: " << standUpEvent[i].availableSeat << "\n";
        for (int j = 0; j < standUpEvent[i].seatTrack.size(); j++){
            MyFile << "SeatTrack: " << standUpEvent[i].seatTrack[j] << "\n";
        }
        MyFile << "\n";
    }

    for (int i = 0; i < filmSize; i++){
        MyFile << "Ref: " << filmEvent[i].ref << "\n";
        MyFile << "Name: " << filmEvent[i].name << "\n";
        MyFile << "SeatCapacity: " << filmEvent[i].seatCapacity << "\n";
        MyFile << "AvailableSeat: " << filmEvent[i].availableSeat << "\n";
        MyFile << "FilmType: " << filmEvent[i].filmType << "\n";
        MyFile << "\n";
    }
    MyFile.close();
}

void printName(details* array){
    std::cout << array->name << std::endl;
}

void saveData()
{
    std::ofstream MyFile(FILENAME, std::ofstream::trunc);
    for (int i = 0; i < liveSize; i++){
        MyFile << "Ref: " << liveEvent[i].ref << "\n";
        MyFile << "Name: " << liveEvent[i].name << "\n";
        MyFile << "SeatCapacity: " << liveEvent[i].seatCapacity << "\n";
        MyFile << "AvailableSeat: " << liveEvent[i].availableSeat << "\n";
        MyFile << "\n";
    }

    for (int i = 0; i < standUpSize; i++){
        MyFile << "Ref: " << standUpEvent[i].ref << "\n";
        MyFile << "Name: " << standUpEvent[i].name << "\n";
        MyFile << "SeatCapacity: " << standUpEvent[i].seatCapacity << "\n";
        MyFile << "AvailableSeat: " << standUpEvent[i].availableSeat << "\n";
        for (int j = 0; j < standUpEvent[i].seatTrack.size(); j++){
            MyFile << "SeatTrack: " << standUpEvent[i].seatTrack[j] << "\n";
        }
        MyFile << "\n";
    }

    for (int i = 0; i < filmSize; i++){
        MyFile << "Ref: " << filmEvent[i].ref << "\n";
        MyFile << "Name: " << filmEvent[i].name << "\n";
        MyFile << "SeatCapacity: " << filmEvent[i].seatCapacity << "\n";
        MyFile << "AvailableSeat: " << filmEvent[i].availableSeat << "\n";
        MyFile << "FilmType: " << filmEvent[i].filmType << "\n";
        MyFile << "\n";
    }

    MyFile.close();
}

void determineSize()
{
    liveSize = 0;
    standUpSize = 0;
    filmSize = 0;
    std::ifstream myFile(FILENAME);
    int ref;
    std::string myText;
   while (std::getline(myFile, myText)){
        if (myText.find("Ref: ") != std::string::npos){
            ref = std::stoi(myText.substr(myText.find("Ref: ") + 5));
            if (ref == 1){
                liveSize += 1;
            } else if (ref == 2){
                standUpSize += 1;    
            } else if (ref == 3){
                filmSize += 1;
            } 
        }
    }
    
    myFile.close();
}