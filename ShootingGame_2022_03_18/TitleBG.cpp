#include "ShootingGame.h"

TitleBG::TitleBG(float px, float py) : Sprite("","", true, px, py)
{}

TitleBG::~TitleBG()
{}

void TitleBG::Start()
{
	//타이틀 배경 이미지 로드//
	SetSprite("Asset/타이틀배경.bmp");
}

void TitleBG::Update()
{}