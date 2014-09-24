#pragma once
#include "Shot.h"

class CEquipment
{
public:
	CShot* m_pShotFirst;
	int ShotCount;

public:
	CEquipment(void);
	~CEquipment(void);

	CShot* FindLast(void);
	void Add(int nImageId, int nx, int ny);
	void Remove(int nIndex);
	CShot* GetAt(int nIndex);

	void DrawShot(void);
	void CheckShot(void);
	void MoveShot(void);
};

