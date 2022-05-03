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
			SetSprite("Asset/UI/Menu2/hover.bmp"); //��ư..hover �̹���
		}
	}
	else if (state == State::hover)
	{
		if (IsInImageRect() == false)
		{
			//normal�� ���� ����//
			state = State::normal;

			//normal �̹�����..����
			SetSprite("Asset/UI/Menu2/normal.bmp"); //��ư..normal �̹���
		}
		
		if (Input::GetMouseButtonDown(0) == true)
		{
			//click���� ���� ����//
			state = State::click;

			//click �̹�����..����//
			SetSprite("Asset/UI/Menu2/active.bmp"); //��ư..click �̹���
		}

	}
	else if (state == State::click)
	{	
		//��ư..���� ���� ����//

		if (Input::GetMouseButtonUp(0) == true)
		{
			//normal ���·�..����
			state = State::normal;

			//normal �̹�����..����
			SetSprite("Asset/UI/Menu2/normal.bmp"); //��ư..normal �̹���
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