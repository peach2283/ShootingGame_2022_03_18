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

	//충돌체 추가하기//
	AddBoxCollider2D(0, 0, 32, 12);
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
