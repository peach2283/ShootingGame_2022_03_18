#include "ShootingGame.h"

Score::Score(float px, float py) : Sprite("", "", true, px, py)
{}

Score::~Score()
{}

void Score::Start()
{
	SetSprite("Asset/UI/Score/Score200.bmp");

	//������..�ڽİ�ü �߰��ϱ�
	AddChildObject(new Icon(-26, 0, "Asset/UI/Icon/Kill_ICON24x24.bmp"), 6);

	//���� ��� �ؽ�Ʈ
	text = AddChildObject(new Text(L"0000", 18, 72, 23), 6);
}

void Score::Update()
{}

void Score::SetScore(int s)
{
	//���� => �����ڵ� ���ڿ���..��ȯ�ϱ� (wsprintf)
	WCHAR temp[10];
	wsprintf(temp, L"%04d", s);

	((Text*)text)->SetText(temp);
}