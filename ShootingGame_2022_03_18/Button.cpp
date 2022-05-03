#include "ShootingGame.h"

Button::Button(float px, float py) : Sprite("", "", true, px, py)
{}

Button::~Button()
{}

void Button::Start()
{
	SetSprite("Asset/UI/Menu2/normal.bmp"); //��ư..�⺻ �̹���
}

void Button::Update()
{
	if (Input::GetMouseButtonDown(0) == true)
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
			printf("���콺�� �̹���..������.����\n");
		}
	}
}
