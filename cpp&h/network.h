// ----------------------------------------------------------------------------------------------------
//
// ネットワークの説明[network.h]
// Author : masayasu wakita
//
// ----------------------------------------------------------------------------------------------------
#ifndef _NETWORK_H_
#define _NETWORK_H_	 // ファイル名を基準を決める

// ----------------------------------------------------------------------------------------------------
//
// インクルードファイル
//
// ----------------------------------------------------------------------------------------------------
#include "main.h"
#include "keyboard.h"

// ----------------------------------------------------------------------------------------------------
//
// マクロ定義
//
// ----------------------------------------------------------------------------------------------------
#define SCRIPT_NETWORK "network.ini"
#define MAX_PLAYER 4

typedef enum
{
	NUM_KEY_W = 0,
	NUM_KEY_A,
	NUM_KEY_S,
	NUM_KEY_D,
	NUM_KEY_M
} NUM_KEY;

typedef enum
{
	SOCKETTYPE_CLIENT = 0,
	SOCKETTYPE_GAME,
	SOCKETTYPE_MAX
} SOCKETTYPE;

// ----------------------------------------------------------------------------------------------------
//
// 構造体定義
//
// ----------------------------------------------------------------------------------------------------
typedef struct
{
	//int m_nId = -1;										// ID番号
	int m_aKeyState[NUM_KEY_M] = {};				// キーボードのプレス状態
} PLAYERSTATE;

// ----------------------------------------------------------------------------------------------------
//
// クラス
//
// ----------------------------------------------------------------------------------------------------
class CNetwork
{
public:
	/* 関数 */
	CNetwork();
	~CNetwork();
	HRESULT Init(void);
	void Uninit(void);
	void Update(void);

	static HRESULT LoadConfiguration(void);

	HRESULT Build(void);
	HRESULT Connect(void);

	PLAYERSTATE GetKeystate(void);

	bool SendTCP(const char* data, int nSize);
	bool SendUDP(const char* data, int nSize);
	bool DataRecv(SOCKETTYPE type, char* data, int nSize);

	bool KeyData(void);
	SOCKET GetSocket(void) { return m_sockClient; }
	bool GetPressKeyboard(int nId, int nKey);

private:
	SOCKET createServerSocket(unsigned short port);
	static void ConvertStringToFloat(char* text,const char* delimiter, float* pResult);

	SOCKET m_sockClient;								//ソケット(クライアント)
	SOCKET m_sockClientToServer;						// ソケットキー情報
	SOCKET m_sockServerToClient;						// ソケットキー情報

	struct sockaddr_in m_addrServer;					//ソケットアドレス(サーバ)の情報
	struct sockaddr_in m_addrClientToServer;			// キー送信用ソケット
	struct sockaddr_in m_addrServerToClient;			// キー送信用ソケット

	PLAYERSTATE keystate;
	fd_set m_readfds;

	int m_nId;

	static char aIp[32];				// IPアドレス
	static char aMultiCast_ip[32];			// マルチキャストIP
	static int nPort;					// ポート番号
};
#endif // !_NETWORK_H_