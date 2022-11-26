#pragma once
#include <string>
#include "managers/game_manager.hpp"

class Application final
{
public:
	Application(const std::string& appName);
	~Application();

	void run();

private:
	std::string m_appName;
	GameManager m_gameMgr;
};
