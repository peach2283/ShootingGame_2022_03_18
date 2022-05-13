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
	AddChildObject(new PopupHeader(0, -36), 6);

	//�޴�..������..��ư�� �ڽİ�ü �߰��ϱ�//
	AddChildObject(new PopupRestart(13, 15        ), 6);
	AddChildObject(new PopupTitle  (13, 15 + 40   ), 6);
	AddChildObject(new PopupQuit   (13, 15 + 40+40), 6);

	//�˾��޴�..��Ȱ��ȭ ��Ű��//
	SetActive(false);
}

void PopupMenu::Update()
{
}

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

void PopupRestart::OnClick()
{
	SceneManager::LoadScene("Game");
}

////////////////�˾� �޴�..������... Ÿ��Ʋ�� ������ �޴� /////////////////
PopupTitle::PopupTitle(float px, float py) : Button(px, py)
{}

PopupTitle::~PopupTitle()
{}

void PopupTitle::Start()
{
	//��ư..�����̹���..�ε��ϱ�//
	SetSprite("Asset/UI/Menu2/normal.bmp");

	//normal, hover, click..�̹��� ���..�����ϱ�//
	SetNormalImg("Asset/UI/Menu2/normal.bmp");
	SetHoverImg("Asset/UI/Menu2/hover.bmp");
	SetClickImg("Asset/UI/Menu2/active.bmp");

}

void PopupTitle::OnClick()
{
	SceneManager::LoadScene("Title");
}

////////////////�˾� �޴�..������... �����ϱ� /////////////////
PopupQuit::PopupQuit(float px, float py) : Button(px, py)
{}

PopupQuit::~PopupQuit()
{}

void PopupQuit::Start()
{
	//��ư..�����̹���..�ε��ϱ�//
	SetSprite("Asset/UI/Menu2/normal.bmp");

	//normal, hover, click..�̹��� ���..�����ϱ�//
	SetNormalImg("Asset/UI/Menu2/normal.bmp");
	SetHoverImg("Asset/UI/Menu2/hover.bmp");
	SetClickImg("Asset/UI/Menu2/active.bmp");
}

void PopupQuit::OnClick()
{
	//[1]���� Ȯ�� �ܰ�
	//[2]���������ϱ� 
	//..��Ÿ �ʿ��� ���� ���� �ܰ�..

	Application::Quit();
}