#include "stdafx.h"
#include "Monster.h"
#include "MonsterBullet.h"
#include"MagicSpell.h"
#include"Boss.h"

Monster::Monster(Vec2 pos)
	:m_AtkCheck(false)
	,m_StartMove(true)
{
	m_Monster = Sprite::Create(L"Painting/Player1.png");
	m_Monster->SetParent(this);
	SetPosition(pos);
	m_mHp = 10;
}

void Monster::Update(float time)
{
	//printf("%d \n", m_mHp);
	//Object* pPlayer = nullptr;
	//for (const auto& iter : ObjectMgr::GetInst()->m_Objects)
	//{
	//	if ((iter)->m_Tag == "Player")
	//	{
	//		pPlayer = iter;
	//	}
	//}

	//vPlayerPos = pPlayer->m_Position;


	//vDir = vPlayerPos - m_Position;
	//Nor(&vDir, &vDir);

	//if (m_Speed <= 1.f)
	//{
	//	m_Speed = 1.5f;
	//}		
	//if (m_AtkTime <= 150 && m_mHp >100)
	//{
	//			m_Speed += 0.08;

	//			m_Position.x += m_Speed * vDir.x;
	//			m_Position.y += m_Speed * vDir.y;


	//}
 //   else if (m_AtkTime > 150 && m_AtkTime <= 240 && m_mHp > 70)
	//{

	//			float GotSpeed = 0;
	//			GotSpeed = GotSpeed + 0.1;
	//			m_Speed -= GotSpeed;
	//			m_Position.x += m_Speed * vDir.x;
	//			m_Position.y += m_Speed * vDir.y;
	//}
	//if (m_AtkTime > 238)
	//{
	//			m_Speed = 0.08;
	//			m_AtkTime = 0;
	//}


	if (m_StartMove == true)
	{
		m_Position.y += 1;
		m_mHp++;
	}
	if (m_Position.y >= 90)
		m_StartMove = false;
	

	m_AtkTime++;

	//if (m_mHp >= 70 && m_StartMove == false && m_AtkTime >=0)
	//{
	//   ObjMgr->KeepObject(new MonsterBullet(m_Position), "MonsterBullet");
	//   m_AtkTime = 0;
	//}
	float randomX = rand() % 760+570;



	if (m_AtkTime >= 30)
	{
		ObjMgr->KeepObject(new MagicSpell(randomX,m_Position.y ), "MagicSpell");
		m_AtkTime = 0;
	}


	if (m_mHp <= 0)
	{
		ObjMgr->RemoveObject(this);
		ObjMgr->KeepObject(new Boss(m_Position), "Boss");
	}
	ObjMgr->CollideCheak(this, "PlayerBullet");

}

void Monster::Render()
{


	//Vec2 vCameraPos = Camera::GetInst()->GetPosition();

	//m_HpBar = Sprite::Create(L"Painting/Hp/HpBar1.png");
	//m_HpBar->SetPosition(1000 - vCameraPos.x, 100);

	//m_HpBar2 = Sprite::Create(L"Painting/Hp/HpBar2.png");
	//m_HpBar2->SetPosition(1000 - vCameraPos.x, 100);

	//m_MonsterHp = Sprite::Create(L"Painting/Hp/MonsterHp.png");
	//m_MonsterHp->SetPosition(1000 - vCameraPos.x - 800, 100);




	//m_HpBar2->Render();
	LPDIRECT3DDEVICE9 pDevice = Renderer::GetInst()->GetDevice();
	D3DXCreateLine(pDevice, &m_pLine);
	m_pLine->SetWidth(3);
	Vec2 vList[] =
	{

		Vec2(100,30),
		Vec2(8*m_mHp+200,30)
	};

	m_pLine->Begin();
	m_pLine->Draw(vList, 2, D3DCOLOR_XRGB(255, 0, 0));
	m_pLine->End();


	m_Monster->Render();

	//m_HpBar->Render();
	//m_MonsterHp->Render();
	

	





}

void Monster::OnCollision(Object* obj, std::string tag)
{
	if (tag == "PlayerBullet")
	{
		m_mHp--;
	}

}
