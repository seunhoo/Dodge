#include "stdafx.h"  //자주 변경되지 않는 긴 소스를 stdafx에 넣고 미리 컴파일을 해둔다.본문에 stdafx.h를 사용하여 전체 컴파일 속도를 상승시킨다.
#include "Player.h"
#include"PlayerBullet.h"
#include"Boomerang.h"
#include "Camera.h"
#include"DeathScene.h"

Player::Player()
	: m_Delay(300)
	, m_Return(false)
	, m_Shake(false)
	,m_Dash(false)
	, m_PlayerHp(1)
{ 

	Speed = 7.f;


	m_Player = Sprite::Create(L"Painting/Player2.png");
	m_Player->SetParent(this);




	SetPosition(1920 /2, 800);
}

Player::~Player()
{
}


void Player::Update(float time)
{


	Vec2 vCameraPos = Camera::GetInst()->GetPosition();

	m_Hpbar = Sprite::Create(L"Painting/Player/HpBar0.png");
	m_Hpbar->SetPosition(1920 / 2 - vCameraPos.x, 980);


	num++;
	if (num >= 30)
	{
		ObjMgr->CollideCheak(this, "Monster");
		ObjMgr->CollideCheak(this, "MonsterBullet");
		num = 0;
	}
	if (m_PlayerHp <= 0)
	{
		ObjMgr->RemoveObject(this);
		SceneDirector::GetInst()->ChangeScene(new DeathScene());
	}



	if (INPUT->GetKey(VK_SHIFT) == KeyState::PRESS )
	{
		m_Dash = true;
		if (INPUT->GetKey('W') == KeyState::DOWN)
		{
			m_Position.y -= Speed * 20;
		
		}
		else if (INPUT->GetKey('S') == KeyState::DOWN)
		{
			m_Position.y += Speed * 20;
		}
		else if (INPUT->GetKey('D') == KeyState::DOWN)
		{
			m_Position.x += Speed * 20;
		}
		else if (INPUT->GetKey('A') == KeyState::DOWN)
		{
			m_Position.x -= Speed * 20;
		}

	}
	else
	{
		m_Dash = false;
	}

	if (INPUT->GetKey('W') == KeyState::PRESS && m_Dash == false && m_Position.y >= 20)
	{
		m_Position.y -= Speed;

	}
	if (INPUT->GetKey('S') == KeyState::PRESS && m_Dash == false && m_Position.y <= 1050)
	{
		m_Position.y += Speed;
	}
	if (INPUT->GetKey('D')== KeyState::PRESS && m_Dash == false && m_Position.x <= 1350)
	{
		m_Position.x += Speed;

	}
	if (INPUT->GetKey('A') == KeyState::PRESS && m_Dash == false && m_Position.x >= 570)
	{
		m_Position.x -= Speed;

	}

	m_Delay++;

	
	if ( INPUT->GetKey(VK_UP) == KeyState::PRESS && m_Delay >= 10)
	{
		Shot();
		m_Delay = 0;
	}
	//InitProgram();





}

void Player::Render()
{
	m_Player->Render();

	//Vec2 vCameraPos = Camera::GetInst()->GetPosition();




	//if (INPUT->GetKey(VK_SPACE) == KeyState::PRESS && m_Delay > 300)
	//{
	//	ShotTime++;

	//	LPDIRECT3DDEVICE9 pDevice = Renderer::GetInst()->GetDevice();
	//	D3DXCreateLine(pDevice, &m_pLine);

	//	m_pLine->SetWidth(10.f);

	//	Vec2 vList[] =
	//	{
	//		Vec2(m_Position.x - 60 + vCameraPos.x ,m_Position.y - 80),
	//		Vec2(m_Position.x - 40 + ShotTime + vCameraPos.x,m_Position.y - 80),
	//	};

	//	m_pLine->Begin();
	//	m_pLine->Draw(vList, 2, D3DCOLOR_XRGB(255, 0, 0));

	//	if (ShotTime >= 100)
	//	{

	//		m_Delay = 0;
	//		ShotTime = 0;
	//	}
	//}

	//if (m_Dash == true)
	//{

	//}
	 

	//LPDIRECT3DDEVICE9 pDevice = Renderer::GetInst()->GetDevice();
	//D3DXCreateLine(pDevice, &m_pLine);
	//m_pLine->SetWidth(60.f);
	//Vec2 vList[] =
	//{

	//	Vec2(180 ,1057),
	//	Vec2(181 * m_PlayerHp +100  ,1057),

	//};

	//m_pLine->Begin();
	//m_pLine->Draw(vList, 2, D3DCOLOR_XRGB(255, 0,0));
	//m_pLine->End();
	//m_Hpbar->Render();

}

void Player::InitProgram()
{
}


void Player::Shot()
{
	ObjMgr->KeepObject(new PlayerBullet(m_Position,m_Rotation), "PlayerBullet");
}

void Player::OnCollision(Object* obj, std::string tag)
{

	if (tag == "Monster" )
		m_PlayerHp--;
	if (tag == "MonsterBullet")
		m_PlayerHp--;
	
}
