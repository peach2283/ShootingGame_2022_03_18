#include "ShootingGame.h"

TitleScene::TitleScene() : Scene()
{}

TitleScene::~TitleScene()
{}

void TitleScene::Load()
{
	ObjectManager::Instantiate(new TitleBG(0, 0));

	//타이틀에..메뉴가 많은경우는..UIManager를 활용
	ObjectManager::Instantiate(new StartBTN(20 , 700), 6);
	ObjectManager::Instantiate(new ExitBTN (260, 700), 6);
}