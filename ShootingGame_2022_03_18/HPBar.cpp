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