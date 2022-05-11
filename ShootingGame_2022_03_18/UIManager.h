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
	GameObject* playerIcons[3];

	//��ź ������..��ü ������//
	GameObject* bombIcons[8];

public:
	UIManager();
	~UIManager();

	void Start();
	void Update();
};

