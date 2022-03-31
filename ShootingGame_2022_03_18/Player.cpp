#include "ShootingGame.h"

Player::Player(float px, float py) : GameObject("플레이어","", true, px, py)
{
	this->speed = 250;  //이동스피드

	this->fireTimer = 0  ; //발사타이머 측정 변수
	this->fireDelay = 0.2; //발사지연 세팅 변수

	this->index = 3;  //기울어 지지 않은 플레이어 이미지

	this->animTimer = 0;   //애니메니션 시간 측정 변수
	this->animDelay = 0.1f;//애니메니션 지연 지정 변수

	this->hp = 100;  //플레이어 체력
}

Player::~Player()
{}

void Player::Start()
{
	//플레이어 애니메이션 이미지 직접 로드//
	Bitmap::ReadBMP("Asset/팬텀이동2.bmp", 64 * 0 , 0, 62, 80, &sprite[0]);
	Bitmap::ReadBMP("Asset/팬텀이동2.bmp", 64 * 1 , 0, 62, 80, &sprite[1]);
	Bitmap::ReadBMP("Asset/팬텀이동2.bmp", 64 * 2 , 0, 62, 80, &sprite[2]);
	Bitmap::ReadBMP("Asset/팬텀이동2.bmp", 64 * 3 , 0, 62, 80, &sprite[3]);
	Bitmap::ReadBMP("Asset/팬텀이동2.bmp", 64 * 4 , 0, 62, 80, &sprite[4]);
	Bitmap::ReadBMP("Asset/팬텀이동2.bmp", 64 * 5 , 0, 62, 80, &sprite[5]);
	Bitmap::ReadBMP("Asset/팬텀이동2.bmp", 64 * 6 , 0, 62, 80, &sprite[6]);

	//충돌체 추가하기//
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
	//이동하기//
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

		//이미지 변경//
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

		//이미지 변경//
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
	//연속 자동 레이저 발사하기//
	if (Input::GetKey(KeyCode::Space) == true)
	{
		fireTimer = fireTimer + Time::deltaTime;

		if (fireTimer >= fireDelay)
		{
			float px = GetPx();
			float py = GetPy();

			/////////////레이저 한발 발사////////////////
			//레이저 객체...생성하기//
			Instantiate(new Laser(px + 34 - 6, py - 24));
			
			/////////////레이저 두발 발사////////////////
			//레이저 객체...생성하기//
			//Instantiate(new Laser(px + 34 - 6 - 7, py - 24));
			//Instantiate(new Laser(px + 34 - 6 + 7, py - 24));
			
			///////////////레이저 세발 발사//////////////
			//레이저 객체...생성하기//
			//Instantiate(new Laser(px + 34 - 6 - 7, py - 18));
			//Instantiate(new Laser(px + 34 - 6,     py - 26));
			//Instantiate(new Laser(px + 34 - 6 + 7, py - 18));
			
			//발사타이머...리셋
			fireTimer = 0;
		}
	}	
}

void Player::OnTriggerStay2D(GameObject * other)
{
	string tag = other->GetTag();

	printf("---플레이어 클래스 충돌처리----\n");
	printf("   충돌 상대 태그 %s\n", tag.data());
}