#pragma once
#include "Equipment.h"
#include "ImageObject.h"

class CCharacter : public CImageObject
{
public:
	//�v���C���[���G�̑���
	//����
	//�̗�
	//�����蔻��͈�
	CEquipment m_pEquipment;

public:
	CCharacter(void);
	CCharacter(int id);
	~CCharacter(void);
	//�ړ�				�o�[�`����
	//�V���b�g��ł�
};

