#ifndef __MAIN_H_
#define __MAIN_H_

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
    @return void 
 */
void live(Event* liveDetails);

/* 
    To add a booking or cancel booking and list details and availability for stand up event.
    @param standUpDetails stores the details of the chosen stand-up event
    @return void 
 */
void standUp(Event* standUpDetails);

/* 
    To add a booking or cancel booking and list details and availability for film event.
    @param filmDetails stores the details of the chosen film event
    @return void 
 */
void film(Event* filmDetails);

/*
    To load the file if already exist into a vector 
    @param no parameter
    @return no return
 */
void loadFile();

/*
    To print the list of name of a particular event
    @param array stores the details of type struc
    @return no return
 */
void printName(details* array);

/* 
    To add data to the file if doesn't exist
    @param no parameter
    @return no return
 */
void addData();

/* 
    To save datat to the file when quit
    @param no parameter
    @return no return
 */
void saveData();

/* 
    To determine the size of the vector size 
    @param no parameter
    @return no return
 */
void determineSize();


void booking(Event* details);

void cancelBooking(Event* details);

#endif