#include "ShootingGame.h"

Shield::Shield(float px, float py) : Animation("����","����", true, px, py)
{}

Shield::~Shield()
{}

void Shield::Start()
{
	AddSprite("Asset/��ȣ����1.bmp", 0);
	AddSprite("Asset/��ȣ����2.bmp", 0);
	AddSprite("Asset/��ȣ����3.bmp", 0);

	//�浹ü �߰��ϱ�//
	AddBoxCollider2D(10, 10, 70, 70);
}

void Shield::Update()
{}
