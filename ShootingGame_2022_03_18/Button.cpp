#include "ShootingGame.h"

Button::Button(float px, float py) : Sprite("", "", true, px, py)
{}

Button::~Button()
{}

void Button::Start()
{
	SetSprite("Asset/UI/Menu2/normal.bmp"); //버튼..기본 이미지
}

void Button::Update()
{
	if (Input::GetMouseButtonDown(0) == true)
	{
		//마우스 좌표..구해서..이미지 사각형 안에 있는지를...체크//
		int x = Input::mousePosition.x;
		int y = Input::mousePosition.y;

		//이미지 크기 가져오기
		int width, height;
		ImageRect(width, height);

		//이미지 사각형 좌표 구하기
		int x0 = GetPx();
		int x1 = x0 + width;

		int y0 = GetPy();
		int y1 = y0 + height;

		//마우스 좌표가..이미지안에 있는지 판단하기//
		if (x0 < x && x < x1 && y0 < y && y < y1)
		{
			printf("마우스가 이미지..위에서.눌림\n");
		}
	}
}
