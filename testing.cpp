#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "events.h"
#include "struct.h"

TEST_CASE("test live ", "[Live()]"){
    Live live;
    live.setRef(1);
    live.setName("TomorrowIsland");
    live.setMaxCapacity(300);
    int seat = 20;

    live.availableSeatPtr(&seat);
    
    REQUIRE(live.getRef() == 1);
    REQUIRE(live.getName() == "TomorrowIsland"); 
    REQUIRE(live.getMaxCapacity() == 300);
    REQUIRE(live.getAvailableSeat() == 20);

    live.setAvailableSeat(10);
    REQUIRE(live.getAvailableSeat() == 10);
    REQUIRE(live.description() == "TomorrowIsland has 10 available seats out of 300 seats.");
}

TEST_CASE("test standup ", "[StandUp()]"){
    StandUp standUp;
    standUp.setRef(2);
    standUp.setName("Kaya");
    standUp.setMaxCapacity(200);

    int seat = 50;
    standUp.availableSeatPtr(&seat);

    REQUIRE(standUp.getRef() == 2);
    REQUIRE(standUp.getName() == "Kaya"); 
    REQUIRE(standUp.getMaxCapacity() != 300);
    REQUIRE(standUp.getAvailableSeat() != 10);
}

TEST_CASE("test film ", "[Film()]"){
    Film film;
    film.setRef(3);
    film.setName("Spiderman: Age of Covid");
    film.setMaxCapacity(200);
    film.setType("3D");
    int seat = 150;
    film.availableSeatPtr(&seat);

    REQUIRE(film.getRef() == 3);
    REQUIRE(film.getName() != "Avengers: Age of Covid"); 
    REQUIRE(film.getMaxCapacity() != 300);
    REQUIRE(film.getAvailableSeat() == 150);

    film.setAvailableSeat(10);
    REQUIRE(film.getAvailableSeat() != 150);

    REQUIRE(film.description() == "Film Spiderman: Age of Covid of film type 3D has 10 available seats out of 200 seats.");
}

// TEST_CASE("test film booking"){

// }