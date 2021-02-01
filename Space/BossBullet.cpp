#include "stdafx.h"
#include "BossBullet.h"

BossBullet::BossBullet(float posx, float posy, float rotate)
{
	m_BossBullet = new Animation();
	m_BossBullet->Init(1, true);
	m_BossBullet->AddContinueFrame(L"Painting/Boss/Attack/BossAttack",0,20);
	m_BossBullet->SetParent(this);


	SetPosition(posx ,posy);

}

void BossBullet::Update(float time)
{
	m_BossBullet->Update(time);

	if (m_BossBullet->m_CurrentFrame == 20)
	{
		ObjMgr->RemoveObject(this);
	}
}

void BossBullet::Render()
{
	m_BossBullet->Render();
}

void BossBullet::OnCollision(Object* obj, std::string tag)
{
}
