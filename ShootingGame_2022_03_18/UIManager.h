#pragma once

#include "GameObject.h"

class UIManager : public GameObject
{
private:
	//팝업 메뉴..게임오브젝트..포인터//
	GameObject* popupMenu;

public:
	UIManager();
	~UIManager();

	void Start();
	void Update();
};

