#pragma once
#include <vector>
#include <SFML/Graphics.hpp>

struct Snake
{
	Snake(
		const float size,
		const sf::Color& color,
		const sf::Vector2f& loc,
		const sf::Vector2f& vel);
	~Snake();

	sf::CircleShape m_head;
	std::vector<sf::RectangleShape> m_bodies;
	sf::CircleShape m_tail;
	sf::Vector2f m_position;
	sf::Vector2f m_velocity;
};
