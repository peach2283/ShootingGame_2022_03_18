#include "ShootingGame.h"

Pause::Pause(float px, float py) : Button(px, py)
{}

Pause::~Pause()
{}

void Pause::Start()
{
	SetSprite("Asset/UI/Button/Pause.bmp");

	//부모 클래스에..이미지 파일 경로를..지정함//
	SetNormalImg("Asset/UI/Button/Pause.bmp");
	SetHoverImg ("Asset/UI/Button/Pause.bmp");
	SetClickImg ("Asset/UI/Button/Pause.bmp");
}
