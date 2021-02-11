#include "Game.h"

static double const MS_PER_UPDATE = 10.0;
Game::Game() :
	m_window{ sf::VideoMode{ desktop.width, desktop.height, desktop.bitsPerPixel }, "SFML Game" }
{
	init();

}


Game::~Game()
{
}


void Game::run()
{
	sf::Clock clock;
	sf::Int32 lag = 0;

	while (m_window.isOpen())
	{
		sf::Time dt = clock.restart();

		lag += dt.asMilliseconds();

		processEvents();

		while (lag > MS_PER_UPDATE)
		{
			update(MS_PER_UPDATE);
			lag -= MS_PER_UPDATE;
		}
		update(MS_PER_UPDATE);

		render();
	}
}


void Game::init()
{
	m_maxEnemies = (rand() % 50) + 10;
	m_distance = (rand() % 25) + 5;
	for (int i = 0; i < m_maxEnemies; i++)
	{
		int randomNumX = (rand() % 1500) + 100;
		int randomNumY = (rand() % 300) + 100;
		sf::Vector2f randomPos = sf::Vector2f(randomNumX, randomNumY);
		m_enemyUnits.push_back(new Unit(randomPos, sf::Color::Red));
	}

	m_tinyForce = m_fuzzyLogic.FuzzyTriangle(m_maxEnemies, -10, 0, 10);
	m_smallForce = m_fuzzyLogic.FuzzyTrapezoid(m_maxEnemies, 2.5, 10, 15, 20);
	m_moderateForce = m_fuzzyLogic.FuzzyTrapezoid(m_maxEnemies, 15, 20, 25, 30);
	m_LargeForce = m_fuzzyLogic.FuzzyGrade(m_maxEnemies, 25, 30);

	m_closeRange = m_fuzzyLogic.FuzzyTriangle(m_distance, -30, 0, 30);
	m_mediumRange = m_fuzzyLogic.FuzzyTrapezoid(m_distance, 10, 30, 50, 70);
	m_farRange = m_fuzzyLogic.FuzzyGrade(m_distance, 50, 70);
	
	m_lowVal = m_fuzzyLogic.FuzzyOr(m_fuzzyLogic.FuzzyAnd(m_mediumRange, m_tinyForce), m_fuzzyLogic.FuzzyAnd(m_mediumRange, m_smallForce));
	m_mediumVal = m_fuzzyLogic.FuzzyAnd(m_closeRange, m_tinyForce);
	m_highVal = m_fuzzyLogic.FuzzyAnd(m_closeRange, m_fuzzyLogic.FuzzyNot(m_mediumRange));
	std::cout << "VAls " << m_lowVal << " , "  << m_mediumVal << " , " << m_highVal;

	m_deployVal = (m_lowVal * 10 + m_mediumVal * 30 + m_highVal * 50) / (m_lowVal + m_mediumVal + m_highVal);
	std::cout << "Deploy Val " << m_deployVal;

	for (int i = 0; i < m_deployVal; i++)
	{
		int randomNumX = (rand() % 1500) + 100;
		int randomNumY = (rand() % 800) + 500;
		sf::Vector2f randomPos = sf::Vector2f(randomNumX, randomNumY);
		m_playerUnits.push_back(new Unit(randomPos, sf::Color::Green));
	}
}

void Game::processEvents()
{
}

void Game::update(double dt)
{
}
void Game::render()
{
	m_window.clear(sf::Color::Black);
	for (int i = 0; i < m_enemyUnits.size(); i++)
	{
		m_enemyUnits[i]->Render(m_window);
	}
	for (int i = 0; i < m_playerUnits.size(); i++)
	{
		m_playerUnits[i]->Render(m_window);
	}
	m_window.display();
}

void Game::handleInputs()
{

}

