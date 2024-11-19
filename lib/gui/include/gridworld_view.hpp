#ifndef GRIDWORLD_VIEW_HPP
#define GRIDWORLD_VIEW_HPP

#include <SFML/Graphics.hpp>
#include "gridworld.hpp"

class GridWorldView {
public:
    GridWorldView(GridWorld& model);
    void draw(sf::RenderWindow& window);
    void setTimeElapsed(float timeElapsed);

private:
    GridWorld& model;
    // size of character dots
    const float characterSize = 10.0f;
    const float characterSpacing = 2.0f;
    float timeElapsed = 0.0f;
};

#endif // GRIDWORLD_VIEW_HPP