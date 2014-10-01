#pragma once
#include "ImageObject.h"

class CShot:public CImageObject
{
public:
	CShot* m_pNextShot;

public:
	CShot(int nImageId, int nx, int ny);
};

