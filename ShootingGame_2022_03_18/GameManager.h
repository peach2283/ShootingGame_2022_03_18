#pragma once

#include "GameObject.h"

class GameManager : public GameObject
{
private:
	
	static GameManager* instance;

public:

	int playerCount;  //�÷��̾� ī��Ʈ

	GameManager();
	~GameManager();

	void Start();
	void Update();

	static GameManager* Instance();
};

