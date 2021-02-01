#include "stdafx.h"
#include "PlayerBullet.h"
#include"Monster.h"
PlayerBullet::PlayerBullet(Vec2 pos, float rotate)
{
	m_Sprite = Sprite::Create(L"Painting/Bullet2.png");
	m_Sprite->SetParent(this);
	SetPosition(pos);


}

void PlayerBullet::Update(float time)
{
	ObjMgr->CollideCheak(this, "Monster");

	ShotTime++;

	if (ShotTime >= 200)
	{
		ObjMgr->RemoveObject(this);
	}
	m_Speed = 20.f;

	m_Position.y -= m_Speed;
}

void PlayerBullet::Render()
{
	//LPDIRECT3DDEVICE9 pDevice = Renderer::GetInst()->GetDevice();

	//D3DXCreateLine(pDevice, &m_pLine);

	//Vec2 vList[] =
	//{

	//	Vec2(m_Position.x + 4.5,m_Position.y - 4.5),
	//	Vec2(m_Position.x + 4.5,m_Position.y + 4.5),
	//	Vec2(m_Position.x - 4.5,m_Position.y + 4.5),
	//	Vec2(m_Position.x - 4.5,m_Position.y - 4.5),
	//	Vec2(m_Position.x + 4.5,m_Position.y - 4.5)
	//};

	//m_pLine->Begin();
	//m_pLine->Draw(vList, 5, D3DCOLOR_XRGB(255, 0, 0));

	m_Sprite->Render();

	
}

void PlayerBullet::OnCollision(Object* obj, std::string tag)
{
	if (tag == "Monster")
	{
		ObjMgr->RemoveObject(this);
	}
	if (tag == "Boss")
	{
		ObjMgr->RemoveObject(this);
	}
}


