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

void Sprite::SetSprite(const char* fileName, int pvx, int pvy)
{
	if (sprite.rgb != nullptr)
	{
		delete[] sprite.rgb;  //기존에 로드한 이미지 메모리 삭제
	}

	Bitmap::ReadBMP(fileName, &sprite);

	sprite.pvx = pvx;
	sprite.pvy = pvy;
}

void Sprite::SetSprite(const char* fileName, int x, int y, int width, int height, int pvx, int pvy)
{
	if (sprite.rgb != nullptr)
	{
		delete[] sprite.rgb;  //기존에 로드한 이미지 메모리 삭제
	}

	Bitmap::ReadBMP(fileName, x, y, width, height, &sprite);

	sprite.pvx = pvx;
	sprite.pvy = pvy;
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