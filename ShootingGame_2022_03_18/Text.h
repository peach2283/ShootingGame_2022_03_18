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

public:
	Text(wstring text, float px, float py);
	~Text();

	void Start();
	void Update();
	void Draw();
};
