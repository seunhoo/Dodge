#pragma once
class Boomerang : public Object
{
private:

	Sprite* m_BooBerang;

	Vec2 m_Dir;

public:


	Boomerang(Vec2 pos);



	bool m_Return;

	void Update(float time);
	void Render();
	void OnCollision(Object* obj, std::string tag);


};

