#include "ShootingGame.h"

Boss::Boss(float px, float py) : Sprite("보스","", true, px, py)
{
	this->speed     = 50;
	this->state     = State::moveDown;
	this->attackPos = 50;

	this->fallTimeOut    = 5;
	this->deadChildCount = 0;
}

Boss::~Boss()
{}

void Boss::Start()
{
	//폭발하지 않은 보스 이미지//
	SetSprite("Asset/보스.bmp", 0, 0, 493, 206);

	//프로펠러..자식객체 추가하기
	AddChildObject(new Propeller( 63+16, 41+6));
	AddChildObject(new Propeller(111+16, 41+6));
	AddChildObject(new Propeller(159+16, 41+6));

	AddChildObject(new Propeller(302+16, 41+6));
	AddChildObject(new Propeller(350+16, 41+6));
	AddChildObject(new Propeller(398+16, 41+6));

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
	AddChildObject(new Cannon(265 + 5, 97 + 10, "오른쪽대포"));  //오른쪽 대포
	AddChildObject(new Cannon(206 - 5, 97 + 10, "왼쪽대포"));    //왼쪽 대포

	//레이더..자식 객체 추가하기
	AddChildObject(new Radar(241, 105));
	AddChildObject(new Radar(241, 117));
}

void Boss::Update()
{
	if (state == State::moveDown)
	{
		Translate(0, speed * Time::deltaTime);

		if (GetPy() > attackPos)
		{
			state = State::attack;
		}
	}
	else if (state == State::attack)
	{
		//캐논..자식..객체를..찾아서..발사..시작을..알려줌...//
		string cannons[2] = { "오른쪽대포" , "왼쪽대포" };
		
		for (int i = 0; i < 2; i++)
		{
			Cannon * c=(Cannon*)Find(cannons[i]);

			if (c != nullptr)
			{
				c->OnStartFire();
			}
		}


	}
	else if (state == State::fall)
	{
		//추락... 이동//
		Translate(0, speed * Time::deltaTime);

		//추락 시간 측정//
		fallTimeOut = fallTimeOut - Time::deltaTime;

		if (fallTimeOut <= 0)
		{
			//보스 제거하기//
			Destroy(this);

			//스테이지 클리어//
			printf("=======스테이지 클리어=======\n");
		}
	}
}

void Boss::OnChildDestroy(string name)
{
	//제거된..자식 카운트..증가시키기//
	deadChildCount++;
	printf("제거된 자식 카운트 : %d\n", deadChildCount);

	if (deadChildCount == 25)  //보스의..모든 자식객체가..제거됨 (전체..자식갯수는 25개)
	{
		//보스..폭발...
		float px = GetPx();
		float py = GetPy();

		Instantiate(new EnemyExp(px + (493 - 224) / 2  - 180  , py + (206 - 320) / 2));
		Instantiate(new EnemyExp(px + (493 - 224) / 2         , py + (206 - 320) / 2));
		Instantiate(new EnemyExp(px + (493 - 224) / 2  + 180  , py + (206 - 320) / 2));

		//보스가...폭발후..이미지로...변경		
		SetSprite("Asset/보스.bmp", 0, 613, 385, 182, -47, -7);

		//보스 추락 상태로..변경하기//
		state = State::fall;
	}
}