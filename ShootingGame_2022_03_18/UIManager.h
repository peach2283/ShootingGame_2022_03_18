#pragma once

#include "GameObject.h"

class UIManager : public GameObject
{
private:
	//�˾� �޴�..���ӿ�����Ʈ..������//
	GameObject* popupMenu;

	//�÷��̾� ü�¹� ���ӿ�����Ʈ..������//
	GameObject* hpBar;

public:
	UIManager();
	~UIManager();

	void Start();
	void Update();
};

