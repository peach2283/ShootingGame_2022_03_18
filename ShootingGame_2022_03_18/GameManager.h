#pragma once

#include "GameObject.h"

class GameManager : public GameObject
{
private:	
	static GameManager* instance;
	
	float playerHp;     //�÷��̾� ü��
	
	int   playerCount;  //�÷��̾� ī��Ʈ
	int   bombCount;    //��ź ī��Ʈ
	int   score;        //���� ����

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

	//�������� �ø��� / ���� �������� �Լ�
	void AddScore(int score);
	int  GetScore();

	//��źī��Ʈ ��������
	int  GetBombCount();
	void SubBombCount();
	void AddBombCount();

	static GameManager* Instance();
};

