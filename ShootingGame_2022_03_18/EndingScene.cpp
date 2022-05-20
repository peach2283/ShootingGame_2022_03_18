#include "ShootingGame.h"

EndingScene::EndingScene(string name) : Scene(name)
{}

EndingScene::~EndingScene()
{}

void EndingScene::Load()
{
	ObjectManager::Instantiate(new EndingBG(80, 100));

	ObjectManager::Instantiate(new Text(L"MISSION", 72, 70,  80), 6);
	ObjectManager::Instantiate(new Text(L"CLEAR!!", 72, 76, 640), 6);
}