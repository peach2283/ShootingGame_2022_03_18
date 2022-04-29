#include "ShootingGame.h"

Player::Player(float px, float py) : GameObject("�÷��̾�","", true, px, py)
{
	this->speed       = 250;  //�̵����ǵ�
	this->showUpSpeed = 150;  //showUP �̵� �ӵ�

	this->fireTimer = 0  ; //�߻�Ÿ�̸� ���� ����
	this->fireDelay = 0.2; //�߻����� ���� ����

	this->index = 3;  //���� ���� ���� �÷��̾� �̹���

	this->animTimer = 0;   //�ִϸ޴ϼ� �ð� ���� ����
	this->animDelay = 0.1f;//�ִϸ޴ϼ� ���� ���� ����

	this->hp    = 100;            //�÷��̾� ü��
	this->state = State::showUp;  //���� �ʱ�ȭ

	this->bulletCount = 1;  //�÷��̾� �Ѿ�(������) �߻簹��
	this->bombCount   = 5;  //�÷��̾� ���� ��ź ����

	this->isBulletItemCollided = false;  //�浹 �ȵ�����..�ʱ�ȭ

	this->shieldTimeOut = 3; //���� ���� �ð�
}

Player::~Player()
{}

void Player::Start()
{
	//�÷��̾� �ִϸ��̼� �̹��� ���� �ε�//
	Bitmap::ReadBMP("Asset/�����̵�2.bmp", 64 * 0 , 0, 62, 80, &sprite[0]);
	Bitmap::ReadBMP("Asset/�����̵�2.bmp", 64 * 1 , 0, 62, 80, &sprite[1]);
	Bitmap::ReadBMP("Asset/�����̵�2.bmp", 64 * 2 , 0, 62, 80, &sprite[2]);
	Bitmap::ReadBMP("Asset/�����̵�2.bmp", 64 * 3 , 0, 62, 80, &sprite[3]);
	Bitmap::ReadBMP("Asset/�����̵�2.bmp", 64 * 4 , 0, 62, 80, &sprite[4]);
	Bitmap::ReadBMP("Asset/�����̵�2.bmp", 64 * 5 , 0, 62, 80, &sprite[5]);
	Bitmap::ReadBMP("Asset/�����̵�2.bmp", 64 * 6 , 0, 62, 80, &sprite[6]);

	//�浹ü �߰��ϱ�//
	AddBoxCollider2D(25, 10, 12, 60);  //����
	AddBoxCollider2D(10, 40, 42, 15);  //����

	//��ȣ���� �ڽİ�ü �߰��ϱ�//
	AddChildObject(new Shield(-10, -10), 2);
}

void Player::Update()
{
	if (state == State::showUp)
	{
		Translate(0, -showUpSpeed * Time::deltaTime);

		if (GetPy() <= HEIGHT - 150)
		{
			state = State::control;
		}
	}
	else if (state == State::control)
	{
		Move();
		Fire();
		ShiledTimer();	
	}

	//�浹Ȯ�� ���� ... ����//
	isBulletItemCollided = false;
}

void Player::Draw()
{
	float px = GetPx();
	float py = GetPy();

	Bitmap::DrawBMP(px, py, &sprite[index]);
}

void Player::ShiledTimer()
{
	//���� �ð� �����ϱ�//
	shieldTimeOut = shieldTimeOut - Time::deltaTime;

	if (shieldTimeOut <= 0)
	{
		//���и� ����..(��Ȱ��ȭ)
		Shield* shield = (Shield*)Find("����");

		if (shield != nullptr)
		{
			shield->SetActive(false);  //���� ��Ȱ��ȭ
		}
		else {
			printf("���� �ڽİ�ü�� ã�� ����\n");
		}
	}
}

