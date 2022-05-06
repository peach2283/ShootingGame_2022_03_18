#include "ShootingGame.h"

Button::Button(float px, float py) : Sprite("", "", true, px, py)
{
	this->state = State::normal;
}

Button::~Button()
{}

void Button::Start()
{
	SetSprite("Asset/UI/Menu2/normal.bmp"); //버튼..기본 이미지
}

void Button::Update()
{
	if (state == State::normal)
	{
		if (IsInImageRect() == true)
		{
			//hover로 상태 전이//
			state = State::hover;

			//hover 이미지로..변경//
			SetSprite( hoverImg.data() ); //버튼..hover 이미지
		}
	}
	else if (state == State::hover)
	{
		if (IsInImageRect() == false)
		{
			//normal로 상태 전이//
			state = State::normal;

			//normal 이미지로..변경
			SetSprite( normalImg.data() ); //버튼..normal 이미지
		}
		
		if (Input::GetMouseButtonDown(0) == true)
		{
			//click으로 상태 전이//
			state = State::click;

			//click 이미지로..변경//
			SetSprite( clickImg.data() ); //버튼..click 이미지

			//이미지..클릭 효과로..이동 시키기//
			Translate(1, 1);
		}
	}
	else if (state == State::click)
	{	
		if (Input::GetMouseButtonUp(0) == true)
		{
			//normal 상태로..전이
			state = State::normal;

			//normal 이미지로..변경
			SetSprite( normalImg.data() ); //버튼..normal 이미지

			//이미지..클릭 효과..원래 위치로..이동 시키기//
			Translate(-1, -1);

			//버튼..관련 동작 실행//
			OnClick();
		}
	}
}

bool Button::IsInImageRect()
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
		return true;
	}
	else {
		return false;
	}
}

void Button::SetNormalImg(string fileName)
{
	this->normalImg = fileName;
}

void Button::SetHoverImg(string fileName)
{
	this->hoverImg = fileName;
}

void Button::SetClickImg(string fileName)
{
	this->clickImg = fileName;
}

void Button::OnClick()
{}