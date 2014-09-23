#pragma once
class CShot
{
public:
	int m_ImageID;
	int m_nx;
	int m_ny;
	CShot* m_pNextShot;

public:
	CShot(int nImageId, int nx, int ny);
	~CShot(void);

	void DrawShot(void);
};

