#include "stdafx.h"
#include "Boss.h"
#include"BossBullet.h"
Boss::Boss(Vec2 pos)
	:BossSpawn(false)
	,m_AtkCheck(false)
	,m_BossHp(200)
{
	m_BossAni = new Animation();
	m_BossAni->Init(7, true);
	m_BossAni->AddContinueFrame(L"Painting/Boss/Boss", 0, 4);
	m_BossAni->SetParent(this);

	m_Warning = Sprite::Create(L"Painting/Boss/Attack/BossAtkReady.png");
	m_Warning->SetParent(this);
	m_Warning->SetPosition(m_Position.x, m_Position.y + 1000);

	m_Warning1 = Sprite::Create(L"Painting/Boss/Attack/BossAtkReady.png");
	m_Warning1->SetParent(this);
	m_Warning1->SetPosition(m_Position.x - 170, m_Position.y + 1000);

	m_Warning2 = Sprite::Create(L"Painting/Boss/Attack/BossAtkReady.png");
	m_Warning2->SetParent(this);
	m_Warning2->SetPosition(m_Position.x + 170, m_Position.y + 1000);

	m_Boss = Sprite::Create(L"Painting/Boss/Boss4.png");
	m_Boss->SetParent(this);
	SetPosition(pos);
}

void Boss::Update(float time)
{
	ObjMgr->CollideCheak(this, "PlayerBullet");
	//m_Position.y -= 0.1f;
	if (m_BossAni->m_CurrentFrame == 4)
	{
		BossSpawn = true;
	}

	if(BossSpawn == false)
	{
		m_BossHp += 20;
		//m_BossAni->Update(time);
	}
	if (m_Position.y <= 150)
	{
		m_Position.y += 3;
	}


	m_AtkTime++;
	m_PageTime++;

		if (m_AtkTime >= 150 && m_AtkCheck == false && m_PageTime <= 500)
		{

			Object* pPlayer = nullptr;
			for (const auto& iter : ObjectMgr::GetInst()->m_Objects)
			{
				if ((iter)->m_Tag == "Player")
				{
					pPlayer = iter;
				}
			}

			Vec2 vPlayerPos = pPlayer->m_Position;


			Vec2 vDir = vPlayerPos - m_Position;
			Nor(&vDir, &vDir);


			ObjMgr->KeepObject(new BossBullet(m_Position.x, m_Position.y + 1200, m_Rotation), "MonsterBullet");

			m_AtkCheck = true;
		}
		if (m_AtkTime >= 200)
		{
			m_AtkTime = 0;
			m_AtkCheck = false;
		}
		if (m_PageTime >= 500)
		{
			ObjMgr->KeepObject(new BossBullet(m_Position.x + 170, m_Position.y + 1200, m_Rotation), "MonsterBullet");
			ObjMgr->KeepObject(new BossBullet(m_Position.x - 170, m_Position.y + 1200, m_Rotation), "MonsterBullet");
			m_PageTime = 0;
		}
	

	
}

void Boss::Render()
{
	LPDIRECT3DDEVICE9 pDevice = Renderer::GetInst()->GetDevice();
	D3DXCreateLine(pDevice, &m_pLine);
	m_pLine->SetWidth(3);
	Vec2 vList[] =
	{

		Vec2(100,30),
		Vec2(2* (m_BossHp+ 200),30)
	};

	m_pLine->Begin();
	m_pLine->Draw(vList, 2, D3DCOLOR_XRGB(255, 0, 0));
	m_pLine->End();

	if (m_AtkTime >= 100 && m_AtkTime < 130)
	{
		m_Warning->Render();
	}
	if (m_PageTime >= 450 && m_PageTime < 500)
	{
		m_Warning1->Render();
		m_Warning2->Render();
	}

		m_BossAni->Render();
	


	
	if (BossSpawn == true)
	{
		m_Boss->Render();
	}
}

void Boss::OnCollision(Object* obj, std::string tag)
{
	if (tag == "PlayerBullet")
		m_BossHp--;
}
