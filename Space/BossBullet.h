#pragma once
class BossBullet : public Object
{
private:

	Animation* m_BossBullet;


public:

	BossBullet(float posx,float posy, float rotate);

	void Update(float time);
	void Render();
	void OnCollision(Object* obj, std::string tag);
};

