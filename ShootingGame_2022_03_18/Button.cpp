#include "ShootingGame.h"

Button::Button(float px, float py) : Sprite("", "", true, px, py)
{}

Button::~Button()
{}

void Button::Start()
{
	SetSprite("Asset/UI/Menu2/normal.bmp"); //��ư..�⺻ �̹���
}

void Button::Update()
{}
