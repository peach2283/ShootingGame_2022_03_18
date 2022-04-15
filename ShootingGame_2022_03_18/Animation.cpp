#include "ShootingGame.h"

Animation::Animation(string tag, string name, bool active, float px, float py)
		 :GameObject(tag, name, active, px, py)
{
	this->index = 0;

	this->animTimer = 0;
	this->animDelay = 0.07;

	this->animId = 0;
}

Animation::~Animation()
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < sprite[i].size(); j++)
		{
			delete[] sprite[i][j].rgb;
		}
	}
}

void Animation::AddSprite(const char* fileName, int x, int y, int width, int height, int id)
{
	Image img;

	Bitmap::ReadBMP(fileName, x, y, width, height, &img);
	sprite[id].push_back(img);
}

void Animation::AddSprite(const char* fileName, int id)
{
	Image img;

	Bitmap::ReadBMP(fileName, &img);
	sprite[id].push_back(img);
}

void Animation::Play(int id)
{
	animId = id;
	index  = 0;
}

void Animation::Draw()
{
	//�ִϸ��̼� Ÿ�̸�..����//
	animTimer = animTimer + Time::deltaTime;

	//���ö���Ʈ �׸���//
	float px = GetPx();
	float py = GetPy();

	Bitmap::DrawBMP(px, py, &sprite[animId][index]);

	if (animTimer >= animDelay)
	{		
		index++;

		if ( index >= sprite[animId].size() )
		{
			index = 0;

			//�ִϸ޼� �Ϸ�..�̺�Ʈ//
			OnAnimationEnd();
		}

		animTimer = 0;  //Ÿ�̸� ����
	}
}

void Animation::Speed(float speed)
{
	animDelay = animDelay / speed;
}

void Animation::OnAnimationEnd()
{}