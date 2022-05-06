#include "ShootingGame.h"

Pause::Pause(float px, float py) : Button(px, py)
{}

Pause::~Pause()
{}

void Pause::Start()
{
	SetSprite("Asset/UI/Button/Pause.bmp");

	//�θ� Ŭ������..�̹��� ���� ��θ�..������//
	SetNormalImg("Asset/UI/Button/Pause.bmp");
	SetHoverImg ("Asset/UI/Button/Pause.bmp");
	SetClickImg ("Asset/UI/Button/Pause.bmp");
}

void Pause::OnClick()
{
	GameManager* manager = GameManager::Instance();
	
	if (manager->GetPause() == true)  //������ ���� ... ����������
	{
		Time::timeScale = 1;
		manager->SetPause(false);  //���� ������ ������
	}
	else { //������ ����..���� ������
	
		Time::timeScale = 0;
		manager->SetPause(true);  //���� ���� ������
	}
}