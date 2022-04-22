#include "ShootingGame.h"

//������, �Ҹ���//
GameObject::GameObject(string tag, string name, bool active, float px, float py)
{
	this->tag	 = tag;
	this->name	 = name;
	this->active = active;

	this->px = px;
	this->py = py;

	this->isDead = false;   //������� �ƴ� ǥ��
	this->parent = nullptr; //��ü..�����ڿ����� �θ�ü�� ����
}

GameObject::~GameObject()
{}

//����, ����//
string GameObject::GetTag()
{
	return tag;
}

string GameObject::GetName()
{
	return name;
}

bool GameObject::GetActive()
{
	return active;
}

bool GameObject::GetDead()
{
	return isDead;
}

float GameObject::GetPx()
{
	return px;
}

float GameObject::GetPy()
{
	return py;
}

void GameObject::GetPosition(float& px, float& py)
{
	px = this->px;
	py = this->py;
}

void GameObject::SetTag(string tag)
{
	this->tag = tag;
}

void GameObject::SetName(string name)
{
	this->name = name;
}

void GameObject::SetActive(bool active)
{
	this->active = active;
}

void GameObject::SetDead(bool dead)
{
	this->isDead = dead;

	for (int i = 0; i < childObjects.size(); i++)
	{
		childObjects[i]->SetDead(dead);
	}
}

void GameObject::SetPx(float px)
{
	//���ο� ��ġ��(px) - ���������� x ��ǥ(this->px) = �̵���(dx)//
	float dx = px - this->px; //�̵���

	this->px = px; //���ӿ�����Ʈ ��ġ ����

	//�浹ü��..�̵��� �����ϱ�//
	for (int i = 0; i < collider.size(); i++)
	{
		collider[i].Translate(dx, 0);
	}

	//�ڽİ�ü��..�̵��� �����ϱ�//
	for (int i = 0; i < childObjects.size(); i++)
	{
		childObjects[i]->Translate(dx, 0);
	}
}

void GameObject::SetPy(float py)
{
	float dy = py - this->py; //�̵���

	this->py = py; //���ӿ�����Ʈ ��ġ ����

	//�浹ü..�̵��� �����ϱ�//
	for (int i = 0; i < collider.size(); i++)
	{
		collider[i].Translate(0, dy);
	}

	//�ڽİ�ü��..�̵��� �����ϱ�//
	for (int i = 0; i < childObjects.size(); i++)
	{
		childObjects[i]->Translate(0, dy);
	}
}

void GameObject::Translate(float x, float y)
{
	//���ӿ�����Ʈ...��ǥ �̵�//
	px = px + x;
	py = py + y;

	//�浹ü...��ǥ �̵�//	
	for (int i = 0; i < collider.size(); i++)
	{
		collider[i].Translate(x, y);
	}

	//�ڽİ�ü..��ǥ �̵�//
	for (int i = 0; i < childObjects.size(); i++)
	{
		childObjects[i]->Translate(x, y);
	}
}

void GameObject::AddBoxCollider2D(float x, float y, float width, float height)
{
	collider.push_back( BoxCollider2D(x + px, y + py, width, height) );
}

vector<BoxCollider2D> GameObject::GetCollider()
{
	return collider;
}

void GameObject::Draw()
{}

void GameObject::OnDrawGizmos()
{
	for (int i = 0; i < collider.size(); i++)
	{
		//�ڽ� �浹ü..�簢�� �׸���//
		float x, y, width, height;

		collider[i].GetBox(x, y, width, height);

		//������ �ϴ� ��ǥ
		float x2 = x + width;
		float y2 = y + height;

		//�����׸���
		DrawLine(x, y, x2, y, 255, 0, 0);
		DrawLine(x2, y, x2, y2, 255, 0, 0);
		DrawLine(x, y2, x2, y2, 255, 0, 0);
		DrawLine(x, y, x, y2, 255, 0, 0);
	}
}

void GameObject::OnTriggerStay2D(GameObject * other)
{	
}

GameObject * GameObject::Instantiate(GameObject* obj, int layer)
{
	ObjectManager::Instantiate(obj, layer);
	return obj;
}

/**************************************************
void GameObject::SetDead(bool dead)
{
	this->isDead = dead;

	for (int i = 0; i < childObjects.size(); i++)
	{
		childObjects[i]->SetDead(dead);
	}
}
*************************************************/

void GameObject::Destroy(GameObject* obj)
{
	//�ڽİ�ü��..���ŵɶ�..�θ�..��ü��..��Ͽ���...������ .. obj�� �ڽİ�ü...obj�� �θ�..obj->parent
	if (obj->parent != nullptr)
	{
		vector<GameObject*> &child = obj->parent->childObjects;

		for (int i = 0; i < child.size(); i++)
		{
			if (child[i] == obj)
			{
				child.erase(child.begin() + i);
				i--;
			}
		}
	}

	ObjectManager::Destroy(obj);
}

void GameObject::AddChildObject(GameObject* child, int layer)
{
	child->parent = this;  //this�� child ��ü�� �θ�..��ü������

	childObjects.push_back(child);

	//�ڽİ�ü�� �θ� ��ǥ ��������..�̵���Ű��
	child->Translate(px, py);

	ObjectManager::Instantiate(child, layer);
}

GameObject* GameObject::Find(string name)
{
	for (int i = 0; i < childObjects.size(); i++)
	{
		if (childObjects[i]->GetName() == name)
		{
			return childObjects[i];  //ã�� �ڽ� ��ü �����͸� ��ȯ��
		}
	}

	//ã������ �ڽ� ��ü�� ��Ͽ� ����
	return nullptr;
}