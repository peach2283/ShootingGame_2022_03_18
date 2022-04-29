#pragma once

#include "GameObject.h"

class GameManager : public GameObject
{
private:
	
	static GameManager* instance;
	int playerCount;  //�÷��̾� ī��Ʈ

public:

	GameManager();
	~GameManager();

	void Start();
	void Update();

	void SpawnPlayer();

	static GameManager* Instance();
};

