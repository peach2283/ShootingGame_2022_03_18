#include "ShootingGame.h"

/////////////////���� ��ư///////////////////////////////
StartBTN::StartBTN(float px, float py) : Button(px, py)
{}

StartBTN::~StartBTN()
{}

void StartBTN::Start()
{
	//�⺻ �̹���...�߰��ϱ�
	SetSprite("Asset/UI_old/����.bmp");

	//���콺�� ����..����Ǵ� �̹���..
	SetNormalImg("Asset/UI_old/����.bmp");
	SetHoverImg ("Asset/UI_old/����.bmp");
	SetClickImg ("Asset/UI_old/����.bmp");
}

void StartBTN::OnClick()
{
	printf("���ӽ���");
}

///////////////������ ��ư////////////////////////////
ExitBTN::ExitBTN(float px, float py) : Button(px, py)
{}

ExitBTN::~ExitBTN()
{}

void ExitBTN::Start()
{
	//�⺻ �̹���...�߰��ϱ�
	SetSprite("Asset/UI_old/������.bmp");

	//���콺�� ����..����Ǵ� �̹���..
	SetNormalImg("Asset/UI_old/������.bmp");
	SetHoverImg ("Asset/UI_old/������.bmp");
	SetClickImg ("Asset/UI_old/������.bmp");
}

void ExitBTN::OnClick()
{
	Application::Quit();
}