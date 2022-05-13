#include "ShootingGame.h"

Scene::Scene(string name)
{
    this->name = name;
}

Scene::~Scene()
{}

void Scene::Load()
{
}

void Scene::Run()
{
    //��ü��� ������Ʈ
    ObjectManager::Update();

    //��ü �浹�˻�
    ObjectManager::CheckCollision();

    //���� ��� ��ü �����ϱ�//
    ObjectManager::ClearDeadObject();

    //�׸���
    ObjectManager::Draw();
}

void Scene::Unload()
{
    ObjectManager::Clear(); //���Ӱ�ü ���..��ü ����
}

string Scene::GetName()
{
    return name;
}