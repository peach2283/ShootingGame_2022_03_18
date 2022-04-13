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

void Sprite::Draw()
{
	if (enabled == true)
	{
		//���ö���Ʈ �׸���//
		float px = GetPx();
		float py = GetPy();

		Bitmap::DrawBMP(px, py, &sprite);
	}
}