void Player::Move()
{
	//�̵��ϱ�//
	float dist = Time::deltaTime * speed;

	if ( Input::GetKey(KeyCode::UpArrow) == true )  
	{
		Translate(0, -dist);

		if (GetPy() < 0)
		{
			SetPy(0);
		}
	}

	if ( Input::GetKey(KeyCode::DownArrow)==true)
	{
		Translate(0, dist);

		if (GetPy() > HEIGHT - 78)
		{
			SetPy(HEIGHT - 78);
		}
	}

	if (Input::GetKey(KeyCode::LeftArrow)==true)
	{
		Translate(-dist, 0);

		if (GetPx() < -8)
		{
			SetPx(-8);
		}

		//�̹��� ����//
		animTimer = animTimer + Time::deltaTime;

		if (animTimer >= animDelay)
		{
			index--;

			if (index < 0)
			{
				index = 0;
			}

			animTimer = 0;
		}
	}

	if (Input::GetKey(KeyCode::RightArrow)==true)
	{
		Translate(dist, 0);

		if (GetPx() > WIDTH - 54)
		{
			SetPx(WIDTH - 54);
		}

		//�̹��� ����//
		animTimer = animTimer + Time::deltaTime;

		if (animTimer >= animDelay)
		{
			index++;

			if (index > 6)
			{
				index = 6;
			}

			animTimer = 0;
		}
	}

	if (Input::GetKey(KeyCode::LeftArrow) != true && Input::GetKey(KeyCode::RightArrow) != true)
	{
		animTimer = animTimer + Time::deltaTime;
		
		if (animTimer >= animDelay)
		{
			if (index < 3)
			{
				index++;
			}
			else if (index > 3)
			{
				index--;
			}

			animTimer = 0;
		}		
	}
}

void Player::Fire()
{
	//���� �ڵ� ������ �߻��ϱ�//
	if (Input::GetKey(KeyCode::Space) == true)
	{
		fireTimer = fireTimer + Time::deltaTime;

		if (fireTimer >= fireDelay)
		{
			float px = GetPx();
			float py = GetPy();

			if (bulletCount == 1)
			{
				/////////////������ �ѹ� �߻�////////////////
				//������ ��ü...�����ϱ�//
				Instantiate(new Laser(px + 34 - 6, py - 24));
			}
			else if (bulletCount == 2)
			{
				/////////////������ �ι� �߻�////////////////
				//������ ��ü...�����ϱ�//
				Instantiate(new Laser(px + 34 - 6 - 7, py - 24));
				Instantiate(new Laser(px + 34 - 6 + 7, py - 24));
			}
			else if (bulletCount == 3)
			{
				///////////////������ ���� �߻�//////////////
				//������ ��ü...�����ϱ�//
				Instantiate(new Laser(px + 34 - 6 - 7, py - 18));
				Instantiate(new Laser(px + 34 - 6, py - 26));
				Instantiate(new Laser(px + 34 - 6 + 7, py - 18));
			}
			
			//�߻�Ÿ�̸�...����
			fireTimer = 0;
		}
	}	

	//��ź �߻��ϱ�//
	if (Input::GetKeyDown(KeyCode::Z) == true)
	{
		if (bombCount > 0)
		{
			float px = GetPx();
			float py = GetPy();

			Instantiate(new Bomb(px + 16, py));
			bombCount--;

			printf("��ź ���� ���� %d\n", bombCount);
		}
		else {
			printf("���� ��ź�� ����\n");
		}
	}
}

void Player::Explosion()
{
	if (GetDead() == false)
	{
		//�÷��̾� ���� �� ����
		float px, py;
		this->GetPosition(px, py);

		Instantiate(new PlayerExp(px - (224 - 62) / 2, py - (320 - 80) / 2));

		Destroy(this);

		//�÷��̾� ������ �ϱ�//
		GameManager* manager = GameManager::Instance();
		manager->SpawnPlayer();
	}
}

void Player::OnTriggerStay2D(GameObject * other)
{
	string tag = other->GetTag();

	if (state == State::control)  //�ӽ÷�...��Ʈ��..���¸�..�浹ó��
	{
		if (tag == "�����Ѿ�" || tag=="�����Ѿ�")
		{
			if (shieldTimeOut < 0)  //�ǵ尡 ������..���ŵǾ�����츸..���ظ� ������
			{
				//�����Ѿ� ���� �����ϱ�//
				hp -= 10;

				if (hp <= 0)
				{
					Explosion();
				}
			}
		}
		else if (tag=="����" || tag == "�����ڽ�")
		{
			Explosion();
		}
		else if (tag == "�Ѿ˾�����")
		{
			if (isBulletItemCollided == false)
			{
				isBulletItemCollided = true;  //�浹��������..ǥ��

				//������ ����
				Destroy(other);

				if (bulletCount < 3)
				{
					//�Ѿ�(������) �߻簹�� ����
					bulletCount++;
				}
			}
		}
		else if (tag == "��ź������")
		{			
			//������ ����
			Destroy(other);

			//��ź ���� ����
			bombCount++;

			printf("��ź ���� ���� %d\n", bombCount);

		}
	}
}