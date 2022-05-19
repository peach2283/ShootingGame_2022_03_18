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
	AddChildObject(new Text(L"0000", 18, 72, 23), 6);
}

void Score::Update()
{}
