#include "ShootingGame.h"

///////////////////�˾� �޴�..Ŭ����/////////////////////////////
PopupMenu::PopupMenu(float px, float py) : Sprite("","", true, px, py)
{}

PopupMenu::~PopupMenu()
{}

void PopupMenu::Start()
{
	//�޴� ����̹���//
	SetSprite("Asset/UI/Menu2/bg.bmp");

	//�˾� ���..�ڽ� ��ü �߰��ϱ�//
	AddChildObject(new PopupHeader(0, -35), 6);

	//�޴�..������..��ư�� �ڽİ�ü �߰��ϱ�//
	AddChildObject(new PopupRestart(46, 20), 6);
}

void PopupMenu::Update()
{}

///////////////�˾� �޴�..���.Ŭ����//////////////////////////
PopupHeader::PopupHeader(float px, float py) : Sprite("", "", true, px, py)
{}

PopupHeader::~PopupHeader()
{}

void PopupHeader::Start()
{
	//��� �̹���//
	SetSprite("Asset/UI/Menu2/heading.bmp");
}

void PopupHeader::Update()
{}

////////////////�˾� �޴�..������... �ٽý��� /////////////////
PopupRestart::PopupRestart(float px, float py) : Button(px, py)
{}

PopupRestart::~PopupRestart()
{}

void PopupRestart::Start()
{
	//��ư..�����̹���..�ε��ϱ�//
	SetSprite("Asset/UI/Menu2/normal.bmp");

	//normal, hover, click..�̹��� ���..�����ϱ�//
	SetNormalImg("Asset/UI/Menu2/normal.bmp");
	SetHoverImg ("Asset/UI/Menu2/hover.bmp");
	SetClickImg ("Asset/UI/Menu2/active.bmp");
}