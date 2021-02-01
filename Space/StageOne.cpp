#include "stdafx.h"
#include "StageOne.h"

StageOne::StageOne()
{
	ObjMgr->KeepObject(new Player(), "Player");
	ObjMgr->KeepObject(new Monster(Vec2(1920 / 2, -100)), "Monster");


	m_BackGround = Sprite::Create(L"Painting/BackGround/BackGround1.png");
	m_BackGround->SetPosition(1920 / 2, 1080 / 2);
}

void StageOne::Update(float time)
{
}

void StageOne::Render()
{
	m_BackGround->Render();
}
