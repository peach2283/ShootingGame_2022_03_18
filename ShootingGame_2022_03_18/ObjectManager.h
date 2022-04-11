#pragma once
#include <vector>
#include "GameObject.h"

using namespace std;

class ObjectManager
{
private:
	static vector<GameObject*> gameObjects[6];
public:

	//���� Instance �߰� �� ���� //
	static void Instantiate(GameObject* obj, int layer=0);
	static void Destroy(GameObject* obj);

	//���� ��� ������Ʈ �Լ�
	static void Update();

	//���� ��ü �浹�˻� �Լ�
	static void CheckCollision();

	//���� ��� �׸���
	static void Draw();

	//���� ��� ��� �����ϱ� �Լ�
	static void Clear();

	//���� ������� ǥ�õ� ��ü�� �����ϱ� �Լ�//
	static void ClearDeadObject();
};

