#pragma once
class StageOne : public Object
{
private:
	Sprite* m_BackGround;

public:
	StageOne();

	void Update(float time);
	void Render();

};

