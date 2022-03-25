#include "ShootingGame.h"

Animation::Animation(string tag, string name, bool active, float px, float py)
		 :GameObject(tag, name, active, px, py)
{
	this->index = 0;

	this->animTimer = 0;
	this->animDelay = 0.07;
}

Animation::~Animation()
{}

//애니메이션 기능 테스트 추가 함수//
void Animation::Start()
{
	//이미지..슬라이스..테스트 하기//
	/************************
	Image img;

	Bitmap::ReadBMP("Asset/적기.bmp", 200 * 0 + 1, 281, 190, 137, &img);
	sprite.push_back(img);

	Bitmap::ReadBMP("Asset/적기.bmp", 200 * 1 + 1, 281, 190, 137, &img);
	sprite.push_back(img);
	***************************/

	/**********************중간 피해 애니메니션*****/
	Image img;

	Bitmap::ReadBMP("Asset/적기.bmp", 200 * 0 + 1, 141, 190, 137, &img);
	sprite.push_back(img);

	Bitmap::ReadBMP("Asset/적기.bmp", 200 * 1 + 1, 141, 190, 137, &img);
	sprite.push_back(img);

	Bitmap::ReadBMP("Asset/적기.bmp", 200 * 2 + 1, 141, 190, 137, &img);
	sprite.push_back(img);

	Bitmap::ReadBMP("Asset/적기.bmp", 200 * 3 + 1, 141, 190, 137, &img);
	sprite.push_back(img);
	/**********************************************/
}

void Animation::Update()
{}

void Animation::AddSprite(const char* fileName, int x, int y, int width, int height)
{
	Image img;

	Bitmap::ReadBMP(fileName, x, y, width, height, &img);
	sprite.push_back(img);
}

void Animation::Draw()
{
	//애니메이션 타이머..측정//
	animTimer = animTimer + Time::deltaTime;

	//스플라이트 그리기//
	float px = GetPx();
	float py = GetPy();

	Bitmap::DrawBMP(px, py, &sprite[index]);

	if (animTimer >= animDelay)
	{		
		index++;

		if ( index >= sprite.size() )
		{
			index = 0;
		}

		animTimer = 0;  //타이머 리셋
	}
}