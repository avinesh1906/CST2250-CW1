#ifndef __MAIN_H_
#define __MAIN_H_

/* 
    main.cpp
    Author: M00776456
    Created: 20/12/21
    Updated: 13/01/22
 */

#include <string>
#include <vector>
#include "events.h"
#include "struct.h"
#include "live.h"
#include "film.h"
#include "standUp.h"

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
    @param liveDetails stores the details of the chosen live event
 */
void live(Event* liveDetails);

/* 
    To add a booking or cancel booking and list details and availability for stand up event.
    @param standUpDetails stores the details of the chosen stand-up event
 */
void standUp(Event* standUpDetails);

/* 
    To add a booking or cancel booking and list details and availability for film event.
    @param filmDetails stores the details of the chosen film event
 */
void film(Event* filmDetails);

/*
    To load the file if already exist into a vector 
    @param no parameter
 */
void loadFile();

/*
    To print the list of name of a particular event
    @param array stores the details of type struc
 */
void printName(details* array);

/* 
    To add data to the file if doesn't exist
    @param no parameter
 */
void addData();

/* 
    To save data to the file when quit
    @param no parameter
 */
void saveData();

/* 
    To determine the size of the vector size 
    @param no parameter
 */
void determineSize();

/* 
    To add booking for an event
    @param details stores the details of the chosen event
 */
void booking(Event* details);

/* 
    To cancel booking for an event
    @param details stores the details of the chosen event
 */
void cancelBooking(Event* details);

/* 
    To display the shows of each event and make a choice
    @param vectorSize stores the size of the vector event
 */
void menuChoice(int vectorSize, details* event);

/* 
    To list details of all events\
    @param no parameter
 */
void listAll();

/* 
    To clear the heap memory and exit the program
    @param no parameter
 */
void quit();

#endif