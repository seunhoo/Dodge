#pragma once
#define SCENE SceneDirector::GetInst()
class SceneDirector : public Singleton<SceneDirector>
{
	Object* m_CurrentScene;


public:
	SceneDirector();
	~SceneDirector();

	void ChangeScene(Object* newScene);

	void Update(float time);
	void Render();

};

