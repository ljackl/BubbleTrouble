//
// Created by pat on 9/05/18.
//

#include "catch.hpp"
#include "../src/core/Bubble.hpp"
#include "../core/TextureManager.hpp"

TEST_CASE("popBubble") {
    TextureManager textureManager;
    textureManager.loadTexture("bubble", "resources/images/bubble.png");

    sf::Vector2f pos = sf::Vector2f(0.0f, 0.0f);
    sf::Vector2f vel = sf::Vector2f(0.0f, 0.0f);
    sf::Vector2f acl = sf::Vector2f(0.0f, 0.0f);
    Bubble testBubble(pos, vel, acl, STATE_PLAY, POP_ONE, textureManager.getRef("bubble"));

    testBubble.popBubble();
    REQUIRE(!testBubble.isPopped());

    testBubble.popBubble();
    REQUIRE(!testBubble.isPopped());

    testBubble.popBubble();
    REQUIRE(testBubble.isPopped());
}