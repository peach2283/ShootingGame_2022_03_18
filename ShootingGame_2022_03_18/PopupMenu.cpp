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
	AddChildObject(new PopupHeader(0, -35), 6);

	//메뉴..아이템..버튼들 자식객체 추가하기//
	AddChildObject(new PopupRestart(46, 20), 6);
}

void PopupMenu::Update()
{}

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