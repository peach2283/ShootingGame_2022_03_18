#pragma once

#include "GameObject.h"

class UIManager : public GameObject
{
private:
	//팝업 메뉴..게임오브젝트..포인터//
	GameObject* popupMenu;

	//플레이어 체력바 게임오브젝트..포인터//
	GameObject* hpBar;

	//플레이어 아이콘..객체 포인터//
	GameObject* playerIcons[3];

	//폭탄 아이콘..객체 포인터//
	GameObject* bombIcons[8];

	//점수 출력 객체 포인터//
	GameObject* score;

public:
	UIManager();
	~UIManager();

	void Start();
	void Update();
};

