#pragma once //컴파일러에게 해당 헤더 파일이 한번만 빌드되도록 한다. 해당 헤더파일이 여러번 include 되는 것을 막아준다. 여러곳에서 include 되면 그때마가 각각 정의가 추가되어 중첩되는 경우가 생기기 때문이다. 즉 중복된 내용이 여러번 빌드되는 것을 막기 위해 #pragma once를 사용한다

class Object
{
public:
	LPDIRECT3DDEVICE9 m_pDev;
	Object* m_Parent;
	RECT m_Collision;


	Matrix m_wMat;
	Vec2 m_Position;
	Vec2 m_Scale;
	Vec2 m_Size;
	float m_Rotation;

	bool m_Destroy;


	bool m_Visible;

	int m_Layer;


	float m_Speed;

	int m_Hp;
	int m_Atk;

	std::string m_Tag;

public:
	int A;
	int R;
	int G;
	int B;
	Object();
	~Object();

	Matrix GetMatrix();

public:
	virtual void Update(float time);
	virtual void Render();
	virtual void OnCollision(Object* other, std::string tag);
	virtual void Mode(float time);

public:
	void Translate(float x, float y);
	void SetScale(float x, float y);
	void SetPosition(float x, float y);
	void SetPosition(Vec2 Pos);
	void Rotate(float r);
	void SetDestroy(bool destroy) { m_Destroy = destroy; }
	void SetParent(Object* parent) { m_Parent = parent; }
public:
	bool GetDestroy() { return m_Destroy; }
};