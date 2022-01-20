#pragma once

#include "Ship.h"
#include "Asteroid.h"

class Spawner
{
private:
    Ship* ship;
    std::vector<Asteroid>* asteroids;
public:
    Spawner();
    Spawner(Ship& ship, std::vector<Asteroid>& asteroids);
    void init(Ship& ship, std::vector<Asteroid>& asteroids);
    void spawnAsteroid(ast::Vector2 pos, ast::Vector2 dir, float speed, AsteroidSize size);
    void spawnAsteroids(int count);
};

