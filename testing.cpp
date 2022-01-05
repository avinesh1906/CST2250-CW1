#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "events.h"
#include "struct.h"

TEST_CASE("test live ", "[Live()]"){
    Live live;
    live.setRef(1);
    live.setName("TomorrowIsland");
    live.setMaxCapacity(150);

    int seat = 10;
    live.setAvailableSeat(&(seat));

    REQUIRE(live.getRef() == 1);
    REQUIRE(live.getName() == "TomorrowIsland"); 
    REQUIRE(live.getMaxCapacity() != 200);
    REQUIRE(live.getAvailableSeat() != 50);
}

TEST_CASE("test standup ", "[Live()]"){
    StandUp standUp;
    standUp.setRef(1);
    standUp.setName("TomorrowIsland");
    standUp.setMaxCapacity(150);

    int seat = 10;
    standUp.setAvailableSeat(&(seat));

    REQUIRE(standUp.getRef() == 1);
    REQUIRE(standUp.getName() == "TomorrowIsland"); 
    REQUIRE(standUp.getMaxCapacity() != 200);
    REQUIRE(standUp.getAvailableSeat() != 50);
}

TEST_CASE("test film ", "[Live()]"){
    Film film;
    film.setRef(1);
    film.setName("TomorrowIsland");
    film.setMaxCapacity(150);

    int seat = 10;
    film.setAvailableSeat(&(seat));

    REQUIRE(film.getRef() == 1);
    REQUIRE(film.getName() == "TomorrowIsland"); 
    REQUIRE(film.getMaxCapacity() != 200);
    REQUIRE(film.getAvailableSeat() != 50);
}

