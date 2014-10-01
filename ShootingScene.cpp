#include "ShootingScene.h"

#define SHOOTING_FIELD_WIDTH 480
#define SHOOTING_FIELD_HEIGHT 480

CShootingScene::CShootingScene(void)
{
	m_shotid = LoadGraph(_T("Image\\’e00.png"));
	m_charid = LoadGraph(_T("Image\\ƒLƒƒƒ‰ƒNƒ^00.png"));
	m_Player.m_ImageID = m_charid;
}


CShootingScene::~CShootingScene(void)
{
}

void CShootingScene::CheckKey(void)
{
	if(CheckHitKey(KEY_INPUT_UP) == 1)
		m_Player.m_y -= 3;
	if(CheckHitKey(KEY_INPUT_DOWN) == 1)
		m_Player.m_y += 3;
	if(CheckHitKey(KEY_INPUT_LEFT) == 1)
		m_Player.m_x -= 3;
	if(CheckHitKey(KEY_INPUT_RIGHT) == 1)
		m_Player.m_x += 3 ;

	if(m_Player.m_x < 0 )
		m_Player.m_x = 0 ;
	if(m_Player.m_x > 640 - 64)
		m_Player.m_x = 640 - 64;
	if(m_Player.m_y < 0 )
		m_Player.m_y = 0 ;
	if(m_Player.m_y > 480 - 64)
		m_Player.m_y = 480 - 64;

	if(CheckHitKey(KEY_INPUT_SPACE) == 1)
	{
		m_Player.m_pEquipment.Add(m_shotid, m_Player.m_x, m_Player.m_y);
	}
}

void CShootingScene::DrawImage(void)
{
	CheckKey();
	m_Player.DrawImage();
	m_Player.m_pEquipment.DrawShot();
	m_Player.m_pEquipment.MoveShot();
	m_Player.m_pEquipment.CheckShot();

}
