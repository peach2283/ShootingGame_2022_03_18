#include "GameBG.h"

GameBG::GameBG(float px, float py):Sprite("���ӹ��", "", true, px, py)
{
}

GameBG::~GameBG()
{}

void GameBG::Start()
{
	//�̹��� �ε�//	
	SetSprite("Asset/���ӹ��.bmp");
}

void GameBG::Update()
{
	//�̵� �� �Է�
}