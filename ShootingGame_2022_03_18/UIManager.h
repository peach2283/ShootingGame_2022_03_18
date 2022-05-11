#pragma once

#include "GameObject.h"

class UIManager : public GameObject
{
private:
	//�˾� �޴�..���ӿ�����Ʈ..������//
	GameObject* popupMenu;

	//�÷��̾� ü�¹� ���ӿ�����Ʈ..������//
	GameObject* hpBar;

	//�÷��̾� ������..��ü ������//
	GameObject* icons[3];

public:
	UIManager();
	~UIManager();

	void Start();
	void Update();
};

