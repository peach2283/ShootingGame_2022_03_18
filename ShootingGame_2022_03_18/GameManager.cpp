#include "GameManager.h"

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

GameManager* GameManager::Instance()
{
	return instance;
}
