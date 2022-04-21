#include "ShootingGame.h"

Sprite::Sprite(string tag, string name, bool active, float px, float py)
	  :GameObject(tag, name, active, px, py)
{
	sprite.width  = 0;
	sprite.height = 0;
	sprite.rgb	  = nullptr;

	this->enabled = true;
}

Sprite::~Sprite()
{
	if (sprite.rgb != nullptr)
	{
		delete[] sprite.rgb;
	}
}

void Sprite::SetSprite(const char* fileName)
{
	Bitmap::ReadBMP(fileName, &sprite);
}

void Sprite::SetSprite(const char* fileName, int x, int y, int width, int height)
{
	Bitmap::ReadBMP(fileName, x, y, width, height, &sprite);
}

void Sprite::Draw()
{
	if (enabled == true)
	{
		//스플라이트 그리기//
		float px = GetPx();
		float py = GetPy();

		Bitmap::DrawBMP(px, py, &sprite);
	}
}

void Sprite::ImageRect(int& width, int& height)
{
	width = sprite.width;
	height = sprite.height;
}