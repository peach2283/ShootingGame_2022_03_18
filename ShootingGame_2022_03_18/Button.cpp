#include "ShootingGame.h"

Button::Button(float px, float py) : Sprite("", "", true, px, py)
{
	this->state = State::normal;
}

Button::~Button()
{}

void Button::Start()
{
	SetSprite("Asset/UI/Menu2/normal.bmp"); //��ư..�⺻ �̹���
}

void Button::Update()
{
	if (state == State::normal)
	{
		if (IsInImageRect() == true)
		{
			//hover�� ���� ����//
			state = State::hover;

			//hover �̹�����..����//
			SetSprite( hoverImg.data() ); //��ư..hover �̹���
		}
	}
	else if (state == State::hover)
	{
		if (IsInImageRect() == false)
		{
			//normal�� ���� ����//
			state = State::normal;

			//normal �̹�����..����
			SetSprite( normalImg.data() ); //��ư..normal �̹���
		}
		
		if (Input::GetMouseButtonDown(0) == true)
		{
			//click���� ���� ����//
			state = State::click;

			//click �̹�����..����//
			SetSprite( clickImg.data() ); //��ư..click �̹���

			//�̹���..Ŭ�� ȿ����..�̵� ��Ű��//
			Translate(1, 1);
		}
	}
	else if (state == State::click)
	{	
		if (Input::GetMouseButtonUp(0) == true)
		{
			//normal ���·�..����
			state = State::normal;

			//normal �̹�����..����
			SetSprite( normalImg.data() ); //��ư..normal �̹���

			//�̹���..Ŭ�� ȿ��..���� ��ġ��..�̵� ��Ű��//
			Translate(-1, -1);

			//��ư..���� ���� ����//
			OnClick();
		}
	}
}

bool Button::IsInImageRect()
{
	//���콺 ��ǥ..���ؼ�..�̹��� �簢�� �ȿ� �ִ�����...üũ//
	int x = Input::mousePosition.x;
	int y = Input::mousePosition.y;

	//�̹��� ũ�� ��������
	int width, height;
	ImageRect(width, height);

	//�̹��� �簢�� ��ǥ ���ϱ�
	int x0 = GetPx();
	int x1 = x0 + width;

	int y0 = GetPy();
	int y1 = y0 + height;

	//���콺 ��ǥ��..�̹����ȿ� �ִ��� �Ǵ��ϱ�//
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