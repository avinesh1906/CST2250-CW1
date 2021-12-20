#include "events.h"
#include <string>

Event::Event(int id)
{
    this->id = id;
}

Event::~Event()
{

}

std::string Event::description(){
    return name + "has " +  std::to_string(availableSeat) + " avaiable seats" ;
}

