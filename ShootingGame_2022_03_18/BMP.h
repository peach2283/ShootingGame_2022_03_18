#pragma once

//���ӿ��� ������ ���Ǵ� �̹��� ���� ����ü//
struct Image
{
	int width;
	int height;
	unsigned int* rgb;
};

class Bitmap
{
private:
public:
	static void ReadBMP(const char* fileName, Image* img);
	static void DrawBMP(float px, float py, Image* img);
};


