#include "ShootingGame.h"

TitleScene::TitleScene() : Scene()
{}

TitleScene::~TitleScene()
{}

void TitleScene::Load()
{
	ObjectManager::Instantiate(new TitleBG(0, 0));

	//Ÿ��Ʋ��..�޴��� ��������..UIManager�� Ȱ��
	ObjectManager::Instantiate(new StartBTN(20 , 700), 6);
	ObjectManager::Instantiate(new ExitBTN (260, 700), 6);
}