#pragma once
#include "Equipment.h"
#include "CImageObject.h"

class CCharacter:public CImageObject
{
	public:
		CEquipment m_pEquipment;

	public:
		CCharacter(void);
		CCharacter(int id);
		~CCharacter(void);
		void DrawCharacter(void);

};

