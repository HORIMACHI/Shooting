#include "Character.h"
#include "DxLib.h"

CCharacter::CCharacter(void)
{
	m_id = -1;
	m_x = 0;
	m_y = 0;
}

CCharacter::CCharacter(int id)
{
	m_id = id;
	m_x = 0;
	m_y = 0;
}

CCharacter::~CCharacter(void)
{

}

void CCharacter::DrawCharacter(void)
{
	DrawGraph( m_x, m_y, m_id, TRUE );
}

