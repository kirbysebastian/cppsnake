#pragma once
#include <memory>
#include "snake/snake.hpp"

class SnakeController final
{
public:
	SnakeController();
	~SnakeController();

	void update();
	void createSnake(
		const float size,
		const sf::Color& color,
		const sf::Vector2f& location,
		const sf::Vector2f& velocity
	);
	void readMovement(const sf::Keyboard::Key& key);

	void draw(sf::RenderWindow& window);

private:
	void updateSnakeHead();
	void updateSnakeHeadEnd();
	void updateSnakeBody();
	void updateSnakeBodyEnd();
	void updateSnakeTail();
	void drawBody(sf::RenderWindow& window);
	void drawTail(sf::RenderWindow& window);

	sf::Vector2f m_snakeHeadEnd;
	sf::Vector2f m_snakeBodyEnd;
	std::unique_ptr<Snake> m_snakePtr;
};
