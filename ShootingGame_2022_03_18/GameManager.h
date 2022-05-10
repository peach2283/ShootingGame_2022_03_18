#pragma once

#include "GameObject.h"

class GameManager : public GameObject
{
private:	
	static GameManager* instance;
	
	float playerHp;     //�÷��̾� ü��
	int   playerCount;  //�÷��̾� ī��Ʈ
	bool  pause;        //���� �Ͻ� ���� ... ���� ����(true ��������, false ��������)

public:

	GameManager();
	~GameManager();

	void Start();
	void Update();

	void SpawnPlayer();

	void SetPause(bool pause);
	bool GetPause();

	//�÷��̾� ���� �����Լ�//
	void DamagePlayer(float damage);

	//�÷��̾� ü�� ��������//
	float GetPlayerHp();

	static GameManager* Instance();
};

