//
// Created by pat on 5/05/18.
//

#ifdef _WIN32
#include "stdafx.h"
#endif

#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "../src/other/TestClass.hpp"

TEST_CASE("addition") {
    TestClass test;
    REQUIRE(test.add(2, 3) == 5);
    REQUIRE(test.add(-1, 1) == 0);
    REQUIRE(test.add(2, 4) == 6);
}