#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "events.h"
#include "struct.h"

TEST_CASE("test live name", "[Live]"){
    Live live;
    live.setName("TomorrowIsland");
    REQUIRE(live.getName() == "TomorrowIsland");   
}

TEST_CASE("test live reference", "[Live]"){
    Live live;
    live.setRef(1);
    REQUIRE(live.getRef() == 1);
}

TEST_CASE("test live max capacity", "[Live]"){
    Live live;
    live.setMaxCapacity(150);
    REQUIRE(live.getMaxCapacity() != 200);
}

// TEST_CASE("test live available seat", "[Live]"){
//     Live live;
//     int seat = 50;
//     live.setAvailableSeat(&(seat));

// }