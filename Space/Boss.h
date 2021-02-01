#pragma once
class Boss : public Object
{
private:

	LPD3DXLINE m_pLine;
	Animation* m_BossAni;
	Sprite* m_Boss;
	Sprite* m_Warning;
	Sprite* m_Warning1;
	Sprite* m_Warning2;

public:

	bool BossSpawn;

	int m_AtkTime;
	
	int m_BossHp;
	int m_PageTime;
	bool m_AtkCheck;


	float m_Distance;
	Vec2 m_Dir;

	Boss(Vec2 pos);

	void Update(float time);
	void Render();
	void OnCollision(Object* obj, std::string tag);
};

