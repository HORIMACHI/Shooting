#pragma once
#include "Imageobject.h"
#include "Equipment.h"

class CPlayer : public CImageObject
{
public:
	CEquipment m_pEquipment;

public:
	CPlayer(void);
	~CPlayer(void);
};

