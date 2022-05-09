#include "ShootingGame.h"

UIManager::UIManager() : GameObject("","",true, 0,0)
{}

UIManager::~UIManager()
{}

void UIManager::Start()
{
    //�Ͻ����� ��ư..�߰��ϱ�
    Instantiate(new Pause(430, 5), 6);

    //�˾� �޴�..�߰��ϱ�
    popupMenu = Instantiate(new PopupMenu(122, 300), 6);

    //ü�¹� �߰��ϱ�
    Instantiate(new HPBar(10, 10), 6);
}

void UIManager::Update()
{
    //���ӸŴ���..��������//
    GameManager* manager = GameManager::Instance();

    if (manager->GetPause() == true)
    {
        popupMenu->SetActive(true);
    }
    else {
        popupMenu->SetActive(false);
    }
}
