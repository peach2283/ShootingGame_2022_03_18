#pragma once

#include "GameObject.h"

class GameManager : public GameObject
{
private:	
	static GameManager* instance;
	
	float playerHp;     //�÷��̾� ü��
	
	int   playerCount;  //�÷��̾� ī��Ʈ
	int   bombCount;    //��ź ī��Ʈ

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

	//�÷��̾� ī��Ʈ ��������//
	int GetPlayerCount();

	//��źī��Ʈ ��������
	int  GetBombCount();
	void SubBombCount();
	void AddBombCount();

	static GameManager* Instance();
};

