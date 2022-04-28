#include "shootingGame.h"

BossChildSprite::BossChildSprite(string tag, string name, bool active, float px, float py)
				:Sprite(tag, name, active, px, py)
{
	this->hp     = 100;
	this->damage = 10;
}

BossChildSprite::~BossChildSprite()
{}

void BossChildSprite::Update()
{}

void BossChildSprite::Explosion()
{
	if (this->GetDead() == false)  //아직 폭발..제거 되지 않은 ..상태
	{
		//날개가..폭발효과//
		float px = GetPx();
		float py = GetPy();

		//폭발 효과 이동 오프셋(offset)구하기//
		int width, height;        //스플라이트 이미지 크기
		ImageRect(width, height);

		float offx = (width  - 64) / 2;
		float offy = (height - 64) / 2;

		Instantiate(new BossChildExp(px + offx, py + offy));
	
		//날개가..제거//
		Destroy(this);   //GameObject의 isDead가 true로 변경

		//부모..객체인..보스에게..자식이 제거되었음을 알림//
		((Boss*)parent)->OnChildDestroy(this->GetName());
	}
}

void BossChildSprite::SetDamage(float damage)
{
	this->damage = damage;
}

void BossChildSprite::OnTriggerStay2D(GameObject* other)
{
	string tag = other->GetTag();

	if (tag == "레이저")
	{
		//체력 줄이기//
		hp = hp - damage;

		if (hp <= 0)
		{
			Explosion();
		}
	}
	else if (tag == "폭탄폭발")
	{
		Explosion();
	}
}