#include "Character.h"
#include "DxLib.h"

CCharacter::CCharacter(void)
{
	m_ImageID = -1;
	m_x = 0;
	m_y = 0;
}

CCharacter::CCharacter(int ImageID)
{
	m_ImageID = ImageID;
	m_x = 0;
	m_y = 0;
}

CCharacter::~CCharacter(void)
{

}


