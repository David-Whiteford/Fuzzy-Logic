#pragma once

#include <SFML/Graphics.hpp>
class Unit
{
public:
	Unit(sf::Vector2f t_position,sf::Color t_color);
	~Unit();
	void SetUp(sf::Vector2f t_position, sf::Color t_color);
	void Render(sf::RenderWindow& t_window);
private:
	sf::Vector2f m_position;
	sf::RectangleShape m_unit;
};
