#pragma once

#include "GameObject.h"
#include <ft2build.h>
#include <freetype/freetype.h>

class Text : public GameObject
{
private:
	FT_Library library;
	FT_Face    face;

	//폰트 파일에서..글꼴 찾아오기
	wstring text;

	//폰트 크기
	int size;

	//폰트 색
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
