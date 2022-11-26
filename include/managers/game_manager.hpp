#pragma once
#include <memory>
#include <string_view>
#include <SFML/Graphics.hpp>

#include "controllers/snake_controller.hpp"

class GameManager final
{
public:
	GameManager(
		const std::string_view,
		const uint32_t screenWidth,
		const uint32_t screenHeight);
	~GameManager();

	void start();

private:
	sf::Event m_event;
	sf::RenderWindow m_window;

	std::unique_ptr<SnakeController> m_snakeCtrlrPtr;
};
