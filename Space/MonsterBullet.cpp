#include "stdafx.h"
#include "MonsterBullet.h"

MonsterBullet::MonsterBullet(Vec2 pos)
	:m_BulletSpeed(3.f)
{
	m_Bullet = Sprite::Create(L"Painting/Monster/MonsterBullet.png");
	m_Bullet->SetParent(this);

	SetPosition(pos);

	float posrdX = rand() % 1920 - 960;
	posX = posrdX;

	float posrdY = rand() % 1080;
	posY = posrdY;

	float Rota = (rand() % 300 + 1) * 0.01f;
	Rotation = Rota;

}

void MonsterBullet::Update(float time)
{
	printf("%d \n", m_Bullet->m_Layer);
	m_DeleteTime++;
	ObjMgr->CollideCheak(this, "Player");
	

	m_Position.x += -m_BulletSpeed * (posX / 500);
	m_Position.y += m_BulletSpeed * (posY / 500);


	if (m_Position.y <= 20 || m_Position.y >= 1050 || m_Position.x >= 1350 || m_Position.x <= 570)
	{
		posX += Rotation * -posX;
		posY += Rotation * -posY;
		ObjMgr->RemoveObject(this);
	}
}

void MonsterBullet::Render()
{
	m_Bullet->Render();
}

void MonsterBullet::OnCollision(Object* obj, std::string tag)
{ 
     if(tag == "Player")
      	ObjMgr->RemoveObject(this);
}
