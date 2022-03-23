#include "ShootingGame.h"

State Input::state[6] = { State::keyUpRep, State::keyUpRep, State::keyUpRep,State::keyUpRep ,State::keyUpRep ,State::keyUpRep };
int   Input::vKey[6]  = { VK_UP          , VK_DOWN        , VK_LEFT        , VK_RIGHT        , VK_SPACE      ,   'Z' };

void Input::Update()
{
    for (int i = 0; i < 6; i++)
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

bool Input::GetKey(int i) //Ű�� ������ �ִ� ������ üũ�Լ�
{
    if (state[i] == State::keyDownRep)
    {
        return true;
    }
    else {
        return false;
    }
}

bool Input::GetKeyDown(int i) //Ű�� ���� üũ�Լ�
{
    if (state[i] == State::keyDown)
    {
        return true;
    }
    else {
        return false;
    }
}

bool Input::GetKeyUp(int i) //Ű�� ���� üũ�Լ�
{
    if (state[i] == State::keyUp)
    {
        return true;
    }
    else {
        return false;
    }
}