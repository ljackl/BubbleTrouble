//
// Created by pat on 9/05/18.
//

#include "catch.hpp"
#include "../src/core/Game.hpp"
#include "../states/SplashGameState.hpp"

TEST_CASE("runningTest") {
    Game testGame(10, 10);

    REQUIRE(testGame.running());

    testGame.end();
    REQUIRE(!testGame.running());
}

TEST_CASE("pushStateTest") {
    Game testGame(10, 10);

    auto* testState = new SplashGameState(&testGame);
    testGame.pushState(testState);

    REQUIRE(testGame.peekState() == testState);
}

TEST_CASE("popStateTest") {
    Game testGame(10, 10);

    auto* testState1 = new SplashGameState(&testGame);
    auto* testState2 = new SplashGameState(&testGame);
    testGame.pushState(testState1);
    testGame.pushState(testState2);

    testGame.popState();

    REQUIRE(testGame.peekState() == testState1);
}

TEST_CASE("changeStateTest") {
    Game testGame(10, 10);

    auto* testState1 = new SplashGameState(&testGame);
    auto* testState2 = new SplashGameState(&testGame);

    testGame.changeState(testState1);
    REQUIRE(testGame.peekState() == testState1);

    testGame.changeState(testState2);
    REQUIRE(testGame.peekState() == testState2);
}
