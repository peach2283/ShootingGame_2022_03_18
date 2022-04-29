#pragma once

#include "GameObject.h"

class GameManager : public GameObject
{
private:
	
	static GameManager* instance;

public:

	int playerCount;  //플레이어 카운트

	GameManager();
	~GameManager();

	void Start();
	void Update();

	static GameManager* Instance();
};

