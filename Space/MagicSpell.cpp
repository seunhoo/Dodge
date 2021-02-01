#include "stdafx.h"
#include "MagicSpell.h"

MagicSpell::MagicSpell(float posx,float posy)
{

	m_Spell = Sprite::Create(L"Painting/Razer.png");

	m_Spell->SetParent(this);

	SetPosition(posx, posy);
	
}

void MagicSpell::Update(float time)
{
	if (m_Position.x < 580 || m_Position.x > 1360)
	{
		ObjMgr->RemoveObject(this);
	}
	m_Position.y += 100;
}

void MagicSpell::Render()
{
	m_Spell->Render();
}

void MagicSpell::OnCollision(Object* obj, std::string tag)
{
}
