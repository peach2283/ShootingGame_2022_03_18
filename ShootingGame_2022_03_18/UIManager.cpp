#include "ShootingGame.h"

UIManager::UIManager() : GameObject("","",true, 0,0)
{}

UIManager::~UIManager()
{}

void UIManager::Start()
{
    //일시중지 버튼..추가하기
    Instantiate(new Pause(430, 5), 6);

    //팝업 메뉴..추가하기
    popupMenu = Instantiate(new PopupMenu(122, 300), 6);

    //체력바 추가하기
    Instantiate(new HPBar(10, 10), 6);
}

void UIManager::Update()
{
    //게임매니저..가져오기//
    GameManager* manager = GameManager::Instance();

    if (manager->GetPause() == true)
    {
        popupMenu->SetActive(true);
    }
    else {
        popupMenu->SetActive(false);
    }
}
