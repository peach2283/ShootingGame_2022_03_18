#pragma once
#include "GameObject.h"
#include "BMP.h"

class Sprite : public GameObject
{
private:
	Image sprite;

public:

	bool enabled;  //���ö���Ʈ ��밡�� ���� ����

	Sprite(string tag, string name, bool active, float px, float py);
	~Sprite();

	void SetSprite(const char* fileName, int pvx=0, int pvy=0);
	void SetSprite(const char* fileName, int x, int y, int width, int height, int pvx=0, int pvy=0);

	void Draw();
	void ImageRect(int& width, int& height);
};

