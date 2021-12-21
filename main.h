#ifndef __MAIN_H_
#define __MAIN_H_

#include <string>
#include <vector>


struct details
{
    int id;
    std::string name;
    int seatCapacity;
    int availableSeat;
    std::vector <int> seatAllocated;
    std::string filmType;
};


/* 
    To display the main menu for the staff to choose between events and list all events' details.
    @param no parameter
    @return int
 */
int mainMenu();

/* 
    To display the menu for booking, refund or list details of a particular chosen event
    @param no parameter
    @return int    
 */

int menu();

/* 
    To add a booking or cancel booking and list details and availability for live event.
    @param liveDetails stores the details for live event
    @return void 
 */
void live(details* liveDetails);

/* 
    To add a booking or cancel booking and list details and availability for stand up event.
    @param no parameters
    @return void 
 */
void standUp();

/* 
    To add a booking or cancel booking and list details and availability for film event.
    @param no parameters
    @return void 
 */
void film();

/* 
    To list all events
    @param liveDetails, standUpDetails, filmDetails stores the current data for each events
    @return void
 */
void all(details liveDetails, details standUpDetails, details filmDetails);

/*
    To enter the details of a particular event into an array
    @param array stores the details of type struct and eventType is either live, standUp or film
    @return no return
 */
void enterDetails(details* array, std::string eventType);

/*
    To print the list of name of a particular event
    @param array stores the details of type struc
    @return no return
 */
void printName(details* array);

#endif