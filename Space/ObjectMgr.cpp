#include "stdafx.h"  //���� ������� �ʴ� �� �ҽ��� stdafx�� �ְ� �̸� �������� �صд�.������ stdafx.h�� ����Ͽ� ��ü ������ �ӵ��� ��½�Ų��.
#include "ObjectMgr.h"
#include"Camera.h"


ObjectMgr::ObjectMgr()
{
}

ObjectMgr::~ObjectMgr()
{
}

void ObjectMgr::Release()
{
	for (auto& iter : m_Objects)
	{
		SAFE_DELETE(iter);
	}
	m_Objects.clear();

}

void ObjectMgr::DeleteCheak()
{
	for (auto iter = m_Objects.begin(); iter != m_Objects.end();)
	{
		if ((*iter)->GetDestroy())
		{
			Object* temp = (*iter);
			iter = m_Objects.erase(iter);
			SAFE_DELETE(temp);
		}
		else
		{
			++iter;
		}
	}


}

void ObjectMgr::Update(float time)
{
	DeleteCheak();

	//Camera::GetInst()->Update(time);
	//Camera::GetInst()->SetScale(Vec2(1.f, 1.f));

	for (const auto& iter : m_Objects)
	{
		(iter)->Update(time);
	}
}



void ObjectMgr::CollideCheak(Object* obj, std::string tag)
{
	for (auto& iter : m_Objects)
	{     
		if ((iter)->m_Tag == tag)
		{
			SetRect(
				&obj->m_Collision,
				obj->m_Position.x - obj->m_Size.x / 2,
				obj->m_Position.y - obj->m_Size.y / 2,
				obj->m_Position.x + obj->m_Size.x / 2,
				obj->m_Position.y + obj->m_Size.y / 2);


			RECT rect;
			if (IntersectRect(&rect, &obj->m_Collision, &(iter)->m_Collision))
			{
				(iter)->OnCollision(obj, obj->m_Tag);
				obj->OnCollision(iter, iter->m_Tag);
			}
		}
	}


}


void ObjectMgr::Render()
{
	m_Objects.sort(stLISTsort());



	for (const auto& iter : m_Objects)
	{
		(iter)->Render();
	}


}

void ObjectMgr::KeepObject(Object* obj, std::string tag)
{
	if (obj)
	{
		m_Objects.push_back(obj);
		obj->m_Tag = tag;
	}


}


void ObjectMgr::RemoveObject(Object* obj)
{
	if (obj)
	{
		obj->SetDestroy(true);
	}

}


