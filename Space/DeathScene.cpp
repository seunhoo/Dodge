#include "stdafx.h"
#include "DeathScene.h"
#include"SceneMain.h"

DeathScene::DeathScene()
	:Die(false)
{
	m_Death = Sprite::Create(L"Painting/BackGround/Death.png");
	m_Death->SetParent(this);
	m_Death->SetPosition(1920 / 2, 1080 / 2);

	m_Button = Sprite::Create(L"Painting/BackGround/Return.png");
	m_Buttons.push_back(m_Button);
	m_Button->SetPosition(700, 800);

	m_ButtonTwo = Sprite::Create(L"Painting/BackGround/End.png");
	m_Buttons.push_back(m_ButtonTwo);
	m_ButtonTwo->SetPosition(1500, 800);
}

void DeathScene::Update(float time)
{
	int num = 1;
	for (auto& iter : m_Buttons)
	{
		if (CollisionMgr::GetInst()->MouseWithBoxCollide(iter->m_Collision) && INPUT->GetButtonDown())
		{
			if (num == 1)
			{
				SCENE->ChangeScene(new SceneMain());
				break;
			}
			if (num == 2)
			{
				App::GetInst()->Release();
				exit(0);
			}
		}
		num++;
	}
		if (!Die)
	{
		ObjMgr->Release();
		Die = true;
	}
}

void DeathScene::Render()
{
	m_Death->Render();
	m_Button->Render();
	m_ButtonTwo->Render();
}
