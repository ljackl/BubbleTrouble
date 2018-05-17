//
// Created by pat on 9/05/18.
//

#include "catch.hpp"
#include "../src/core/Bullet.hpp"
#include "../core/TextureManager.hpp"

TEST_CASE("isOutOfYFrame") {
    TextureManager textureManager;
    textureManager.loadTexture("bullet", "resources/images/bullet.png");

    sf::FloatRect startPosition(-10, -10, -10, -10);
    Bullet testBullet(startPosition, textureManager.getRef("bullet"));

    REQUIRE(testBullet.isOutOfYFrame());
}