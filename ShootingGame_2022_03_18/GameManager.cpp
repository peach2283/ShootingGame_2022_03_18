#include "ShootingGame.h"

GameManager* GameManager::instance = nullptr;

GameManager::GameManager() : GameObject("", "", true, 0,0)
{
	this->playerHp    = 100;   //�÷��̾� ü�� �ʱ�ȭ
	this->playerCount = 3;     //�÷��̾� ����
	this->bombCount   = 5;     //��ź ����
	this->pause       = false; //������ ���� �ƴ�
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
		playerHp = 100;    //�÷��̾� ü�� ����

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

int GameManager::GetPlayerCount()
{
	return playerCount;
}

int  GameManager::GetBombCount()
{
	return bombCount;
}

void GameManager::SubBombCount()
{
	bombCount--;
}

void GameManager::AddBombCount()
{
	bombCount++;

	if (bombCount > 8)  //�ִ� ��ź������ 8 ����..����(������ ����)
	{
		bombCount = 8;
	}
}

GameManager* GameManager::Instance()
{
	return instance;
}
