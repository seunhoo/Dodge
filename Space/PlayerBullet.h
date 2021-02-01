#pragma once
class PlayerBullet : public Object
{
private:

	LPDIRECT3DDEVICE9 m_pDev;
	LPD3DXLINE m_pLine;

	Sprite* m_Sprite;

public:

	bool Fire;
	int ShotTime;
	Vec2 m_Dir;


	PlayerBullet(Vec2 pos, float rotate);

	void Update(float time);
	void Render();
	void OnCollision(Object* obj, std::string tag);
};

