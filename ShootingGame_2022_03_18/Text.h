#pragma once

#include "GameObject.h"
#include <ft2build.h>
#include <freetype/freetype.h>

class Text : public GameObject
{
private:
	FT_Library library;
	FT_Face    face;

	//��Ʈ ���Ͽ���..�۲� ã�ƿ���
	wstring text;

	//��Ʈ ũ��
	int size;

	//��Ʈ ��
	unsigned char r;
	unsigned char g;
	unsigned char b;

public:
	Text(wstring text, int size, float px, float py, unsigned char r=255, unsigned char g=255, unsigned char b=255);
	~Text();

	void Start();
	void Update();
	void Draw();

	void SetText(wstring text);
};
