#include "stdafx.h"  //자주 변경되지 않는 긴 소스를 stdafx에 넣고 미리 컴파일을 해둔다.본문에 stdafx.h를 사용하여 전체 컴파일 속도를 상승시킨다.
#include "SceneMain.h"
#include"Camera.h"
#include"Boss.h"
#include"StageOne.h"
SceneMain::SceneMain()
{


	m_Sprite = Sprite::Create(L"Painting/BackGround/MainScene.png");
	m_Sprite->SetParent(this);
	m_Sprite->SetPosition(1920 / 2, 1080 / 2);

	m_StartButton = Sprite::Create(L"Painting/BackGround/StartGame.png");
	m_StartButton->SetPosition(400, 800);
	m_Buttons.push_back(m_StartButton);

	m_ExitButton = Sprite::Create(L"Painting/BackGround/End.png");
	m_ExitButton->SetPosition(1400, 800);
	m_Buttons.push_back(m_ExitButton);
}

SceneMain::~SceneMain()
{
}


void SceneMain::Update(float time)
{
	//Camera::GetInst()->SetPosition(Vec2(0.f, 0.f));

	int num = 1;

	for (auto& iter : m_Buttons)
	{
		if (CollisionMgr::GetInst()->MouseWithBoxCollide(iter->m_Collision) && INPUT->GetButtonDown())
		{
			if (num == 1)
			{
				SCENE->ChangeScene(new StageOne());
			}
			if (num == 2)
			{
				App::GetInst()->Release();
				exit(0);
			}
			
		}
		num++;
	}



}

void SceneMain::Render()
{
	m_Sprite->Render();
	m_StartButton->Render();
	m_ExitButton->Render();
}
