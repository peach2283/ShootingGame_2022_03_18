#include "ShootingGame.h"

Score::Score(float px, float py) : Sprite("", "", true, px, py)
{}

Score::~Score()
{}

void Score::Start()
{
	SetSprite("Asset/UI/Score/Score200.bmp");

	//아이콘..자식객체 추가하기
	AddChildObject(new Icon(-26, 0, "Asset/UI/Icon/Kill_ICON24x24.bmp"), 6);

	//점수 출력 텍스트
	text = AddChildObject(new Text(L"0000", 18, 72, 23), 6);
}

void Score::Update()
{}

void Score::SetScore(int s)
{
	//정수 => 유니코드 문자열로..변환하기 (wsprintf)
	WCHAR temp[10];
	wsprintf(temp, L"%04d", s);

	((Text*)text)->SetText(temp);
}