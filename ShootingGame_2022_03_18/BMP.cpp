#include "ShootingGame.h"

void Bitmap::ReadBMP(const char* fileName, Image* img)
{
	//��Ʈ�� ����ü
	BITMAPFILEHEADER fileHeader; //��Ʈ�� �������
	BITMAPINFOHEADER infoHeader; //��Ʈ�� �������

	//��Ʈ��(bmp) ���� �ε��ϱ�//
	FILE* stream;
	errno_t err;

	err = fopen_s(&stream, fileName, "rb");

	if (err == 0 && stream != nullptr)
	{
		//��Ʈ�� ������� ����ü �ε��ϱ�//
		fread(&fileHeader, sizeof(BITMAPFILEHEADER), 1, stream);

		//printf("--------��Ʈ�� ���� ��� ����ü--------\n");
		//printf("bfType : 0x%x\n", fileHeader.bfType);  //���ϳ��ο��� bmp���������� ��Ȯ���ϴ� �ڵ�(�����ڵ�)
		//printf("bfSize : %d\n", fileHeader.bfSize);  //���� ũ��
		//printf("bfReserved1 : %d\n", fileHeader.bfReserved1); //���ȵǴ� ����
		//printf("bfReserved2 : %d\n", fileHeader.bfReserved2); //���ȵǴ� ����
		//printf("bfOffBits   : %d\n", fileHeader.bfOffBits);   //�ȼ�����Ÿ ������ Offset(ó������..������ ����)


		//��Ʈ�� ������� ����ü �ε��ϱ�//
		fread(&infoHeader, sizeof(BITMAPINFOHEADER), 1, stream);

		//printf("------��Ʈ�� ���� ��� ����ü ------\n");
		//printf("biWidth : %d\n", infoHeader.biWidth);
		//printf("biHeight: %d\n", infoHeader.biHeight);
		//printf("biBitCount : %d\n", infoHeader.biBitCount);

		//�̹��� ����Ÿ(�ȼ�����Ÿ) �ε��ϱ�//
		int length = infoHeader.biWidth * infoHeader.biHeight;
		unsigned int* rgb = new unsigned int[length];

		fread(rgb, sizeof(unsigned int), length, stream);

		//���ϴݱ�
		fclose(stream);

		//�̹��� ����ü��..�ʿ��� ������ ������//
		img->width = infoHeader.biWidth;
		img->height = infoHeader.biHeight;
		img->rgb = rgb;

	}
	else {
		printf("���� ���� ����\n");
	}
}

void Bitmap::ReadBMP(const char* fileName, int x, int y, int width, int height, Image* img)
{
	//��Ʈ�� ����ü
	BITMAPFILEHEADER fileHeader; //��Ʈ�� �������
	BITMAPINFOHEADER infoHeader; //��Ʈ�� �������

	//��Ʈ��(bmp) ���� �ε��ϱ�//
	FILE* stream;
	errno_t err;

	err = fopen_s(&stream, fileName, "rb");

	if (err == 0 && stream != nullptr)
	{
		//��Ʈ�� ������� ����ü �ε��ϱ�//
		fread(&fileHeader, sizeof(BITMAPFILEHEADER), 1, stream);

		//printf("--------��Ʈ�� ���� ��� ����ü--------\n");
		//printf("bfType : 0x%x\n", fileHeader.bfType);  //���ϳ��ο��� bmp���������� ��Ȯ���ϴ� �ڵ�(�����ڵ�)
		//printf("bfSize : %d\n", fileHeader.bfSize);  //���� ũ��
		//printf("bfReserved1 : %d\n", fileHeader.bfReserved1); //���ȵǴ� ����
		//printf("bfReserved2 : %d\n", fileHeader.bfReserved2); //���ȵǴ� ����
		//printf("bfOffBits   : %d\n", fileHeader.bfOffBits);   //�ȼ�����Ÿ ������ Offset(ó������..������ ����)


		//��Ʈ�� ������� ����ü �ε��ϱ�//
		fread(&infoHeader, sizeof(BITMAPINFOHEADER), 1, stream);

		//printf("------��Ʈ�� ���� ��� ����ü ------\n");
		//printf("biWidth : %d\n", infoHeader.biWidth);
		//printf("biHeight: %d\n", infoHeader.biHeight);
		//printf("biBitCount : %d\n", infoHeader.biBitCount);

		//x, y , width, height �簢�� ������ �κ��̹����� �о����//
		int offset = infoHeader.biWidth * y * 4 + x*4;
		fseek(stream, offset, SEEK_CUR);

		//�����޸� �Ҵ��ϱ�
		unsigned int* rgb = new unsigned int[width * height]; //width*height*4 ����Ʈ ũ��

		//�̹��� ����Ÿ �б�
		int gap = (infoHeader.biWidth - width) * 4;

		for (int i = 0; i < height; i++)
		{
			fread(rgb + width*i, sizeof(unsigned int), width, stream);
			fseek(stream, gap, SEEK_CUR);
		}

		//���ϴݱ�
		fclose(stream);

		//�̹��� ����ü��..�ʿ��� ������ ������//
		img->width  = width;
		img->height = height;
		img->rgb    = rgb;

	}
	else {
		printf("���� ���� ����\n");
	}
}

void Bitmap::DrawBMP(float px, float py, Image* img)
{
	for (int y = 0; y < img->height; y++)
	{
		for (int x = 0; x < img->width; x++)
		{
			unsigned int pixel = img->rgb[y * img->width + x];
			SetPixel(x + px, y + py, pixel);
		}
	}
}

