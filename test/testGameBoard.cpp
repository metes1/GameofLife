#include "catch.h"
#include "GameBoard.h"
#include "GameBoardTypes.h"
#include "Exceptions.h"

TEST_CASE( "tests for GameBoard" , "[GameBoard]" ) {
    GameBoard gameboard;

    SECTION("test init() for existing file"){
        gameboard.init("input.txt");

        //tests if file was read correctly
        //checks whether the gameboard cells match the file
        REQUIRE((   gameboard.getb(0, 0) == 0 
                 && gameboard.getb(7, 7) == 1
               ));
    }

    SECTION("test init() for throws invalid_file"){
        REQUIRE_THROWS_AS(gameboard.init("file.txt"), invalid_file);
    }

    SECTION("test next()"){
        gameboard.init("input.txt");
        gameboard.next();

        //tests if board transitioned properly
        REQUIRE(gameboard.getb(7, 6) == 0);
        REQUIRE(gameboard.getb(7, 7) == 0);
        REQUIRE(gameboard.getb(7, 8) == 1);
        REQUIRE(gameboard.getb(7, 9) == 0);
        REQUIRE(gameboard.getb(7, 10) == 1);
        REQUIRE(gameboard.getb(7, 11) == 0);
        REQUIRE(gameboard.getb(7, 12) == 0);
        REQUIRE(gameboard.getb(8, 6) == 1);
        REQUIRE(gameboard.getb(8, 7) == 1);
        REQUIRE(gameboard.getb(8, 8) == 0);
        REQUIRE(gameboard.getb(8, 9) == 0);
        REQUIRE(gameboard.getb(8, 10) == 0);
        REQUIRE(gameboard.getb(8, 11) == 1);
        REQUIRE(gameboard.getb(8, 12) == 1);
        REQUIRE(gameboard.getb(9, 6) == 1);
        REQUIRE(gameboard.getb(9, 7) == 1);
        REQUIRE(gameboard.getb(9, 8) == 1);
        REQUIRE(gameboard.getb(9, 9) == 0);
        REQUIRE(gameboard.getb(9, 10) == 1);
        REQUIRE(gameboard.getb(9, 11) == 1);
        REQUIRE(gameboard.getb(9, 12) == 1);
        REQUIRE(gameboard.getb(10, 6) == 1);
        REQUIRE(gameboard.getb(10, 7) == 1);
        REQUIRE(gameboard.getb(10, 8) == 0);
        REQUIRE(gameboard.getb(10, 9) == 0);
        REQUIRE(gameboard.getb(10, 10) == 0);
        REQUIRE(gameboard.getb(10, 11) == 1);
        REQUIRE(gameboard.getb(10, 12) == 1);
        REQUIRE(gameboard.getb(11, 6) == 0);
        REQUIRE(gameboard.getb(11, 7) == 0);
        REQUIRE(gameboard.getb(11, 8) == 1);
        REQUIRE(gameboard.getb(11, 9) == 0);
        REQUIRE(gameboard.getb(11, 10) == 1);
        REQUIRE(gameboard.getb(11, 11) == 0);
        REQUIRE(gameboard.getb(11, 12) == 0);
    }

    SECTION("test getb()"){
        gameboard.init("input.txt");
        REQUIRE(gameboard.getb(0, 0) == 0);
    }

    SECTION("test getb() for throws out_of_bounds"){
        gameboard.init("input.txt");
        REQUIRE_THROWS_AS(gameboard.getb(-2, 40), out_of_bounds);
    }
}