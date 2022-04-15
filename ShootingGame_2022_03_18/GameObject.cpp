#include "ShootingGame.h"

//생성자, 소멸자//
GameObject::GameObject(string tag, string name, bool active, float px, float py)
{
	this->tag	 = tag;
	this->name	 = name;
	this->active = active;

	this->px = px;
	this->py = py;

	this->isDead = false;  //삭제대상 아님 표시
}

GameObject::~GameObject()
{}

//게터, 세터//
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
}

void GameObject::SetPx(float px)
{
	//새로운 위치값(px) - 변경이전의 x 좌표(this->px) = 이동값(dx)//
	float dx = px - this->px; //이동량

	this->px = px; //게임오브젝트 위치 지정

	//충돌체에..이동량 적용하기//
	for (int i = 0; i < collider.size(); i++)
	{
		collider[i].Translate(dx, 0);
	}

	//자식객체에..이동량 적용하기//
	for (int i = 0; i < childObjects.size(); i++)
	{
		childObjects[i]->Translate(dx, 0);
	}
}

void GameObject::SetPy(float py)
{
	float dy = py - this->py; //이동량

	this->py = py; //게임오브젝트 위치 지정

	//충돌체..이동량 적용하기//
	for (int i = 0; i < collider.size(); i++)
	{
		collider[i].Translate(0, dy);
	}

	//자식객체에..이동량 적용하기//
	for (int i = 0; i < childObjects.size(); i++)
	{
		childObjects[i]->Translate(0, dy);
	}
}

void GameObject::Translate(float x, float y)
{
	//게임오브젝트...좌표 이동//
	px = px + x;
	py = py + y;

	//충돌체...좌표 이동//	
	for (int i = 0; i < collider.size(); i++)
	{
		collider[i].Translate(x, y);
	}

	//자식객체..좌표 이동//
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
		//박스 충돌체..사각형 그리기//
		float x, y, width, height;

		collider[i].GetBox(x, y, width, height);

		//오른쪽 하단 좌표
		float x2 = x + width;
		float y2 = y + height;

		//직선그리기
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

void GameObject::Destroy(GameObject* obj)
{
	ObjectManager::Destroy(obj);
}

void GameObject::AddChildObject(GameObject* child, int layer)
{
	childObjects.push_back(child);

	//자식객체를 부모 좌표 기준으로..이동시키기
	child->Translate(px, py);

	ObjectManager::Instantiate(child, layer);
}