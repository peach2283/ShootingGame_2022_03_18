#include "ShootingGame.h"

Boss::Boss(float px, float py) : Sprite("보스","", true, px, py)
{
	this->deadChildCount = 0;
}

Boss::~Boss()
{}

//상속에 의해서... Boss 클래스에서...
//void GameObject::AddChildObject(GameObject* child, int layer)
//{
//	child->parent = this;  //this는 child 객체의 부모..객체포인터
//
//	childObjects.push_back(child);
//
	//자식객체를 부모 좌표 기준으로..이동시키기
//	child->Translate(px, py);
//
//	ObjectManager::Instantiate(child, layer);
//}

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

	//보스 건 ... 자식 객체 추가하기
	AddChildObject(new Gun( 94, 71));
	AddChildObject(new Gun(142, 71));
	AddChildObject(new Gun(190, 71));

	AddChildObject(new Gun(238, 63));

	AddChildObject(new Gun(286, 71));
	AddChildObject(new Gun(334, 71));
	AddChildObject(new Gun(382, 71));

	//보스 대포..자식 객체 추가하기
	AddChildObject(new Cannon(265 + 5, 97 + 10));
	AddChildObject(new Cannon(206 - 5, 97 + 10));

	//레이더..자식 객체 추가하기
	AddChildObject(new Radar(241, 105));
	AddChildObject(new Radar(241, 117));
}

void Boss::Update()
{}

void Boss::OnChildDestroy(string name)
{
	//제거된..자식 카운트..증가시키기//
	deadChildCount++;
	printf("제거된 자식 카운트 : %d\n", deadChildCount);

	if (deadChildCount == 25)  //보스의..모든 자식객체가..제거됨
	{
		//보스..폭발...

		//보스..제거...
		Destroy(this);
	}
}