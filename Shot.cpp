#include "Shot.h"
#include "DxLib.h"


CShot::CShot(int nImageId, int nx, int ny)
{
	m_ImageID = nImageId;
	m_x = nx;
	m_y = ny;
	m_pNextShot = NULL;
}


