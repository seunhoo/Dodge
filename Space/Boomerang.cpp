#include "stdafx.h"
#include "Boomerang.h"

Boomerang::Boomerang(Vec2 pos)
	:m_Return(false)
{
	m_BooBerang = Sprite::Create(L"Painting/BoomeRang.png");
	m_BooBerang->SetParent(this);

	SetPosition(pos);

}

void Boomerang::Update(float time)
{
	if (m_Return == false)
	{
		m_Position.x += 10;
		m_Rotation += 0.3f;
	}
	else
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


		m_Position.x += 10 * vDir.x;
		m_Position.y += 10 * vDir.y;
		m_Rotation += 0.4f;
		ObjMgr->CollideCheak(this, "Player");
	}


	if (m_Position.x >= 1920 || m_Position.x <= 0 || m_Position.y >= 1080 || m_Position.y <=0)
		m_Return = true;



}

void Boomerang::Render()
{
	m_BooBerang->Render();
}

void Boomerang::OnCollision(Object* obj, std::string tag)
{
	if (tag == "Player")
	{
		ObjMgr->RemoveObject(this);
		printf("%f  %f \n", m_Position.x, m_Position.y);
	}
}
