#include "ShootingGame.h"

Propeller::Propeller(float px, float py) : Animation("", "", true, px, py)
{}

Propeller::~Propeller()
{}

void Propeller::Start()
{
	//���ؾ��� �ִϸ��̼� - 0��//
	AddSprite("Asset/����.bmp",   7, 439, 32, 12,     0);
	AddSprite("Asset/����.bmp",  42, 439, 30, 12,     0);
	//AddSprite("Asset/����.bmp",  75, 439, 28, 12,     0);
	//AddSprite("Asset/����.bmp", 106, 439, 23, 12,     0);

	//AddSprite("Asset/����.bmp", 133, 439, 19, 12,     0);
	//AddSprite("Asset/����.bmp", 156, 439, 24, 12,     0);
	//AddSprite("Asset/����.bmp", 184, 439, 27, 12,     0);
	//AddSprite("Asset/����.bmp", 215, 439, 29, 12,     0);

	//���⳪�� �ִϸ��̼� - 1��//
	//AddSprite("Asset/����.bmp",   7, 457, 32, 47,      1);
	//AddSprite("Asset/����.bmp",  42, 457, 31, 47,      1);
	//AddSprite("Asset/����.bmp",  76, 457, 29, 47,      1);
	//AddSprite("Asset/����.bmp", 108, 457, 31, 47,      1);

	AddSprite("Asset/����.bmp", 142, 457, 31, 47,      1);
	AddSprite("Asset/����.bmp", 176, 457, 31, 47,      1);
	AddSprite("Asset/����.bmp", 210, 457, 31, 47,      1);
	AddSprite("Asset/����.bmp", 244, 457, 32, 47,      1);

	Play(0);   //0�� �ִϸ��̼�(Ŭ��)����..����
	Speed(2);
}

void Propeller::Update()
{

}
