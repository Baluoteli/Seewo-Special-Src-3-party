#pragma once
#include "AGButton.h"
#include "AGVideoWnd.h"
#include "DeviceDlg.h"
#include "ChatDlg.h"
#include "SEIDlg.h"
#include "AGScreenCaptureDlg.h"

// CVideoDlg 

class CVideoDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CVideoDlg)

public:
	CVideoDlg(CWnd* pParent = NULL);
	virtual ~CVideoDlg();

	enum { IDD = IDD_VIDEO_DIALOG };

	enum { 
		SCREEN_VIDEO1 = 0,	// 
		SCREEN_VIDEO4,		// 
		SCREEN_VIDEOMULTI,	// 
	};

	//HWND GetRemoteVideoWnd(int nIndex);
	HWND GetLocalVideoWnd() { return m_wndLocal.GetSafeHwnd(); };

	void RebindVideoWnd();
	void bindVideoWnd1();

	void ShowControlButton(BOOL bShow = TRUE);

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV
	virtual BOOL OnInitDialog();
	virtual BOOL PreTranslateMessage(MSG* pMsg);

	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnPaint();
	afx_msg void OnShowWindow(BOOL bShow, UINT nStatus);
	afx_msg LRESULT OnNcHitTest(CPoint point);
	afx_msg LRESULT OnShowModeChanged(WPARAM wParam, LPARAM lParam);
	afx_msg LRESULT OnShowBig(WPARAM wParam, LPARAM lParam);
	afx_msg LRESULT OnWindowShareStart(WPARAM wParam, LPARAM lParam);

	afx_msg void OnBnClickedBtnmin();
	afx_msg void OnBnClickedBtnclose();
	afx_msg void OnBnClickedBtnrest();

	afx_msg void OnBnClickedBtnmessage();
	afx_msg void OnBnClickedBtnmode();
	afx_msg void OnBnClickedBtnaudio();
	afx_msg void OnBnClickedBtntip();
	afx_msg void OnBnClickedBtnScreenCapture();
	afx_msg void OnBnClickedBtnMore();

	afx_msg void OnBnClickedBtnfullscr();
	afx_msg void OnCbnSelchangeCmbRole();

	afx_msg void OnBnClickedScreenshare();
	afx_msg void OnBnClickedWindowshare();

	afx_msg void OnBnClickedBtnsetup();
	afx_msg void OnBnClickedBtSEIPush();

	afx_msg LRESULT OnEIDJoinChannelSuccess(WPARAM wParam, LPARAM lParam);
	afx_msg LRESULT OnEIDReJoinChannelSuccess(WPARAM wParam, LPARAM lParam);
	
	afx_msg LRESULT OnEIDFirstLocalFrame(WPARAM wParam, LPARAM lParam);
	afx_msg LRESULT OnEIDFirstRemoteFrameDecoded(WPARAM wParam, LPARAM lParam);
	afx_msg LRESULT OnEIDUserJoined(WPARAM wParam, LPARAM lParam);
	afx_msg LRESULT OnEIDUserOffline(WPARAM wParam, LPARAM lParam);
	afx_msg LRESULT OnEIDConnectionLost(WPARAM wParam, LPARAM lParam);
	afx_msg LRESULT OnEIDVideoDeviceChanged(WPARAM wParam, LPARAM lParam);
	afx_msg LRESULT OnRemoteVideoStat(WPARAM wParam, LPARAM lParam);
	afx_msg LRESULT OnLocalVideoStat(WPARAM wParam, LPARAM lParam);

	afx_msg LRESULT OnStartRecordingService(WPARAM wParam, LPARAM lParam);
	afx_msg LRESULT OnStopRecordingService(WPARAM wParam, LPARAM lParam);
	afx_msg LRESULT OnApiCallExecuted(WPARAM wParam, LPARAM lParam);

	DECLARE_MESSAGE_MAP()

protected:
	BOOL NeedShowSizeBox(CPoint point);
	void EnableSize(BOOL bEnable);
	void CreateScreenShareMenu();
	void CreateMoreMenu();

	void DrawHead(CDC *pDC);

	void InitCtrls();

	void ShowVideo4();

	void ShowButtonsNormal();

	void AdjustButtonsNormal(int cx, int cy);

	//void AdjustSizeVideo1(int cx, int cy);
	void AdjustSizeVideo4(int cx, int cy);
	//void AdjustSizeVideoMulti(int cx, int cy);

private:
	void SwitchBetweenSmallBigViews();

private:
	CBrush			m_brHead;
	CFont			m_ftDes;
	CFont			m_ftDes1;

	CAGButton		m_btnMin;
	CAGButton		m_btnRst;
	CAGButton		m_btnClose;
	
//	CAGButton		m_btnSetup;
	
	CAGButton		m_btnMode;
	CAGButton		m_btnAudio;
	CAGButton		m_btnEndCall;
	CComboBox		m_cbxRole;
	CAGButton		m_btnShow;
	CAGButton		m_btnTip;
	CAGButton		m_btnScrCap;

	CAGButton       m_btnMore;

	BOOL			m_bLastStat;
	UINT			m_nScreenMode;
	UINT			m_nBigShowedUID;

	CAGVideoWnd		m_wndLocal;
	CAGVideoWnd		m_wndBigVideo;
	CAGVideoWnd		m_wndSecond;

	CDeviceDlg		m_dlgDevice;
	CChatDlg        m_dlgChat;
	CSEIDlg			m_dlgSEI;

	CRect			m_rcVideoArea;
	CRect			m_rcChildVideoArea;

	CBitmap         m_bitMenuDevice;
	CBitmap			m_bitMenuSEI;

	CAGScreenCaptureDlg	m_dlgScreenCapture;

private:	// data	

	typedef struct _AGVIDEO_WNDINFO
	{
		UINT	nUID;
		int		nIndex;

		UINT	nWidth;
		UINT	nHeight;
		int		nBitrate;
		int		nFramerate;
		int		nCodec;

	} AGVIDEO_WNDINFO, *PAGVIDEO_WNDINFO, *LPAGVIDEO_WNDINFO;

	CList<AGVIDEO_WNDINFO>	m_listWndInfo;

	BOOL			m_bRecording;
	BOOL			m_bFullScreen;
	int				m_nTimeCounter;
};
