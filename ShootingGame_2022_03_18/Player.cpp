#include "ShootingGame.h"

Player::Player(float px, float py) : Sprite("","", true, px, py)
{
	this->speed = 250;  //�̵����ǵ�

	this->fireTimer = 0  ; //�߻�Ÿ�̸� ���� ����
	this->fireDelay = 0.2; //�߻����� ���� ����
}

Player::~Player()
{}

void Player::Start()
{
	SetSprite("Asset/�÷��̾�.bmp");
}

void Player::Update()
{
	Move();
	Fire();
}

void Player::Move()
{
	//�̵��ϱ�//
	float dist = Time::deltaTime * speed;

	if ( Input::GetKey(KeyCode::UpArrow) == true )  
	{
		Translate(0, -dist);

		if (GetPy() < 0)
		{
			SetPy(0);
		}
	}

	if ( Input::GetKey(KeyCode::DownArrow)==true)
	{
		Translate(0, dist);

		if (GetPy() > HEIGHT - 91)
		{
			SetPy(HEIGHT - 91);
		}
	}

	if (Input::GetKey(KeyCode::LeftArrow)==true)
	{
		Translate(-dist, 0);

		if (GetPx() < 0)
		{
			SetPx(0);
		}
	}

	if (Input::GetKey(KeyCode::RightArrow)==true)
	{
		Translate(dist, 0);

		if (GetPx() > WIDTH - 68)
		{
			SetPx(WIDTH - 68);
		}
	}
}

void Player::Fire()
{
	//���� �ڵ� ������ �߻��ϱ�//
	if (Input::GetKey(KeyCode::Space) == true)
	{
		fireTimer = fireTimer + Time::deltaTime;

		if (fireTimer >= fireDelay)
		{
			float px = GetPx();
			float py = GetPy();

			/////////////������ �ѹ� �߻�////////////////
			//������ ��ü...�����ϱ�//
			Instantiate(new Laser(px + 34 - 3, py - 35));
			

			/////////////������ �ι� �߻�////////////////
			//������ ��ü...�����ϱ�//
			//Instantiate(new Laser(px + 34 - 3 - 7, py - 30));
			//Instantiate(new Laser(px + 34 - 3 + 7, py - 30));
			

			///////////////������ ���� �߻�//////////////
			//������ ��ü...�����ϱ�//
			//Instantiate(new Laser(px + 34 - 3 - 7, py - 28));
			//Instantiate(new Laser(px + 34 - 3,     py - 38));
			//Instantiate(new Laser(px + 34 - 3 + 7, py - 28));
			
			//�߻�Ÿ�̸�...����
			fireTimer = 0;
		}
	}	
}