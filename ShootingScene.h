#pragma once
#include "Scene.h"
#include "Player.h"
#include "Character.h"

class CShootingScene : public CScene
{
public:
	CCharacter m_Player;
	int m_shotid;
	int m_charid;
	//CEnemyManager EnemyManager;
	//CShotManager ShotManager;

public:
	CShootingScene(void);
	~CShootingScene(void);
	void CheckKey(void);
	void DrawImage(void);
};

