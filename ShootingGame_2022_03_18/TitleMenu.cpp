#include "ShootingGame.h"

/////////////////시작 버튼///////////////////////////////
StartBTN::StartBTN(float px, float py) : Button(px, py)
{}

StartBTN::~StartBTN()
{}

void StartBTN::Start()
{
	//기본 이미지...추가하기
	SetSprite("Asset/UI_old/시작.bmp");

	//마우스와 같이..변경되는 이미지..
	SetNormalImg("Asset/UI_old/시작.bmp");
	SetHoverImg ("Asset/UI_old/시작.bmp");
	SetClickImg ("Asset/UI_old/시작.bmp");
}

void StartBTN::OnClick()
{
	printf("게임시작");
}

///////////////끝내기 버튼////////////////////////////
ExitBTN::ExitBTN(float px, float py) : Button(px, py)
{}

ExitBTN::~ExitBTN()
{}

void ExitBTN::Start()
{
	//기본 이미지...추가하기
	SetSprite("Asset/UI_old/끝내기.bmp");

	//마우스와 같이..변경되는 이미지..
	SetNormalImg("Asset/UI_old/끝내기.bmp");
	SetHoverImg ("Asset/UI_old/끝내기.bmp");
	SetClickImg ("Asset/UI_old/끝내기.bmp");
}

void ExitBTN::OnClick()
{
	Application::Quit();
}