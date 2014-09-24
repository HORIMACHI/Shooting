#pragma once
#include "Equipment.h"

class CCharcter
{
public:
	int m_id;
	int m_x;
	int m_y;

	CEquipment m_pEquipment;

public:
	CCharcter(void);
	CCharcter(int id);
	~CCharcter(void);

	void DrawCharcter(void);
	void CCharcter::shot(void);


};

