#include "ShootingGame.h"

GameManager* GameManager::instance = nullptr;

GameManager::GameManager() : GameObject("", "", true, 0,0)
{
	this->playerCount = 3; //�÷��̾� ����
}

GameManager::~GameManager()
{}

void GameManager::Start()
{
	instance = this;  //[����Ƽ] Awake���� ��
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
