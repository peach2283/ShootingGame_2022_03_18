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

public:
	Text(wstring text, float px, float py);
	~Text();

	void Start();
	void Update();
	void Draw();
};
