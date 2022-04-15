#pragma once

#include <vector>;
#include "GameObject.h"
#include "BMP.h"

using namespace std;

class Animation : public GameObject
{
private:
	vector<Image> sprite[3];
	
	int   index;

	//�ִϸ��̼� Ÿ�̸�//
	float animTimer;
	float animDelay;

	//�ִϸ��̼� ���̵�//
	int animId;

public:
	Animation(string tag, string name, bool active, float px, float py);
	~Animation();

	//�ִϸ��̼� �߰� �Լ�//
	void AddSprite(const char* fileName, int x, int y, int width, int height,  int id);
	void AddSprite(const char* fileName, int id);

	//���� �ִϸ��̼� �����Լ�//
	void Play(int id);

	//�ִϸ��̼� ��� �Լ�//
	void Draw();

	//�ִϸ��̼� �ӵ� ����//
	void Speed(float speed);

	//�ִϸ��̼� �Ϸ� �̺�Ʈ..�����Լ�//
	virtual void OnAnimationEnd();
};

