#pragma once

#include <SFML/Graphics.hpp>
#include <vector>
#include "GameManager.h"
#include "Bullet.h"
#include "Constants.h"
#include "Ship.h"

class Game
{
private:
    GameManager manager;
    bool gameOver = false;

    sf::RenderWindow window;
    sf::Texture* shipTex;
    sf::Texture* astTex;
    sf::Texture* blltTex;

    sf::Font font;
    sf::Text scoreText;

    Ship ship;
    sf::Texture* shipHpTexture;
    sf::Sprite shipHpSprite;
    std::vector<Asteroid> asteroids;
    std::vector<Bullet> bullets;
    ast::Vector2 v;
public:
    Game();
    void update();
private:
    void reset();
    void createWindow(std::string windowName, int frameLimit);
    void loadTextures();
    template <typename T>
    void updateEntities(std::vector<T>& v, sf::Time dt);
    template <typename T>
    void drawEntities(std::vector<T>& v);
    template <typename T>
    void drawDebugEntities(std::vector<T>& v);
    void drawLives();
    void checkDespawnedBullets();
    void draw();
};
