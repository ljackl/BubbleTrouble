//
// Created by pat on 9/05/18.
//

#include "catch.hpp"
#include "../src/core/Bullet.hpp"

TEST_CASE("isOutOfYFrame") {
    sf::FloatRect startPosition(10, -10, 10, 10);
    Bullet testBullet(startPosition);

    REQUIRE(testBullet.isOutOfYFrame());
}