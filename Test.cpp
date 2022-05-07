#include "doctest.h"
#include "Game.hpp"
#include "Player.hpp"
#include "Contessa.hpp"
#include "Assassin.hpp"
#include "Ambassador.hpp"
#include "Captain.hpp"
#include "Duke.hpp"
#include <iostream>
#include <string>
using namespace coup;
TEST_CASE("Starting money = 0")
{
    Game g1{};
    Duke duke{g1, "Moshe"};
    Assassin assassin{g1, "Yossi"};
    Ambassador ambassador{g1, "Meirav"};
    Captain captain{g1, "Reut"};
    Contessa contessa{g1, "Gilad"};
    CHECK(duke.coins() == 0);
    CHECK(assassin.coins() == 0);
    CHECK(ambassador.coins() == 0);
    CHECK(captain.coins() == 0);
    CHECK(contessa.coins() == 0);
}
TEST_CASE("income = money+1")
{
    Game g1{};
    Duke duke{g1, "Moshe"};
    Assassin assassin{g1, "Yossi"};
    Ambassador ambassador{g1, "Meirav"};
    Captain captain{g1, "Reut"};
    Contessa contessa{g1, "Gilad"};

    for (int i = 0; i < 50; i++)
    {
        CHECK(duke.coins() == i);
        CHECK(assassin.coins() == i);
        CHECK(ambassador.coins() == i);
        CHECK(captain.coins() == i);
        CHECK(contessa.coins() == i);
        CHECK_NOTHROW(duke.income());
        CHECK_NOTHROW(assassin.income());
        CHECK_NOTHROW(ambassador.income());
        CHECK_NOTHROW(captain.income());
        CHECK_NOTHROW(contessa.income());
    }
}
TEST_CASE("foreign aid = money+2")
{
    Game g1{};
    Duke duke{g1, "Moshe"};
    Assassin assassin{g1, "Yossi"};
    Ambassador ambassador{g1, "Meirav"};
    Captain captain{g1, "Reut"};
    Contessa contessa{g1, "Gilad"};

    for (int i = 0; i < 100; i += 2)
    {
        CHECK(duke.coins() == i);
        CHECK(assassin.coins() == i);
        CHECK(ambassador.coins() == i);
        CHECK(captain.coins() == i);
        CHECK(contessa.coins() == i);
        CHECK_NOTHROW(duke.foreign_aid());
        CHECK_NOTHROW(assassin.foreign_aid());
        CHECK_NOTHROW(ambassador.foreign_aid());
        CHECK_NOTHROW(captain.foreign_aid());
        CHECK_NOTHROW(contessa.foreign_aid());
    }
}
TEST_CASE("Wrong turn")
{
    Game g1{};
    Duke duke{g1, "Moshe"};
    Assassin assassin{g1, "Yossi"};
    Ambassador ambassador{g1, "Meirav"};
    Captain captain{g1, "Reut"};
    Contessa contessa{g1, "Gilad"};
    CHECK_THROWS(assassin.income());
    CHECK_THROWS(ambassador.income());
    CHECK_THROWS(captain.income());
    CHECK_THROWS(contessa.income());
}