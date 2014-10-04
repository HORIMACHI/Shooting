#include "Equipment.h"
#include "DxLib.h"

CEquipment::CEquipment(void)
{
	m_pShotFirst = NULL;
	int ShotCount = 0;
}

CEquipment::~CEquipment(void)
{

}

CShot* CEquipment::FindLast(void)
{
	if(m_pShotFirst == NULL)
	{
		return NULL;
	}
	CShot* pShotBuffer = m_pShotFirst;
	while(pShotBuffer->m_pNextShot != NULL)
	{
		pShotBuffer = pShotBuffer->m_pNextShot;
	}
	return pShotBuffer;
}

void CEquipment::Add(int nImageId, int nx, int ny)
{
	CShot* pNewShot = new CShot(nImageId, nx, ny);

	CShot* pShotLast = FindLast();
	if(pShotLast == NULL)
	{
		m_pShotFirst = pNewShot;
		return;
	}
	pShotLast->m_pNextShot = pNewShot;
	return;
}

void CEquipment::Remove(int nIndex)
{
	if(nIndex < 0)
	{
		return;
	}

	if(m_pShotFirst == NULL)
	{
		return;
	}

	CShot* pShotFront = GetAt(nIndex - 1);
	CShot* pShotRemove = GetAt(nIndex);
	CShot* pShotBack = GetAt(nIndex + 1);

	if(pShotRemove == NULL)
	{
		return;
	}

	else if(pShotFront == NULL)
	{
		m_pShotFirst = pShotBack;
		delete pShotRemove;
	}

	else if(pShotBack == NULL)
	{
		pShotFront->m_pNextShot = pShotBack;
		delete pShotRemove;
	}

	else
	{
		pShotFront->m_pNextShot = pShotBack;
		delete pShotRemove;
	}
	return;
}

CShot* CEquipment::GetAt(int nIndex)
{
	if(nIndex < 0)
	{
		return NULL;
	}

	if(m_pShotFirst == NULL)
	{
		return NULL;
	}

	CShot* pShotBuffer = m_pShotFirst;
	for(int nCnt = 0; nCnt < nIndex; nCnt++)
	{
		if(pShotBuffer == NULL)
		{
			return NULL;
		}
		pShotBuffer = pShotBuffer->m_pNextShot;
	}
	return pShotBuffer;
}

void CEquipment::DrawShot(void)
{
	CShot* pShotBuffer = m_pShotFirst;
	while(pShotBuffer != NULL)
	{
		pShotBuffer->DrawImage();
		pShotBuffer = pShotBuffer->m_pNextShot;	
	}
}

void CEquipment::CheckShot(void)
{
	if(m_pShotFirst == NULL)
	{
		return;
	}

	int nCnt = 0;
	CShot* pShotBuffer = m_pShotFirst;
	while(pShotBuffer == NULL)
	{
		if(pShotBuffer->m_x > 640)
		{
			pShotBuffer = m_pShotFirst;
			Remove(nCnt);
			nCnt = 0;
			continue;
		}
		pShotBuffer = pShotBuffer->m_pNextShot;
		nCnt++;
	}
	return;
}

void CEquipment::MoveShot(void)
{
	CShot* pShotBuffer = m_pShotFirst;
	while(pShotBuffer != NULL)
	{
		pShotBuffer->m_x = pShotBuffer->m_x + 10;
		pShotBuffer = pShotBuffer->m_pNextShot;
	}
	return;
}