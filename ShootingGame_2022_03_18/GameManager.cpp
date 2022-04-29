#include "GameManager.h"

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

GameManager* GameManager::Instance()
{
	return instance;
}
