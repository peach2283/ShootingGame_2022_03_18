#include "ShootingGame.h"

Boss::Boss(float px, float py) : Sprite("","", true, px, py)
{}

Boss::~Boss()
{}

void Boss::Start()
{
	//폭발하지 않은 보스 이미지//
	SetSprite("Asset/보스.bmp", 0, 0, 493, 206 );

	//폭발 이후..보스 이미지
	//SetSprite("Asset/보스.bmp", 0, 613, 385, 182);

	//프로펠러..자식객체 추가하기
	AddChildObject(new Propeller( 63, 41));
	AddChildObject(new Propeller(111, 41));
	AddChildObject(new Propeller(159, 41));

	AddChildObject(new Propeller(302, 41));
	AddChildObject(new Propeller(350, 41));
	AddChildObject(new Propeller(398, 41));

	//날개(덮개)..자식 객체 추가하기
	AddChildObject(new Wing(256, 97,   0));
	AddChildObject(new Wing(302, 94,   1));
	AddChildObject(new Wing(350, 90,   2));
	AddChildObject(new Wing(405, 84,   3));

	AddChildObject(new Wing(206, 98,   4));
	AddChildObject(new Wing(158, 94,   5));
	AddChildObject(new Wing(110, 90,   6));
	AddChildObject(new Wing( 62, 85,   7));
}

void Boss::Update()
{}
