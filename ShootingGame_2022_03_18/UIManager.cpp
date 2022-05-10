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
    hpBar = Instantiate(new HPBar(30, 10), 6);
}

void UIManager::Update()
{
    //���ӸŴ���..��������//
    GameManager* manager = GameManager::Instance();

    //�������� ��ư..UI
    if (manager->GetPause() == true)
    {
        popupMenu->SetActive(true);
    }
    else {
        popupMenu->SetActive(false);
    }

    //�÷��̾� ü�¹�
    float hp=manager->GetPlayerHp();

    ((HPBar*)hpBar)->SetFillAmount(hp/100); 
}
