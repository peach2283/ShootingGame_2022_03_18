#include "ShootingGame.h"

Icon::Icon(float px, float py, string iconImg) : Sprite("","", true, px, py)
{
	this->iconImg = iconImg;
}

Icon::~Icon()
{}

void Icon::Start()
{
	//SetSprite("Asset/UI/Icon/HP_ICON24x24.bmp");
	SetSprite(iconImg.data());
}

void Icon::Update()
{}
