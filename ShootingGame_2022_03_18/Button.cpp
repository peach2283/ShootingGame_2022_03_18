#include "ShootingGame.h"

Button::Button(float px, float py) : Sprite("", "", true, px, py)
{}

Button::~Button()
{}

void Button::Start()
{
	SetSprite("Asset/UI/Menu2/normal.bmp"); //버튼..기본 이미지
}

void Button::Update()
{}
