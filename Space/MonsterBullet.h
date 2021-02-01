#pragma once
class MonsterBullet : public Object
{
private:
	Sprite* m_Bullet;


public:

	MonsterBullet(Vec2 pos);

	int m_DeleteTime;

	float m_BulletSpeed;
	float Rotation;
	float posX;
	float posY;

	void Update(float time);
	void Render();
	void OnCollision(Object* obj, std::string tag);
};

