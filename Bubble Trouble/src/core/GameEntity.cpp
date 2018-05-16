//
// Created by pat on 6/05/18.
//

#include "GameEntity.hpp"

sf::FloatRect GameEntity::getPosition()const {
    return shape.getGlobalBounds();
}

sf::RectangleShape GameEntity::getShape() {
    return shape;
}
