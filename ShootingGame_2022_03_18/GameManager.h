#pragma once

#include "GameObject.h"

class GameManager : public GameObject
{
private:
	
	static GameManager* instance;
	int playerCount;  //플레이어 카운트

public:

	GameManager();
	~GameManager();

	void Start();
	void Update();

	void SpawnPlayer();

	static GameManager* Instance();
};

