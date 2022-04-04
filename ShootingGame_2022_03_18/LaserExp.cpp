#include "ShootingGame.h"

LaserExp::LaserExp(float px, float py) : Animation("", "", true, px, py)
{}

LaserExp::~LaserExp()
{}

void LaserExp::Start()
{
	//���� �̹���..�ε��ϱ�//
	for (int y = 2; y < 5; y++)
	{
		for (int x = 0; x < 5; x++)
		{
			AddSprite("Asset/����������.bmp", x * 36, y * 36, 36, 36, 0);
		}
	}

	//�ִϸ��̼� �ӵ� ����
	Speed(2);
}

void LaserExp::Update()
{}

void LaserExp::OnAnimationEnd()
{	
	Destroy(this);
}