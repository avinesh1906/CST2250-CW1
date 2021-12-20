#include "events.h"

Event::Event(int id)
{
    this->id = id;
}

Event::~Event()
{

}

std::string Event::description(){
    return name + "has " +  availableSeat + " avaiable seats" ;
}

