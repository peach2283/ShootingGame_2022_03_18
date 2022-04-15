#include "ShootingGame.h"

Shield::Shield(float px, float py) : Animation("방패","", true, px, py)
{}

Shield::~Shield()
{}

void Shield::Start()
{
	AddSprite("Asset/보호방패1.bmp", 0);
	AddSprite("Asset/보호방패2.bmp", 0);
	AddSprite("Asset/보호방패3.bmp", 0);

	//충돌체 추가하기//
	AddBoxCollider2D(0, 0, 90, 90);
}

void Shield::Update()
{}
