// ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//
// タイトル選択処理の説明[title_select.h]
// Author : Nishiyama Koki
//
// ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
#ifndef _TITLE_SELECT_H_
#define _TITLE_SELECT_H_	 // ファイル名を基準を決める

// ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//
// インクルードファイル
//
// ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
#include "scene.h"

// ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//
// マクロ定義
//
// ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

// ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//
// 前方宣言
//
// ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
class CUi;
class C2DPresents;

// ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//
// クラス
//
// ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
class CTitle_select : public CScene
{
public:
	/* 関数 */
	CTitle_select();
	~CTitle_select();
	void Init(void);
	void Uninit(void);
	void Update(void);
	void Draw(void);
	void SelfInit(void);
#ifdef _DEBUG
	void Debug(void);
#endif // _DEBUG
	// 当たった後の処理
	//	nObjType	: オブジェクトタイプ
	//	pScene		: 相手のシーン情報
	virtual void Scene_MyCollision(
		int const &nObjType = 0,	// オブジェクトタイプ
		CScene * pScene = NULL		// 相手のシーン情報
	) {};
	// 相手に当てられた後の処理
	//	nObjType	: オブジェクトタイプ
	//	pScene		: 相手のシーン情報
	virtual void Scene_OpponentCollision(
		int const &nObjType = 0,	// オブジェクトタイプ
		CScene * pScene = NULL		// 相手のシーン情報
	) {};
	// 自分から当たらなかった後の処理
	//	nObjType	: オブジェクトタイプ
	//	pScene		: 相手のシーン情報
	virtual void Scene_NoMyCollision(
		int const &nObjType = 0,	// オブジェクトタイプ
		CScene * pScene = NULL		// 相手のシーン情報
	) {};
	// 相手に当てられなかった後の処理
	//	nObjType	: オブジェクトタイプ
	//	pScene		: 相手のシーン情報
	virtual void Scene_NoOpponentCollision(
		int const &nObjType = 0,	// オブジェクトタイプ
		CScene * pScene = NULL		// 相手のシーン情報
	) {};

	// ポインター位置情報を取得
	D3DXVECTOR3 * Scene_GetPPos(void) { return NULL; };
	// ポインター過去の位置情報を取得
	D3DXVECTOR3 * Scene_GetPPosold(void) { return NULL; };
	// ポインター移動量情報の取得
	D3DXVECTOR3 * Scene_GetPMove(void) { return NULL; };

	static HRESULT Load(void);		// 読み込み
	static void UnLoad(void);		// UnLoadする
	// 作成(個人管理)
	static std::unique_ptr<CTitle_select> Create_Self(void);
	// 作成(シーン管理)
	static CTitle_select * Create(void);
protected:

private:
	/* 列挙型 */
	typedef enum
	{
		// 選択
		TITLE_SELECT_CHARACTERSELECT = 0,
		TITLE_SELECT_TUTORIAL,
		TITLE_SELECT_GAMEEND,
		TITLE_SELECT_MAX
	} TITLE_SELECT;
	/* 関数 */
	void Select(void);								// 選択
	/* 変数 */
	static int m_nSelect;							// 選択
	/* 各UIクラス */
	std::vector<std::unique_ptr<CUi>> m_BgUi;					// 背景用UI
	std::unique_ptr<C2DPresents> m_uni_SelectUi;			// 選択UI
	std::vector<std::unique_ptr<CUi>> m_Ui;					// UI情報
};

#endif