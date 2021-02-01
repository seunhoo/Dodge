#pragma once
class CollisionMgr : public Singleton<CollisionMgr>
{
public:
	CollisionMgr();
	~CollisionMgr();

	bool MouseWithBoxCollide(RECT rect);

};

