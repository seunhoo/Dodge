#pragma once
class Camera : public Singleton<Camera>
{
private:


	

	Vec2 n_Position, n_Rotation, n_Scale;
	Matrix CameraMatrix;


public:



	Camera();
	~Camera();

	Vec2 GetPosition() { return n_Position; }
	void SetPosition(Vec2 pos);
	void SetRotate(Vec2 rotate);
	void SetScale(Vec2 scale);
	void Update(float time);
	

	Matrix* GetMatrix() { return &CameraMatrix; }


};

