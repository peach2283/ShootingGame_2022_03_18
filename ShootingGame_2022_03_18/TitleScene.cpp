#include "ShootingGame.h"

TitleScene::TitleScene() : Scene()
{}

TitleScene::~TitleScene()
{}

void TitleScene::Load()
{
	ObjectManager::Instantiate(new TitleBG(0, 0));
}