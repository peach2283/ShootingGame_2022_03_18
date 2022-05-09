#include "ShootingGame.h"

bool Application::isPlaying = true;

void Application::Quit()
{
	isPlaying = false;
}

bool Application::GetIsPlaying()
{
	return isPlaying;
}