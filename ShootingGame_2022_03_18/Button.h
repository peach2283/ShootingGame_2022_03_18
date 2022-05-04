#pragma once
#include "Sprite.h"

class Button : public Sprite
{
	//��ư ����..enum//
	enum State {normal=0, hover=1, click=2};

private:
	State state;  //��ư..���� ����

	//normal, hover, click �̹���..���//
	string normalImg;
	string hoverImg;
	string clickImg;

public:
	Button(float px, float py);
	~Button();

	void Start();
	void Update();

	//���콺..��ǥ��..�̹��� �ȿ� �ִ��� �˻��ϴ� �Լ�//
	bool IsInImageRect();

	void SetNormalImg(string fileName);
	void SetHoverImg (string fileName);
	void SetClickImg (string fileName);
};

