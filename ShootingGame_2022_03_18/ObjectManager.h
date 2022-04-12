#pragma once
#include <vector>
#include "GameObject.h"

using namespace std;

#define MAX_LAYER 8

class ObjectManager
{
private:
	static vector<GameObject*> gameObjects[MAX_LAYER];
public:

	//���� Instance �߰� �� ���� //
	static void Instantiate(GameObject* obj, int layer=0);
	static void Destroy(GameObject* obj);

	//���� ��� ������Ʈ �Լ�
	static void Update();

	//���� ��ü �浹�˻� �Լ�
	static void CheckCollision();
	static void CheckCollisionObjectPair(GameObject* obji, GameObject* objj);

	//���� ��� �׸���
	static void Draw();

	//���� ��� ��� �����ϱ� �Լ�
	static void Clear();

	//���� ������� ǥ�õ� ��ü�� �����ϱ� �Լ�//
	static void ClearDeadObject();
};

