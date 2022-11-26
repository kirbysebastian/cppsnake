#include "application.hpp"

Application::Application(const std::string& appName) :
	m_appName(appName),
	m_gameMgr(m_appName, 1920, 1080)
{}

Application::~Application() {}

void Application::run()
{
	m_gameMgr.start();
}

