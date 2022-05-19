#include "ShootingGame.h"

HPBar::HPBar(float px, float py) : Sprite("","",true, px, py)
{
	this->fillAmount = 1;
}

HPBar::~HPBar()
{}

void HPBar::Start()
{
	SetSprite("Asset/UI/Bar/GreenBar200.bmp");

	//아이콘..자식객체 추가하기
	AddChildObject(new Icon(-26, 0, "Asset/UI/Icon/HP_ICON24x24.bmp"), 6);

	//텍스트..자식객체 추가하기
	text = AddChildObject(new Text(L"100", 18, 84, 18), 6);
}

void HPBar::Update()
{}

void HPBar::Draw()
{
	//이미지 크기 가져오기
	int width, height;	
	ImageRect(width, height);

	//게이지..그리기//
	int x0 = GetPx() + 4;
	int y0 = GetPy() + 4;

	int x1 = x0 + (width -8) * fillAmount;
	int y1 = y0 +  height-8;

	for (int y = y0; y < y1; y++)
	{
		for (int x = x0; x < x1; x++)
		{
			SetPixel(x, y, 255, 0, 0);
		}
	}

	//부모..클래스의 Draw 동작시키기//
	Sprite::Draw();
}

void HPBar::SetFillAmount(float fill)
{
	this->fillAmount = fill;
}

void HPBar::SetHP(float hp)
{
	WCHAR temp[10];

	wsprintf(temp, L"%f", hp);

	((Text*)text)->SetText(temp);
}