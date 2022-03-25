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

	//�ִϸ��̼� Ÿ�̸�//
	float animTimer;
	float animDelay;

public:
	Animation(string tag, string name, bool active, float px, float py);
	~Animation();

	//�ִϸ��̼� �߰� �Լ�//
	void AddSprite(const char* fileName, int x, int y, int width, int height);

	//�ִϸ��̼� ��� �׽�Ʈ �߰� �Լ�//
	void Start();
	void Update();
	void Draw();
};

