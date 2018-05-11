//
// Created by pat on 6/05/18.
//

#include "GameEntity.hpp"

sf::FloatRect GameEntity::getPosition() {
    return shape.getGlobalBounds();
}

sf::RectangleShape GameEntity::getShape() {
    return shape;
}
