#include "ShootingGame.h"

TitleBG::TitleBG(float px, float py) : Sprite("","", true, px, py)
{}

TitleBG::~TitleBG()
{}

void TitleBG::Start()
{
	//Ÿ��Ʋ ��� �̹��� �ε�//
	SetSprite("Asset/Ÿ��Ʋ���.bmp");
}

void TitleBG::Update()
{}