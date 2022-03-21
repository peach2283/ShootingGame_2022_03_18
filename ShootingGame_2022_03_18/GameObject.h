#pragma once
#include <string>

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

public:
	//������, �Ҹ���//
	GameObject(string tag, string name, bool active, float px, float py);
	virtual ~GameObject();

	//����, ����//
	string GetTag();
	string GetName();
	bool   GetActive();

	float GetPx();
	float GetPy();

	void SetTag(string tag);
	void SetName(string name);
	void SetActive(bool active);

	void SetPx(float px);
	void SetPy(float py);

	//�⺻ �����Լ�//
	virtual void Start()  = 0;
	virtual void Update() = 0;
	virtual void Draw()   = 0;

	//��Ÿ Ȱ�� �Լ�//
	void Translate(float x, float y);

	//���ӿ�����Ʈ �߰�/�����ϱ�//
	void Instantiate(GameObject* obj);
	void Destroy(GameObject* obj);

};

