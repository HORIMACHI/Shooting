#include "Character.h"
#include "DxLib.h"

CCharacter::CCharacter(void)
{
	m_ImageID = -1;
	m_x = 0;
	m_y = 0;
}

CCharacter::CCharacter(int id)
{
	m_ImageID = id;
	m_x = 0;
	m_y = 0;
}

CCharacter::~CCharacter(void)
{

}


