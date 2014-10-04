#pragma once

class CImageObject
{
public:
	int m_ImageID;
	int m_x;
	int m_y;

public:
	CImageObject(void);
	CImageObject(int id);
	CImageObject(int x, int y, int id);
	virtual void DrawImage(void);
	
};
