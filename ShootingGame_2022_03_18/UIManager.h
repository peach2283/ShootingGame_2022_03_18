#pragma once

#include "GameObject.h"

class UIManager : public GameObject
{
private:
	//�˾� �޴�..���ӿ�����Ʈ..������//
	GameObject* popupMenu;

public:
	UIManager();
	~UIManager();

	void Start();
	void Update();
};

