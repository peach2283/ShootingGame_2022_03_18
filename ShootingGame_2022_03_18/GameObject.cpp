#include "ShootingGame.h"

//������, �Ҹ���//
GameObject::GameObject(string tag, string name, bool active, float px, float py)
{
	this->tag	 = tag;
	this->name	 = name;
	this->active = active;

	this->px = px;
	this->py = py;
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

float GameObject::GetPx()
{
	return px;
}

float GameObject::GetPy()
{
	return py;
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

void GameObject::SetPx(float px)
{
	//���ο� ��ġ��(px) - ���������� x ��ǥ(this->px) = �̵���(dx)//
	float dx = px - this->px; //�̵���

	this->px = px; //���ӿ�����Ʈ ��ġ ����

	//�浹ü��..�̵��� �����ϱ�//
	collider.Translate(dx, 0);
}

void GameObject::SetPy(float py)
{
	float dy = py - this->py; //�̵���

	this->py = py; //���ӿ�����Ʈ ��ġ ����

	//�浹ü..�̵��� �����ϱ�//
	collider.Translate(0, dy);
}

void GameObject::Translate(float x, float y)
{
	//���ӿ�����Ʈ...��ǥ �̵�//
	px = px + x;
	py = py + y;

	//�浹ü...��ǥ �̵�//	
	collider.Translate(x, y);
}

void GameObject::AddBoxCollider2D(float x, float y, float width, float height)
{
	collider = BoxCollider2D(x + px, y + py, width, height);
}

BoxCollider2D GameObject::GetCollider()
{
	return collider;
}

void GameObject::OnDrawGizmos()
{
	//�ڽ� �浹ü..�簢�� �׸���//
	float x, y, width, height;

	collider.GetBox(x, y, width, height);

	//������ �ϴ� ��ǥ
	float x2 = x + width;
	float y2 = y + height;

	//�����׸���
	DrawLine(x ,  y, x2,  y, 255, 0, 0);
	DrawLine(x2,  y, x2, y2, 255, 0, 0);
	DrawLine(x , y2, x2, y2, 255, 0, 0);
	DrawLine(x,   y, x , y2, 255, 0, 0);

}

void GameObject::OnTriggerStay2D()
{	
}

void GameObject::Instantiate(GameObject* obj)
{
	ObjectManager::Instantiate(obj);
}

void GameObject::Destroy(GameObject* obj)
{
	ObjectManager::Destroy(obj);
}