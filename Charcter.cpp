#include "Charcter.h"
#include "DxLib.h"

CCharcter::CCharcter(void)
{
	m_id = -1;
	m_x = 0;
	m_y = 0;
}

CCharcter::CCharcter(int id)
{
	m_id = id;
	m_x = 0;
	m_y = 0;
}

CCharcter::~CCharcter(void)
{

}

void CCharcter::DrawCharcter(void)
{
	DrawGraph( m_x, m_y, m_id, TRUE );
}

