#include "ShootingGame.h"

Propeller::Propeller(float px, float py) : Animation("", "", true, px, py)
{}

Propeller::~Propeller()
{}

void Propeller::Start()
{
	//피해없는 애니메이션 - 0번//
	AddSprite("Asset/보스.bmp",   7, 439, 32, 12,     0);
	AddSprite("Asset/보스.bmp",  42, 439, 30, 12,     0);
	//AddSprite("Asset/보스.bmp",  75, 439, 28, 12,     0);
	//AddSprite("Asset/보스.bmp", 106, 439, 23, 12,     0);

	//AddSprite("Asset/보스.bmp", 133, 439, 19, 12,     0);
	//AddSprite("Asset/보스.bmp", 156, 439, 24, 12,     0);
	//AddSprite("Asset/보스.bmp", 184, 439, 27, 12,     0);
	//AddSprite("Asset/보스.bmp", 215, 439, 29, 12,     0);

	//연기나는 애니메이션 - 1번//
	//AddSprite("Asset/보스.bmp",   7, 457, 32, 47,      1);
	//AddSprite("Asset/보스.bmp",  42, 457, 31, 47,      1);
	//AddSprite("Asset/보스.bmp",  76, 457, 29, 47,      1);
	//AddSprite("Asset/보스.bmp", 108, 457, 31, 47,      1);

	AddSprite("Asset/보스.bmp", 142, 457, 31, 47,      1);
	AddSprite("Asset/보스.bmp", 176, 457, 31, 47,      1);
	AddSprite("Asset/보스.bmp", 210, 457, 31, 47,      1);
	AddSprite("Asset/보스.bmp", 244, 457, 32, 47,      1);

	Play(0);   //0번 애니메이션(클립)부터..시작
	Speed(2);
}

void Propeller::Update()
{

}
