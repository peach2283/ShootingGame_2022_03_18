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

void Pause::OnClick()
{
	GameManager* manager = GameManager::Instance();
	
	if (manager->GetPause() == true)  //게임이 현재 ... 정지상태임
	{
		Time::timeScale = 1;
		manager->SetPause(false);  //게임 진행중 지정함
	}
	else { //게임이 현재..진행 상태임
	
		Time::timeScale = 0;
		manager->SetPause(true);  //게임 중지 지정함
	}
}