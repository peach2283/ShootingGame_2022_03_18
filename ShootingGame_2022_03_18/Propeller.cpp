#include "ShootingGame.h"

Propeller::Propeller(float px, float py) : Animation("보스자식", "프로펠러", true, px, py)
{
	this->hp = 100;
}

Propeller::~Propeller()
{}

void Propeller::Start()
{
	//피해없는 애니메이션 - 0번//
	AddSprite("Asset/프로펠러1.bmp",   5, 5, 32, 12,   0,    16, 6);
	AddSprite("Asset/프로펠러1.bmp",  39, 5, 32, 12,   0,    16, 6);
	AddSprite("Asset/프로펠러1.bmp",  72, 5, 30, 12,   0,    15, 6);
	AddSprite("Asset/프로펠러1.bmp", 104, 5, 24, 12,   0,    12, 6);

	AddSprite("Asset/프로펠러1.bmp", 131, 5, 20, 12,   0,    10, 6);
	AddSprite("Asset/프로펠러1.bmp", 153, 5, 26, 12,   0,    13, 6);
	AddSprite("Asset/프로펠러1.bmp", 182, 5, 28, 12,   0,    14, 6);
	AddSprite("Asset/프로펠러1.bmp", 213, 5, 30, 12,   0,    15, 6);
	

	//연기나는 애니메이션 - 1번//
	AddSprite("Asset/프로펠러2.bmp",   7, 4, 32, 48, 1, 16, 6);
	AddSprite("Asset/프로펠러2.bmp",  42, 4, 31, 48, 1, 15, 6);
	AddSprite("Asset/프로펠러2.bmp",  76, 4, 29, 48, 1, 15, 6);
	AddSprite("Asset/프로펠러2.bmp", 108, 4, 31, 48, 1, 18, 6);

	AddSprite("Asset/프로펠러2.bmp", 142, 4, 31, 48, 1, 17, 6);
	AddSprite("Asset/프로펠러2.bmp", 176, 4, 32, 48, 1, 16, 6);
	AddSprite("Asset/프로펠러2.bmp", 210, 4, 31, 48, 1, 16, 6);
	AddSprite("Asset/프로펠러2.bmp", 244, 4, 32, 48, 1, 16, 6);


	Play(0);   //0번 애니메이션(클립)부터..시작
	Speed(2);

	//충돌체 추가하기//
	AddBoxCollider2D(-16, -6, 32, 12);
}

void Propeller::Update()
{
	//부모..포인터..확인하기//
	//string tag = parent->GetTag();
	//printf("프로펠러의 부모 객체 태그 %s\n", tag.data());
}

void Propeller::Explosion()
{
	//프로렐러..폭발효과//
	float px = GetPx();
	float py = GetPy();

	float offx = (32 - 64) / 2;
	float offy = (12 - 64) / 2;

	Instantiate(new BossChildExp(px + offx, py + offy));

	//플로펠러..제거//
	Destroy(this);

	//프로펠러의 부모객체인 보스에..프로펠러가..제거되었음을 알려줌//
	((Boss*)parent)->OnChildDestroy( this->GetName() );
}

void Propeller::OnTriggerStay2D(GameObject* other)
{
	string tag = other->GetTag();

	if (tag == "레이저")
	{
		//체력에..피해 적용하기//
		hp = hp - 10;

		//남은 체력에 따라서..애니메니션 변경 및 폭발 제거//
		if (0 < hp && hp <= 50)
		{
			Play(1);  //연기나는 프로펠러..애니메이션으로..변경
		}
		else if (hp <= 0)
		{
			Explosion();
		}
	}
	else if (tag == "폭탄폭발")
	{
		Explosion();
	}
}
