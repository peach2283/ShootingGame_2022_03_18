#pragma once
#include <string>
#include <vector>
#include "BoxCollider2D.h"

using namespace std;

class GameObject
{
private:
	//�⺻�Ӽ�(�ν����� - Inspector)//
	string tag;
	string name;
	bool   active;

	//��ȯ�Ӽ�(Ʈ������ - Transform)//
	float px, py;

	//�ڽ� �ݶ��̾� 2D (BoxCollider2D)..�߰��ϱ�//
	vector<BoxCollider2D> collider;

	//��ü ���� ǥ�� ����
	bool isDead;  // true�� ���� ���, false�� ���� ����� �ƴ�

public:
	//������, �Ҹ���//
	GameObject(string tag, string name, bool active, float px, float py);
	virtual ~GameObject();

	//����, ����//
	string GetTag();
	string GetName();
	bool   GetActive();
	bool   GetDead();

	float GetPx();
	float GetPy();

	void SetTag(string tag);
	void SetName(string name);
	void SetActive(bool active);
	void SetDead(bool deal);

	void SetPx(float px);
	void SetPy(float py);

	//�⺻ �����Լ�//
	virtual void Start()  = 0;
	virtual void Update() = 0;
	virtual void Draw()   = 0;

	//��Ÿ Ȱ�� �Լ�//
	void Translate(float x, float y);

	//�浹 �ڽ�..����� �׸��� �Լ�..
	void OnDrawGizmos();

	//���ӿ�����Ʈ �߰�/�����ϱ�//
	void Instantiate(GameObject* obj);
	void Destroy(GameObject* obj);

	//�浹ü �߰��ϱ�//
	void AddBoxCollider2D(float x, float y, float width, float height);

	//�浹ü ����//
	vector<BoxCollider2D> GetCollider();

	//�浹 ���� ó���Լ�//
	virtual void OnTriggerStay2D(GameObject * other);
};

