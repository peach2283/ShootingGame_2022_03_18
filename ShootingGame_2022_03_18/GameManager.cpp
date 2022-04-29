#include "ShootingGame.h"

GameManager* GameManager::instance = nullptr;

GameManager::GameManager() : GameObject("", "", true, 0,0)
{
	this->playerCount = 3; //플레이어 갯수
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
		Instantiate(new Player(WIDTH / 2 - 34, HEIGHT + 100), 1);
	}
	else {
		Instantiate(new GameOver(30, 200), 5);
	}
}

GameManager* GameManager::Instance()
{
	return instance;
}
