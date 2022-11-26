#include <iostream>
#include "controllers/snake_controller.hpp"

SnakeController::SnakeController()
{}

SnakeController::~SnakeController() {}

void SnakeController::update()
{
	updateSnakeHead();
	updateSnakeHeadEnd();
	updateSnakeBody();
	updateSnakeBodyEnd();
	updateSnakeTail();
}

void SnakeController::createSnake(
	const float size,
	const sf::Color& color,
	const sf::Vector2f& location,
	const sf::Vector2f& velocity)
{
	if (nullptr != m_snakePtr)
		return;

	m_snakePtr = std::make_unique<Snake>(size, color,  location, velocity);
	updateSnakeHeadEnd();
	updateSnakeBody();
	updateSnakeBodyEnd();
	updateSnakeTail();

	std::cout << "HeadPos: (" << m_snakePtr->m_head.getPosition().x << "," << m_snakePtr->m_head.getPosition().y << ")" << std::endl;
	std::cout << "HeadEndPos: (" << m_snakeHeadEnd.x << "," << m_snakeHeadEnd.y << ")" << std::endl;
	//std::cout << "TailPos: (" << m_snakePtr->m_tail.getPosition() << ")" << std::endl;
}

void SnakeController::readMovement(const sf::Keyboard::Key& key)
{
	std::cout << "Velocity: " << m_snakePtr->m_velocity.y << std::endl;
	if (sf::Keyboard::Key::Up == key)
		m_snakePtr->m_velocity = sf::Vector2f{0, -0.0125f};
	else if (sf::Keyboard::Key::Down == key)
		m_snakePtr->m_velocity = sf::Vector2f{0, 0.0125f};
	else if (sf::Keyboard::Key::Left == key)
		m_snakePtr->m_velocity = sf::Vector2f{-0.0125f, 0};
	else if (sf::Keyboard::Key::Right == key)
		m_snakePtr->m_velocity = sf::Vector2f{0.0125f, 0};
}

void SnakeController::draw(sf::RenderWindow& window)
{
	if (!m_snakePtr)
		return;

	window.draw(m_snakePtr->m_head);
	drawBody(window);
	drawTail(window);
}

void SnakeController::updateSnakeHead()
{
	m_snakePtr->m_position += m_snakePtr->m_velocity;
	m_snakePtr->m_head.setPosition(m_snakePtr->m_position);
}

void SnakeController::updateSnakeHeadEnd()
{
	// Get Snake head direction here...
	const auto snakeSize{m_snakePtr->m_head.getRadius()};
	m_snakeHeadEnd = m_snakePtr->m_head.getPosition() + sf::Vector2f{-snakeSize, 0};
}

void SnakeController::updateSnakeBody()
{
	//Note: Need to track current body direction for the succeeding body.
	auto& bodies = m_snakePtr->m_bodies;
	for (int idx=0; idx < bodies.size(); ++idx)
	{
		if (0 == idx)
		{
			bodies[idx].setPosition(m_snakeHeadEnd);
			continue;
		}
	}
}

void SnakeController::updateSnakeBodyEnd()
{
	// Get direction of the last body
	const auto& lastBody = m_snakePtr->m_bodies.back();
	m_snakeBodyEnd = lastBody.getPosition() + sf::Vector2f{-lastBody.getSize().x/2.f, 0.f};
}

void SnakeController::updateSnakeTail()
{
	m_snakePtr->m_tail.setPosition(m_snakeBodyEnd);
}

void SnakeController::drawBody(sf::RenderWindow& window)
{
	for (const auto& body : m_snakePtr->m_bodies)
	{
		window.draw(body);
	}
}

void SnakeController::drawTail(sf::RenderWindow& window)
{
	window.draw(m_snakePtr->m_tail);
}

