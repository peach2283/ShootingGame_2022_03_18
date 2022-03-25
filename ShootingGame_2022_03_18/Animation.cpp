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

//�ִϸ��̼� ��� �׽�Ʈ �߰� �Լ�//
void Animation::Start()
{
	//�̹���..�����̽�..�׽�Ʈ �ϱ�//
	/************************
	Image img;

	Bitmap::ReadBMP("Asset/����.bmp", 200 * 0 + 1, 281, 190, 137, &img);
	sprite.push_back(img);

	Bitmap::ReadBMP("Asset/����.bmp", 200 * 1 + 1, 281, 190, 137, &img);
	sprite.push_back(img);
	***************************/

	/**********************�߰� ���� �ִϸ޴ϼ�*****/
	Image img;

	Bitmap::ReadBMP("Asset/����.bmp", 200 * 0 + 1, 141, 190, 137, &img);
	sprite.push_back(img);

	Bitmap::ReadBMP("Asset/����.bmp", 200 * 1 + 1, 141, 190, 137, &img);
	sprite.push_back(img);

	Bitmap::ReadBMP("Asset/����.bmp", 200 * 2 + 1, 141, 190, 137, &img);
	sprite.push_back(img);

	Bitmap::ReadBMP("Asset/����.bmp", 200 * 3 + 1, 141, 190, 137, &img);
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
	//�ִϸ��̼� Ÿ�̸�..����//
	animTimer = animTimer + Time::deltaTime;

	//���ö���Ʈ �׸���//
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

		animTimer = 0;  //Ÿ�̸� ����
	}
}