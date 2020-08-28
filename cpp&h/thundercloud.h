// ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//
// ���_����[thundercloud.h]
// Author : masayasu wakita
//
// ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
#ifndef _THUNDERCLOUD_H_
#define _THUNDERCLOUD_H_	 // �t�@�C������������߂�

// ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//
// �C���N���[�h�t�@�C��
//
// ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
#include "scene_three.h"

// ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//
// �}�N����`
//
// ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

// ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//
// �O���錾
//
// ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

// ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//
// �N���X
//
// ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
class CThunderCloud : public CScene_THREE
{
public:
	/* �֐� */
	CThunderCloud();
	~CThunderCloud();
	void Init(void);
	void Uninit(void);
	void Update(void);
	void Draw(void);

	static CThunderCloud *Create(D3DXVECTOR3 pos);
#ifdef _DEBUG
	void Debug(void);
#endif // _DEBUG

	static HRESULT Load(void);		// �ǂݍ���
	static void UnLoad(void);		// UnLoad����

protected:

private:
	int m_nLifeCount;
};
#endif