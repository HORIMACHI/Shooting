#include "Shot.h"
#include "DxLib.h"


CShot::CShot(int nImageId, int nx, int ny)
{
	m_ImageID = nImageId;
	m_nx = nx;
	m_ny = ny;
	m_pNextShot = NULL;
}


CShot::~CShot(void)
{
}

void CShot::DrawShot(void)
{
	DrawGraph(m_nx, m_ny, m_ImageID, TRUE);
}
