#include "ShootingGame.h"

Player::Player(float px, float py) : GameObject("","", true, px, py)
{
	this->speed = 250;  //이동스피드

	this->fireTimer = 0  ; //발사타이머 측정 변수
	this->fireDelay = 0.2; //발사지연 세팅 변수

	this->index = 3;  //기울어 지지 않은 플레이어 이미지
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
		index--;

		if (index < 0)
		{
			index = 0;
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
		index++;

		if (index > 6)
		{
			index = 6;
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