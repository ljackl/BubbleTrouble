//
// Created by pat on 5/05/18.
//
// Catch Tutorial:
// https://github.com/catchorg/Catch2/blob/master/docs/tutorial.md
//

#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "../other/TestClass.hpp"

TEST_CASE("addition") {
    TestClass test;
    REQUIRE(test.add(2, 3) == 5);
    REQUIRE(test.add(-1, 1) == 0);
    REQUIRE(test.add(2, 4) == 6);
}