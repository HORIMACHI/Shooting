#include "Scene.h"


CScene::CScene(void)
{
	
}


CScene::~CScene(void)
{

}

void CScene::LoadBackgroundImage(LPCTSTR pFileName)
{
	m_BackgroundImage = LoadGraph(pFileName);
	return;
}

void CScene::LoadBackgroundMusic(LPCTSTR pFileName)
{
	m_BackgroundMusic = LoadSoundMem(pFileName);
	return;
}