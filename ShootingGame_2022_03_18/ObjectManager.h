#pragma once
#include <vector>
#include "GameObject.h"

using namespace std;

class ObjectManager
{
private:
	static vector<GameObject*> gameObjects;
public:

	//���� Instance �߰� �� ���� //
	static void Instantiate(GameObject* obj);
	static void Destroy(GameObject* obj);

	//���� ��� ������Ʈ �Լ�
	static void Update();

	//���� ��� �׸���
	static void Draw();

	//���� ��� ��� �����ϱ� �Լ�
	static void Clear();
};

