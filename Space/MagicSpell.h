#pragma once
class MagicSpell : public Object
{
private:
	Sprite* m_Spell;


public:
	MagicSpell(float posx,float posy);

	void Update(float time);
	void Render();

	void OnCollision(Object* obj, std::string tag);
};

