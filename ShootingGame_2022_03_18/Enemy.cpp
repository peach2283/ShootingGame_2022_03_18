#include "ShootingGame.h"

Enemy::Enemy(float px, float py) : Animation("적기","", true, px, py)
{
	this->speed     = 100;
	
	this->fallSpeed   = 300;
	this->fallTimeOut = 3;

	this->state = State::moveDown;

	this->fireTimer = 0;
	this->fireDelay = 0.5;

	this->hp = 100;

	this->isBombExpCollided = false;
	this->isLaserCollided   = false;

	this->dropBulletItem    = false;
}

Enemy::~Enemy()
{}

void Enemy::Start()
{
	/////////피해없는 적기 이미지들//////////////////////////
	AddSprite("Asset/적기.bmp", 200 * 0 + 1, 281, 190, 137,     0);
	AddSprite("Asset/적기.bmp", 200 * 1 + 1, 281, 190, 137,     0);

	////////중간피해 적기 이미지들//////////////////////////
	AddSprite("Asset/적기.bmp", 200 * 0 + 1, 141, 190, 137,     1);
	AddSprite("Asset/적기.bmp", 200 * 1 + 1, 141, 190, 137,     1);
	AddSprite("Asset/적기.bmp", 200 * 2 + 1, 141, 190, 137,     1);
	AddSprite("Asset/적기.bmp", 200 * 3 + 1, 141, 190, 137,     1);

	////////많은피해 적기 이미지들//////////////////////////
	AddSprite("Asset/적기.bmp", 200 * 0 + 1,   1, 190, 137,     2);
	AddSprite("Asset/적기.bmp", 200 * 1 + 1,   1, 190, 137,     2);
	AddSprite("Asset/적기.bmp", 200 * 2 + 1,   1, 190, 137,     2);
	AddSprite("Asset/적기.bmp", 200 * 3 + 1,   1, 190, 137,     2);

	///충돌체 추가하기////
	AddBoxCollider2D(0  , 80, 190, 25);   //가운데 날개 
	AddBoxCollider2D(65 , 10,  60,  15);  //꼬리 날개 
	AddBoxCollider2D(85 , 25,  20,  110); //몸통

	//moveDown 상태 종료 위치 랜덤만들기
	downEndPos = Random::Range(20, 150);
}

void Enemy::Update()
{	
	Move();
	Fire();

	//중복 충돌 판단 변수 리셋
	isBombExpCollided = false;
	isLaserCollided   = false;
}

void Enemy::Move()
{
	//적기 이동하기 스테이트 머신//
	switch (state)
	{
		case State::moveDown:
		{
			Translate(0, speed * Time::deltaTime);

			if (GetPy() > downEndPos)
			{
				state = State::moveLeft;
			}
		}
		break;

		case State::moveLeft:
		{
			Translate(-speed * Time::deltaTime, 0);

			if (GetPx() < 0)
			{
				state = State::moveRight;
			}
		}
		break;

		case State::moveRight:
		{
			Translate(speed * Time::deltaTime, 0);

			if (GetPx() > WIDTH - 190)
			{
				state = State::moveLeft;
			}
		}
		break;

		case State::fall:
		{
			//추락 이동하기//
			Translate(0, fallSpeed * Time::deltaTime);		

			//타임아웃 측정//
			fallTimeOut -= Time::deltaTime;
			
			if (fallTimeOut < 0)
			{
				//적기 제거//
				Destroy(this);

				//적기 스포너..객체 가져오기..제거 카운드 증가
				EnemySpawner* spawner = EnemySpawner::Instance();
				spawner->AddDestroy();
			}
		}

		break;
	}
}

void Enemy::Fire()
{
	//총알 발사//
	if (state == State::moveLeft || state == State::moveRight)
	{
		fireTimer = fireTimer + Time::deltaTime;

		if (fireTimer >= fireDelay)
		{
			float px = GetPx();
			float py = GetPy();

			Instantiate(new EnemyBullet(px + 95 - 9, py + 137 - 10));

			fireTimer = 0;
		}
	}
}

void Enemy::SetDropBulletItem(bool drop)
{
	dropBulletItem = drop;
}

void Enemy::SetDropBombItem(bool drop)
{
	dropBombItem = drop;
}

void Enemy::Explosion()
{
	//적기 폭발
	float px = this->GetPx();
	float py = this->GetPy();

	Instantiate(new EnemyExp(px - 18, py - 90), 1);

	//적기 제거
	Destroy(this);

	//적기 제거 카운트 하기
	EnemySpawner* spawner = EnemySpawner::Instance();
	spawner->AddDestroy();

	//총알(레이저) 아이템 떨기기//
	//int p = Random::Range(0, 10000);
	//
	//if (p < 1000)
	//{
	//	Instantiate(new BulletItem(px + 80, py + 40));
	//}

	if (dropBulletItem == true)
	{
		Instantiate(new BulletItem(px + 80, py + 40));
	}

	//폭탄 아이템..떨기기//
	if (dropBombItem == true)
	{
		Instantiate(new BombItem(px + (190 - 22) / 2, py + (137 - 40) / 2));
	}
}

void Enemy::OnTriggerStay2D(GameObject * other)
{
	string tag = other->GetTag();

	if (tag == "레이저")
	{
		if (isLaserCollided == false)
		{
			isLaserCollided = true;

			hp = hp - 10;  //적기 체력에..피해(Damage)양 적용하기
		
			//레이저 폭발효과//
			float px = other->GetPx();
			float py = other->GetPy();

			Instantiate(new LaserExp(px - 14, py));

			Destroy(other);  //레이저 삭제하기//

			//적기..피해 애니메니션 판단하기//
			if (80 <= hp && hp <= 100)
			{
				Play(0);  //피해없는 애니메이션
			}
			else if (50 <= hp && hp < 80)
			{
				Play(1);  //중간피해 애니메이션
			}
			else if (0 < hp && hp < 50)
			{
				Play(2);              //심각한피해 애니메이션
				state = State::fall;  //적기 추락상태로..전이(transition)
			}
			else if (hp <= 0)
			{
				Explosion();
			}
		}
	}
	else if (tag == "폭탄폭발")
	{
		if (isBombExpCollided == false)  //이전에...충돌처리가 안되었을때만..
		{
			isBombExpCollided = true;  //충돌처리 했음을...표시
			Explosion();			
		}
	}
	else if (tag == "플레이어")
	{
		//printf("----적기에..플레이어가 충돌함---\n");
	}
}