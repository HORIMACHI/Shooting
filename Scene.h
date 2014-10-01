#pragma once
#include "Windows.h"
#include "DxLib.h"
class CScene
{
public:
	int m_BackgroundImage;
	int m_BackgroundMusic;

public:
	CScene(void);
	~CScene(void);

	void LoadBackgroundImage(LPCTSTR);
	void LoadBackgroundMusic(LPCTSTR);
	void CheckKey(void);
};

