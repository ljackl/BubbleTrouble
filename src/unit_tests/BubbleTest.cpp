//
// Created by pat on 9/05/18.
//

#include "catch.hpp"
#include "../src/core/Bubble.hpp"

TEST_CASE("popBubble") {
    Bubble testBubble(10, 10, STATE_PLAY);

    testBubble.popBubble();
    REQUIRE(!testBubble.isPopped());

    testBubble.popBubble();
    REQUIRE(!testBubble.isPopped());

    testBubble.popBubble();
    REQUIRE(testBubble.isPopped());
}