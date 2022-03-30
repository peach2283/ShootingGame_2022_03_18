#include "ShootingGame.h"

Player::Player(float px, float py) : GameObject("�÷��̾�","", true, px, py)
{
	this->speed = 250;  //�̵����ǵ�

	this->fireTimer = 0  ; //�߻�Ÿ�̸� ���� ����
	this->fireDelay = 0.2; //�߻����� ���� ����

	this->index = 3;  //���� ���� ���� �÷��̾� �̹���

	this->animTimer = 0;   //�ִϸ޴ϼ� �ð� ���� ����
	this->animDelay = 0.1f;//�ִϸ޴ϼ� ���� ���� ����
}

Player::~Player()
{}

void Player::Start()
{
	//�÷��̾� �ִϸ��̼� �̹��� ���� �ε�//
	Bitmap::ReadBMP("Asset/�����̵�2.bmp", 64 * 0 , 0, 62, 80, &sprite[0]);
	Bitmap::ReadBMP("Asset/�����̵�2.bmp", 64 * 1 , 0, 62, 80, &sprite[1]);
	Bitmap::ReadBMP("Asset/�����̵�2.bmp", 64 * 2 , 0, 62, 80, &sprite[2]);
	Bitmap::ReadBMP("Asset/�����̵�2.bmp", 64 * 3 , 0, 62, 80, &sprite[3]);
	Bitmap::ReadBMP("Asset/�����̵�2.bmp", 64 * 4 , 0, 62, 80, &sprite[4]);
	Bitmap::ReadBMP("Asset/�����̵�2.bmp", 64 * 5 , 0, 62, 80, &sprite[5]);
	Bitmap::ReadBMP("Asset/�����̵�2.bmp", 64 * 6 , 0, 62, 80, &sprite[6]);

	//�浹ü �߰��ϱ�//
	AddBoxCollider2D(0, 0, 62, 80);
}

void Player::Update()
{
	Move();
	Fire();
}

void Player::Draw()
{
	float px = GetPx();
	float py = GetPy();

	Bitmap::DrawBMP(px, py, &sprite[index]);
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

		if (GetPy() > HEIGHT - 78)
		{
			SetPy(HEIGHT - 78);
		}
	}

	if (Input::GetKey(KeyCode::LeftArrow)==true)
	{
		Translate(-dist, 0);

		if (GetPx() < -8)
		{
			SetPx(-8);
		}

		//�̹��� ����//
		animTimer = animTimer + Time::deltaTime;

		if (animTimer >= animDelay)
		{
			index--;

			if (index < 0)
			{
				index = 0;
			}

			animTimer = 0;
		}
	}

	if (Input::GetKey(KeyCode::RightArrow)==true)
	{
		Translate(dist, 0);

		if (GetPx() > WIDTH - 54)
		{
			SetPx(WIDTH - 54);
		}

		//�̹��� ����//
		animTimer = animTimer + Time::deltaTime;

		if (animTimer >= animDelay)
		{
			index++;

			if (index > 6)
			{
				index = 6;
			}

			animTimer = 0;
		}
	}

	if (Input::GetKey(KeyCode::LeftArrow) != true && Input::GetKey(KeyCode::RightArrow) != true)
	{
		animTimer = animTimer + Time::deltaTime;
		
		if (animTimer >= animDelay)
		{
			if (index < 3)
			{
				index++;
			}
			else if (index > 3)
			{
				index--;
			}

			animTimer = 0;
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
			Instantiate(new Laser(px + 34 - 6, py - 24));
			
			/////////////������ �ι� �߻�////////////////
			//������ ��ü...�����ϱ�//
			//Instantiate(new Laser(px + 34 - 6 - 7, py - 24));
			//Instantiate(new Laser(px + 34 - 6 + 7, py - 24));
			
			///////////////������ ���� �߻�//////////////
			//������ ��ü...�����ϱ�//
			//Instantiate(new Laser(px + 34 - 6 - 7, py - 18));
			//Instantiate(new Laser(px + 34 - 6,     py - 26));
			//Instantiate(new Laser(px + 34 - 6 + 7, py - 18));
			
			//�߻�Ÿ�̸�...����
			fireTimer = 0;
		}
	}	
}