#include <iostream>
#include "managers/game_manager.hpp"

GameManager::GameManager(
	const std::string_view gameTitle,
	const uint32_t screenWidth,
	const uint32_t screenHeight) :
		m_event(),
		m_window(sf::VideoMode(screenWidth, screenHeight), gameTitle.data()),
		m_snakeCtrlrPtr(std::make_unique<SnakeController>())
	{}

GameManager::~GameManager() {}

void GameManager::start()
{
	const auto& screenSize = m_window.getSize();
	m_snakeCtrlrPtr->createSnake(
		40.f, sf::Color::White, sf::Vector2f{screenSize.x/2, screenSize.y/2}, {0.0125f, 0.f});
	while (m_window.isOpen())
	{
		while (m_window.pollEvent(m_event))
		{
			if (sf::Event::Closed == m_event.type ||
				(sf::Event::KeyPressed == m_event.type &&
				 sf::Keyboard::Key::Escape == m_event.key.code))
				m_window.close();

			if (sf::Event::KeyPressed == m_event.type)
				m_snakeCtrlrPtr->readMovement(m_event.key.code);
		}

		m_window.clear();
		m_snakeCtrlrPtr->update();
		m_snakeCtrlrPtr->draw(m_window);
		m_window.display();
	}
}

