#pragma once

#include <vector>;
#include "GameObject.h"
#include "BMP.h"

using namespace std;

class Animation : public GameObject
{
private:
	vector<Image> sprite;
	int   index;

	//애니메이션 타이머//
	float animTimer;
	float animDelay;

public:
	Animation(string tag, string name, bool active, float px, float py);
	~Animation();

	//애니메이션 추가 함수//
	void AddSprite(const char* fileName, int x, int y, int width, int height);

	//애니메이션 기능 테스트 추가 함수//
	void Start();
	void Update();
	void Draw();
};

