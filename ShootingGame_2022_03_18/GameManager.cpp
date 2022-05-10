#include "ShootingGame.h"

GameManager* GameManager::instance = nullptr;

GameManager::GameManager() : GameObject("", "", true, 0,0)
{
	this->playerHp   = 100;    //플레이어 체력 초기화
	this->playerCount = 3;     //플레이어 갯수
	this->pause       = false; //게임이 중지 아님
}

GameManager::~GameManager()
{}

void GameManager::Start()
{
	instance = this;  //[유니티] Awake에서 함
}

void GameManager::Update()
{}

void GameManager::SpawnPlayer()
{
	playerCount--;

	if (playerCount > 0)
	{		
		playerHp = 100;    //플레이어 체력 리셋

		Instantiate(new Player(WIDTH / 2 - 34, HEIGHT + 100), 1);
	}
	else {
		Instantiate(new GameOver(30, 200), 5);
	}
}

void GameManager::SetPause(bool pause)
{
	this->pause = pause;
}

bool GameManager::GetPause()
{
	return pause;
}

void GameManager::DamagePlayer(float damage)
{
	playerHp = playerHp - damage;
}

float GameManager::GetPlayerHp()
{
	return playerHp;
}

GameManager* GameManager::Instance()
{
	return instance;
}
