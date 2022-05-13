#include "ShootingGame.h"

///////////////////팝업 메뉴..클래스/////////////////////////////
PopupMenu::PopupMenu(float px, float py) : Sprite("","", true, px, py)
{}

PopupMenu::~PopupMenu()
{}

void PopupMenu::Start()
{
	//메뉴 배경이미지//
	SetSprite("Asset/UI/Menu2/bg.bmp");

	//팝업 헤더..자식 객체 추가하기//
	AddChildObject(new PopupHeader(0, -36), 6);

	//메뉴..아이템..버튼들 자식객체 추가하기//
	AddChildObject(new PopupRestart(13, 15        ), 6);
	AddChildObject(new PopupTitle  (13, 15 + 40   ), 6);
	AddChildObject(new PopupQuit   (13, 15 + 40+40), 6);

	//팝업메뉴..비활성화 시키기//
	SetActive(false);
}

void PopupMenu::Update()
{
}

///////////////팝업 메뉴..헤더.클래스//////////////////////////
PopupHeader::PopupHeader(float px, float py) : Sprite("", "", true, px, py)
{}

PopupHeader::~PopupHeader()
{}

void PopupHeader::Start()
{
	//헤더 이미지//
	SetSprite("Asset/UI/Menu2/heading.bmp");
}

void PopupHeader::Update()
{}

////////////////팝업 메뉴..아이템... 다시시작 /////////////////
PopupRestart::PopupRestart(float px, float py) : Button(px, py)
{}

PopupRestart::~PopupRestart()
{}

void PopupRestart::Start()
{
	//버튼..시작이미지..로드하기//
	SetSprite("Asset/UI/Menu2/normal.bmp");

	//normal, hover, click..이미지 경로..지정하기//
	SetNormalImg("Asset/UI/Menu2/normal.bmp");
	SetHoverImg ("Asset/UI/Menu2/hover.bmp");
	SetClickImg ("Asset/UI/Menu2/active.bmp");
}

void PopupRestart::OnClick()
{
	SceneManager::LoadScene("Game");
}

////////////////팝업 메뉴..아이템... 타이틀로 나가기 메뉴 /////////////////
PopupTitle::PopupTitle(float px, float py) : Button(px, py)
{}

PopupTitle::~PopupTitle()
{}

void PopupTitle::Start()
{
	//버튼..시작이미지..로드하기//
	SetSprite("Asset/UI/Menu2/normal.bmp");

	//normal, hover, click..이미지 경로..지정하기//
	SetNormalImg("Asset/UI/Menu2/normal.bmp");
	SetHoverImg("Asset/UI/Menu2/hover.bmp");
	SetClickImg("Asset/UI/Menu2/active.bmp");

}

void PopupTitle::OnClick()
{
	SceneManager::LoadScene("Title");
}

////////////////팝업 메뉴..아이템... 종료하기 /////////////////
PopupQuit::PopupQuit(float px, float py) : Button(px, py)
{}

PopupQuit::~PopupQuit()
{}

void PopupQuit::Start()
{
	//버튼..시작이미지..로드하기//
	SetSprite("Asset/UI/Menu2/normal.bmp");

	//normal, hover, click..이미지 경로..지정하기//
	SetNormalImg("Asset/UI/Menu2/normal.bmp");
	SetHoverImg("Asset/UI/Menu2/hover.bmp");
	SetClickImg("Asset/UI/Menu2/active.bmp");
}

void PopupQuit::OnClick()
{
	//[1]종료 확인 단계
	//[2]게임저장하기 
	//..기타 필요한 게임 종료 단계..

	Application::Quit();
}