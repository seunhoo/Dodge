#pragma once //�����Ϸ����� �ش� ��� ������ �ѹ��� ����ǵ��� �Ѵ�. �ش� ��������� ������ include �Ǵ� ���� �����ش�. ���������� include �Ǹ� �׶����� ���� ���ǰ� �߰��Ǿ� ��ø�Ǵ� ��찡 ����� �����̴�. �� �ߺ��� ������ ������ ����Ǵ� ���� ���� ���� #pragma once�� ����Ѵ�

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