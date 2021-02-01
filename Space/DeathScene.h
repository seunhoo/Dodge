#pragma once
class DeathScene : public Object
{
private:
	std::list<Object*>m_Buttons;
	Sprite* m_Death;
	Sprite* m_Button;
	Sprite* m_ButtonTwo;

	bool Die;
public:
	DeathScene();

	void Update(float time);
	void Render();

};

