#pragma once
class Monster : public Object
{
private:
	LPD3DXLINE m_pLine;
	Sprite* m_Monster;
	//Sprite* m_HpBar;
	//Sprite* m_HpBar2;
	//Sprite* m_MonsterHp;
public:
	int m_mHp;
	int m_AtkTime;
	int m_StartMove;

	bool m_AtkCheck;
	Vec2 AtkPos;
	Vec2 vPlayerPos, vDir;

	Monster(Vec2 pos);

	void Update(float time);
	void Render();
	void OnCollision(Object* obj, std::string tag);
};

