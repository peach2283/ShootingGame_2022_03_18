#pragma once

//�ڽ� �浹ü ... ������Ʈ Ŭ����//
class BoxCollider2D
{
private:
	float x;
	float y;
	float widt;
	float height;

public:
	BoxCollider2D();
	BoxCollider2D(float x, float y, float width, float height);
	
	virtual ~BoxCollider2D();
};

