#include "ShootingGame.h"

EndingScene::EndingScene(string name) : Scene(name)
{}

EndingScene::~EndingScene()
{}

void EndingScene::Load()
{
	ObjectManager::Instantiate(new EndingBG(80, 100));
}