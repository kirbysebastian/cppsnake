#include "snake/snake.hpp"

Snake::Snake(
	const float size,
	const sf::Color& color,
	const sf::Vector2f& pos,
	const sf::Vector2f& vel) :
		m_head(size/2, 100),
		m_tail(size/2, 100),
		m_position(pos),
		m_velocity(vel)
{
	m_head.setFillColor(color);
	m_head.setPosition(m_position);
	m_tail.setFillColor(color);
	m_bodies.emplace_back(sf::Vector2f{size, size});
	m_bodies.back().setFillColor(color);
}

Snake::~Snake() {}

