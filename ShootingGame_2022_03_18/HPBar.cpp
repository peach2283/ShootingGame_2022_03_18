#include "ShootingGame.h"

HPBar::HPBar(float px, float py) : Sprite("","",true, px, py)
{}

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
	//�̹��� ũ�� ��������
	int width, height;	
	ImageRect(width, height);

	//������..�׸���//
	int x0 = GetPx();
	int y0 = GetPy();

	int x1 = x0 + width;
	int y1 = y0 + height;

	for (int y = y0; y < y1; y++)
	{
		for (int x = x0; x < x1; x++)
		{
			SetPixel(x, y, 255, 0, 0);
		}
	}
}