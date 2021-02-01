#include "stdafx.h"
#include "Camera.h"

Camera::Camera()
{
}

Camera::~Camera()
{

}

void Camera::SetPosition(Vec2 pos)
{
	n_Position = -pos;
}

void Camera::SetRotate(Vec2 rotate)
{
	n_Rotation = rotate;
}

void Camera::SetScale(Vec2 scale)
{
	n_Scale = scale;
}

void Camera::Update(float time)
{



	Matrix m_Trans;
	D3DXMatrixTranslation(&m_Trans, n_Position.x, n_Position.y, 0);

	Matrix m_Scale;
	D3DXMatrixScaling(&m_Scale, n_Scale.x, n_Scale.y, 1);

	static float test = 0.f;
	test += time;
	Matrix mRotateZ;
	D3DXMatrixRotationZ(&mRotateZ, test * 2.f);

	CameraMatrix = m_Scale * mRotateZ * m_Trans;
}
