#include "src/include/Spawner.h"
#include "src/include/Constants.h"
#include <cmath>

Spawner::Spawner() { }

Spawner::Spawner(Ship& ship, std::vector<Asteroid>& asteroids)
{
    this->ship = &ship;
    this->asteroids = &asteroids;
}

void Spawner::init(Ship& ship, std::vector<Asteroid>& asteroids)
{
    this->ship = &ship;
    this->asteroids = &asteroids;
}

void Spawner::spawnAsteroid(ast::Vector2 pos, ast::Vector2 dir, float speed, AsteroidSize size)
{
    asteroids->emplace_back(pos, dir, speed, size);
}

void Spawner::spawnAsteroids(int count)
{
    // Bounds of the grace area
    int x1 = ship->getPosition().x - 150;
    int y1 = ship->getPosition().y - 150;
    int x2 = ship->getPosition().x + 150;
    int y2 = ship->getPosition().y + 150;
    for(int i = 0; i < count; i++)
    {
        ast::Vector2 randPos, randDir;
        do
        {          
            randPos.x = rand() % WINDOW_WIDTH;
            randPos.y = rand() % WINDOW_HEIGHT;
        } while (randPos.x > x1 && randPos.x < x2 && randPos.y > y1 && randPos.y < y2);

        float randAng = rand() % 360;
        randDir.x = cos(randAng * PI/180);
        randDir.y = sin(randAng * PI/180);
        spawnAsteroid(randPos, randDir, 3.f, AsteroidSize::Large);
    }
}