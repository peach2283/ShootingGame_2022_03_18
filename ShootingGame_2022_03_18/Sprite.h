#pragma once
#include "GameObject.h"
#include "BMP.h"

class Sprite : public GameObject
{
private:
	Image sprite;

public:

	bool enabled;  //스플라이트 사용가능 지정 변수

	Sprite(string tag, string name, bool active, float px, float py);
	~Sprite();

	void SetSprite(const char* fileName, int pvx=0, int pvy=0);
	void SetSprite(const char* fileName, int x, int y, int width, int height, int pvx=0, int pvy=0);

	void Draw();
	void ImageRect(int& width, int& height);
};

