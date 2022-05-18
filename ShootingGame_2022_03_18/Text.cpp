#include "ShootingGame.h"

Text::Text(wstring text,float px, float py) : GameObject("","",true, px, py)
{
    this->text = text;
}

Text::~Text()
{
    //��Ʈ ��� �ݱ�
    FT_Done_Face(face);
    FT_Done_FreeType(library);
}

void Text::Start()
{
    //��Ʈ ���̺귯�� �ʱ�ȭ
    if (FT_Init_FreeType(&library) == 0)
    {
        //��Ʈ ����(ttf)�ε� �ϱ�
        if (FT_New_Face(library, "Asset/Font/Medium.ttf", 0, &face) == 0)
        {
            //��Ʈ ��� �ɼ�(��Ʈ..ũ��)
            FT_Set_Pixel_Sizes(face, 32, 32);
        }
        else {
            printf("��Ʈ ���� �б� ����\n");
        }
    }
    else {

        printf("��Ʈ ���̺귯��..�ʱ�ȭ ����\n");
    }
}

void Text::Update()
{}

void Text::Draw()
{
    //��Ʈ ���� ��� ��ġ
    int fontx = GetPx();
    int fonty = GetPy();

    for (int i = 0; i < text.length() ; i++)
    {
        int index = FT_Get_Char_Index(face, text[i]);

        //��Ʈ ���Ͽ��� ã�� �۲ø� �̾Ƴ���... face->glyph�� ������
        FT_Load_Glyph(face, index, FT_LOAD_DEFAULT);

        //�۲��� �ȼ�������...��Ʈ�� �̹�����..��ȯ�ϱ�
        FT_Render_Glyph(face->glyph, FT_RENDER_MODE_NORMAL);

        //�ȼ���..ȭ�鿡..����ϱ�
        int width  = face->glyph->bitmap.width;  //�۲� ��Ʈ�� �̹��� ����ũ��
        int height = face->glyph->bitmap.rows;   //�۲� ��Ʈ�� �̹��� ����ũ��

        unsigned char* buffer = face->glyph->bitmap.buffer;  //�۲� �̹��� ��Ʈ�� ����Ÿ

        for (int y = 0; y < height; y++)
        {
            for (int x = 0; x < width; x++)
            {
                unsigned char data = buffer[y * width + x];

                if (data != 0)
                {
                    unsigned char r = 255;
                    unsigned char g = 0;
                    unsigned char b = 0;

                    SetPixel(fontx + x, fonty + y, r, g, b);
                }                  
            }          
        }

        //�� ���� ��� ��...�ش� ���� ��ƴ..�̵��ϱ�
        fontx = fontx + face->glyph->advance.x / 64;
        fonty = fonty + face->glyph->advance.y / 64;
    }
}