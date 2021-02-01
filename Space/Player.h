#pragma once
class Player : public Object
{
private:


	LPD3DXLINE m_pLine;

	Sprite* m_Sprite;

	Sprite* m_Player;
	Sprite* m_Hpbar;
public:
	int ShotTime;
	int m_PlayerHp;
	int num;


	float Speed;
	int m_Delay;

	bool m_Return;
	bool m_Shake;
	bool m_Dash;

	Player();
	~Player();

	void Update(float time);
	void InitProgram();
	void Render();

	void Shot();
	void OnCollision(Object* obj, std::string tag);
};

