#pragma once

#include "GameObject.h"

class GameManager : public GameObject
{
private:	
	static GameManager* instance;
	
	float playerHp;     //플레이어 체력
	
	int   playerCount;  //플레이어 카운트
	int   bombCount;    //폭탄 카운트
	int   score;        //게임 점수

	bool  pause;        //게임 일시 정지 ... 저장 변수(true 게임정지, false 게임진행)

public:

	GameManager();
	~GameManager();

	void Start();
	void Update();

	void SpawnPlayer();

	void SetPause(bool pause);
	bool GetPause();

	//플레이어 피해 적용함수//
	void DamagePlayer(float damage);

	//플레이어 체력 가져오기//
	float GetPlayerHp();

	//플레이어 카운트 가져오기//
	int GetPlayerCount();

	//게임점수 올리기 / 점수 가져오기 함수
	void AddScore(int score);
	int  GetScore();

	//폭탄카운트 가져오기
	int  GetBombCount();
	void SubBombCount();
	void AddBombCount();

	static GameManager* Instance();
};

