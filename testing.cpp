#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "events.h"
#include "struct.h"
#include "live.h"
#include "film.h"
#include "standUp.h" 

/* Helper function to check if a vector contains the book seat track */


TEST_CASE("test live ", "[Live()]"){
    Live live;
    live.setRef(1);
    live.setName("TomorrowIsland");
    live.setMaxCapacity(300);

    int availableSeat = 20;
    live.availableSeatPtr(&availableSeat);
    
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

    int availableSeat = 50;
    standUp.availableSeatPtr(&availableSeat);

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

    int availableSeat = 150;
    film.availableSeatPtr(&availableSeat);

    REQUIRE(film.getRef() == 3);
    REQUIRE(film.getName() != "Avengers: Age of Covid"); 
    REQUIRE(film.getMaxCapacity() != 300);
    REQUIRE(film.getAvailableSeat() == 150);

    film.setAvailableSeat(10);
    REQUIRE(film.getAvailableSeat() != 150);

    REQUIRE(film.description() == "Film Spiderman: Age of Covid of film type 3D has 10 available seats out of 200 seats.");
}

TEST_CASE("test live booking", "[Live()]"){
    Live live;

    int availableSeat = 150;
    live.availableSeatPtr(&availableSeat);

    REQUIRE(live.getAvailableSeat() == 150);

    live.booking(50);
    REQUIRE(live.getAvailableSeat() == 100);
}

TEST_CASE("test live cancel booking", "[Live()]"){
    Live live;

    int availableSeat = 150;
    live.availableSeatPtr(&availableSeat);

    REQUIRE(live.getAvailableSeat() == 150);

    live.cancel(25);
    REQUIRE(live.getAvailableSeat() == 175);
}

TEST_CASE("test film booking", "[Film()]"){
    Film film;

    int availableSeat = 50;
    film.availableSeatPtr(&availableSeat);

    REQUIRE(film.getAvailableSeat() != 300);

    film.booking(10);
    REQUIRE(film.getAvailableSeat() == 40);
}

TEST_CASE("test film cancel booking", "[Live()]"){
    Film film;

    int availableSeat = 10;
    film.availableSeatPtr(&availableSeat);

    REQUIRE(film.getAvailableSeat() == 10);

    film.cancel(5);
    REQUIRE(film.getAvailableSeat() == 15);
}

TEST_CASE("test standUp booking", "[StandUp()]"){
    StandUp standUp;
    
    int seatToBook = 1;
    int availableSeat = 296;
    std::vector <int> list = {1,2,3,4};
    standUp.setSeatTrack(&list);
    standUp.availableSeatPtr(&availableSeat);

    REQUIRE(standUp.getAvailableSeat() != 300);

    standUp.booking(seatToBook);
    REQUIRE(standUp.getAvailableSeat() == 295);

}

TEST_CASE("test standUp cancel booking", "[StandUp()]"){
    StandUp standUp;

    std::vector <int> list = {1,2,3,4,5};
    standUp.setSeatTrack(&list);

    int availableSeat = 195;
    standUp.availableSeatPtr(&availableSeat);

    REQUIRE(standUp.getAvailableSeat() != 200);

    standUp.cancel(2);
    REQUIRE(standUp.getAvailableSeat() != 190);
}