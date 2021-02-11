#include "Unit.h"

Unit::Unit(sf::Vector2f t_position, sf::Color t_color)
{
	SetUp(t_position, t_color);
}

void Unit::SetUp(sf::Vector2f t_position, sf::Color t_color)
{
	m_unit.setPosition(t_position);
	m_unit.setFillColor(t_color);
	m_unit.setSize(sf::Vector2f(2.0f, 5.0f));
}

void Unit::Render(sf::RenderWindow& t_window)
{
	t_window.draw(m_unit);
}
