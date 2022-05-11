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
    hpBar = Instantiate(new HPBar(30, 48), 6);

    //플레이어..카운트..아이콘 추가하기
    icons[0] = Instantiate(new Icon(250, 5, "Asset/UI/Icon/PlayerIcon.bmp"), 6);
    icons[1] = Instantiate(new Icon(300, 5, "Asset/UI/Icon/PlayerIcon.bmp"), 6);
    icons[2] = Instantiate(new Icon(350, 5, "Asset/UI/Icon/PlayerIcon.bmp"), 6);

    //스코어..추가하기
    Instantiate(new Score(30, 10), 6);

    //폭탄 카운트..아이콘 추가하기
    
}

void UIManager::Update()
{
    //게임매니저..가져오기//
    GameManager* manager = GameManager::Instance();

    //일지정지 버튼..UI
    if (manager->GetPause() == true)
    {
        popupMenu->SetActive(true);
    }
    else {
        popupMenu->SetActive(false);
    }

    //플레이어 체력바
    float hp=manager->GetPlayerHp();

    ((HPBar*)hpBar)->SetFillAmount(hp/100); 

    //플레이어 카운트
    int count = manager->GetPlayerCount();

    for (int i = 0; i < 3; i++)
    {
        if (i < count)
        {
            icons[i]->SetActive(true);
        }
        else {
            icons[i]->SetActive(false);
        }
    }

}
