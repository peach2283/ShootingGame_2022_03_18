#include "ShootingGame.h"

EndingBG::EndingBG(float px, float py) : Sprite("","", true, px, py)
{}

EndingBG::~EndingBG()
{}

void EndingBG::Start()
{
	SetSprite("Asset/�������.bmp");
}

void EndingBG::Update()
{}