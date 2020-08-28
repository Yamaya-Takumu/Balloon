// ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//
// プレイヤー番号表示処理 [BalloonNum.h]
// Author : RYOUMA INOUE
//
// ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
#include "BalloonNum.h"

// ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//
// 静的変数宣言
//
// ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
int CBalloonNum::m_nID = 0;

// ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
// コンストラクタ処理
// ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
CBalloonNum::CBalloonNum()
{

}

// ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
// デストラクタ処理
// ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
CBalloonNum::~CBalloonNum()
{
}

// ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
// 初期化処理
// ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
void CBalloonNum::Init(void)
{
	SetCol(D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f));
	CScene_TWO::Init();

	BindTexture(CTexture_manager::GetTexture(54));
	SetAnimation(1.0f / 4, 1.0f, 0.0f, m_nID);
}

// ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
// 終了処理
// ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
void CBalloonNum::Uninit(void)
{
	CScene_TWO::Uninit();
}

// ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
// 更新処理
// ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
void CBalloonNum::Update(void)
{
	CScene_TWO::Update();
}


// ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
// 描画処理
// ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
void CBalloonNum::Draw(void)
{
	CScene_TWO::Draw();
}

// ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
// 順位表示の生成
// ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
CBalloonNum *CBalloonNum::Create(int nID)
{
	m_nID = nID;
	CBalloonNum *pBalloonNum = new CBalloonNum();

	if (pBalloonNum != NULL)
	{
		pBalloonNum->SetSize(D3DXVECTOR2(500.0f, 500.0f));
		pBalloonNum->SetPosition(D3DXVECTOR3(200.0f, 400.0f, 0.0f));
		pBalloonNum->Init();
		pBalloonNum->ManageSetting(LAYER_UI);
	}

	return pBalloonNum;
}

#ifdef _DEBUG
//-------------------------------------------------------------------------------------------------------------
// デバッグ表示
//-------------------------------------------------------------------------------------------------------------
void CBalloonNum::Debug(void)
{

}
#endif // _DEBUG

// ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
// リソース情報読み込み処理
// ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
HRESULT CBalloonNum::Load(void)
{
	return S_OK;
}

// ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
// 読み込んだリソース情報を破棄処理
// ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
void CBalloonNum::UnLoad(void)
{
}
