#pragma once

#include "GameObject.h"

class GameManager : public GameObject
{
private:	
	static GameManager* instance;
	
	int   playerCount;  //플레이어 카운트
	bool  pause;        //게임 일시 정지 ... 저장 변수(true 게임정지, false 게임진행)

public:

	GameManager();
	~GameManager();

	void Start();
	void Update();

	void SpawnPlayer();

	void SetPause(bool pause);
	bool GetPause();

	static GameManager* Instance();
};

