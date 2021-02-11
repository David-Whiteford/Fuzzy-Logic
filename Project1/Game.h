#ifndef GAME_H
#define GAME_H
#include <cstdlib>
#include <iostream>
#include <SFML/Graphics.hpp>
#include "MyEnums.h"
#include "Unit.h"
#include "FuzzyLogic.h"

struct CollisionsCheck
{
	bool collisionRight{};
	bool collisionLeft{};
	bool collisionUp{};
	bool collisionDown{};
};

class Game
{
public:
	Game();
	~Game();

	void run();

private:
	FuzzyLogic m_fuzzyLogic;
	std::vector<Unit*> m_enemyUnits;
	std::vector<Unit*> m_playerUnits;
	void init();
	void processEvents();
	void update(double dt);
	void render();
	void handleInputs();
	
	sf::VideoMode desktop = sf::VideoMode::getDesktopMode();
	sf::Event event;
	sf::RenderWindow m_window; // main SFML window
	int m_maxEnemies = 0;
	float m_distance = 0.0f;
	//Enemy Force
	float m_tinyForce, m_smallForce, m_moderateForce, m_LargeForce;
	//Range
	float m_closeRange, m_mediumRange, m_farRange;
	float m_lowVal, m_mediumVal, m_highVal;
	int m_deployVal = 0;
};
#endif
