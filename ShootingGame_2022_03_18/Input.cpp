#include "ShootingGame.h"

//enum KeyCode            {UpArrow=0,       DownArrow=1     , LeftArrow=2    ,RightArrow=3    , Space=4        , Z=5 };

Input::State Input::state[6+3] = { State::keyUpRep, State::keyUpRep, State::keyUpRep,State::keyUpRep ,State::keyUpRep ,State::keyUpRep, State::keyUpRep , State::keyUpRep , State::keyUpRep };
int          Input::vKey [6+3] = { VK_UP          , VK_DOWN        , VK_LEFT        , VK_RIGHT        , VK_SPACE      ,   'Z' ,         VK_LBUTTON       , VK_RBUTTON     ,   VK_MBUTTON };

MousePosition Input::mousePosition = { 0,0 };

void Input::Update()
{
    for (int i = 0; i < 6 + 3; i++)
    {
        if (state[i] == State::keyUpRep) //�����ִ� ����
        {
            if (GetAsyncKeyState(vKey[i]) != 0)
            {
                state[i] = State::keyDown;  //������ ���·�..����
            }
        }
        else if (state[i] == State::keyDown) //������ ����
        {
            if (GetAsyncKeyState(vKey[i]) != 0)
            {
                state[i] = State::keyDownRep; //������ �ִ� ���·�...����
            }
            else {
                state[i] = State::keyUp; //���� ���·�...����
            }
        }
        else if (state[i] == State::keyDownRep) //������ �ִ� ����
        {
            if (GetAsyncKeyState(vKey[i]) == 0)
            {
                state[i] = State::keyUp;  //���� ���·�..����
            }
        }
        else if (state[i] == State::keyUp) //���� ����
        {
            if (GetAsyncKeyState(vKey[i]) == 0)
            {
                state[i] = State::keyUpRep; //���� ���� ���·�..����
            }
            else {
                state[i] = State::keyDown; //������ ���·�..����
            }
        }
    }
}

bool Input::GetKey(KeyCode code) //Ű�� ������ �ִ� ������ üũ�Լ�
{
    if (state[code] == State::keyDown || state[code] == State::keyDownRep)
    {
        return true;
    }
    else {
        return false;
    }
}

bool Input::GetKeyDown(KeyCode code) //Ű�� ���� üũ�Լ�
{
    if (state[code] == State::keyDown)
    {
        return true;
    }
    else {
        return false;
    }
}

bool Input::GetKeyUp(KeyCode code) //Ű�� ���� üũ�Լ�
{
    if (state[code] == State::keyUp)
    {
        return true;
    }
    else {
        return false;
    }
}

bool Input::GetMouseButton(int button)
{
    if (state[button + 6] == State::keyDownRep)
    {
        return true;
    }
    else {
        return false;
    }
}

bool Input::GetMouseButtonDown(int button)
{
    if (state[button + 6] == State::keyDown)
    {
        return true;
    }
    else {
        return false;
    }
}

bool Input::GetMouseButtonUp(int button)
{
    if (state[button + 6] == State::keyUp)
    {
        return true;
    }
    else {
        return false;
    }
}