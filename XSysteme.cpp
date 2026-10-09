// XSysteme.cpp : Définit le point d'entrée de l'application.
//
#pragma once
#define _WIN32_WINNT  0x0503
#define _WIN32_IE 0x703

#include "targetver.h"
#define WIN32_LEAN_AND_MEAN             // Exclure les en-têtes Windows rarement utilisés
#include <windows.h>
#include <stdlib.h>
#include <malloc.h>
#include <memory.h>
#include <tchar.h>
#include <commctrl.h>
#include <shellapi.h>
#include "resource.h"
#pragma comment(lib, "user32.lib")
#pragma comment(lib, "comctl32.lib")
#pragma comment( lib, "advapi32.lib" )
#pragma warning(disable:28159)
#pragma warning(disable:6031)
#pragma warning(disable:4615)
#pragma warning(disable:4311)
#pragma warning(disable:4302)
#pragma warning(disable:4312)

#define WEBLINK_KLM_GETBKMODE     (WM_USER+1)
#define WEBLINK_KLM_SETBKMODE     (WM_USER+2)
#define WEBLINK_KLM_GETBKCOLOR    (WM_USER+3)
#define WEBLINK_KLM_SETBKCOLOR    (WM_USER+4)
#define WEBLINK_KLM_GETTEXTCOLOR      (WM_USER+5)
#define WEBLINK_KLM_SETTEXTCOLOR      (WM_USER+6)
#define WEBLINK_KLM_GETTEXTHOVERCOLOR (WM_USER+7)
#define WEBLINK_KLM_SETTEXTHOVERCOLOR (WM_USER+8)
#define WEBLINK_KLM_GETFONT       WM_GETFONT
#define WEBLINK_KLM_SETFONT       WM_SETFONT
#define WEBLINK_KLM_GETFONTHOVER  (WM_USER+9)
#define WEBLINK_KLM_SETFONTHOVER  (WM_USER+10)
#define WEBLINK_KLM_GETLINKSTRING  (WM_USER+11)
#define WEBLINK_KLM_SETLINKSTRING  (WM_USER+12)
#define WEBLINK_KLM_UPDATE        (WM_USER+13)
#define WEBLINK_KLN_CLICKED       0
#define WEBLINK_KLN_MOUSEOVER     1 // detecte le passage de la souris au-dessus de fenetre
#define WEBLINK_KLN_MOUSEOUT      2 // detecte quand la souris n'est plus en train de survoler la fenetre

#ifdef _WIN64
#define TITRE "XSysteme Edition 64Bits"
#define GWL_USERDATA GWLP_USERDATA
#define WEBLINK_CLASS  "WebLinkCtrlClass64"
#else
#define TITRE "XSysteme Edition 32Bits"
#define WEBLINK_CLASS  "WebLinkCtrlClass32"
#endif // _WIN64
// Macros
#define WebLink_GetBkMode(w) (int)SendMessage((w),WEBLINK_KLM_GETBKMODE,0,0)
#define WebLink_SetBkMode(w,m) (BOOL)SendMessage((w),WEBLINK_KLM_SETBKMODE,(WPARAM)(m),0)
#define WebLink_GetBkColor(w) (COLORREF)SendMessage((w),WEBLINK_KLM_GETBKCOLOR,0,0)
#define WebLink_SetBkColor(w,c,f) (COLORREF)SendMessage((w),WEBLINK_KLM_SETBKCOLOR,(WPARAM)(BOOL)(f),(LPARAM)(c))
#define WebLink_GetTextColor(w) (COLORREF)SendMessage((w),WEBLINK_KLM_GETTEXTCOLOR,0,0)
#define WebLink_SetTextColor(w,c,f) (COLORREF)SendMessage((w),WEBLINK_KLM_SETTEXTCOLOR,(WPARAM)(BOOL)(f),(LPARAM)(c))
#define WebLink_GetTextHoverColor(w) (COLORREF)SendMessage((w),WEBLINK_KLM_GETTEXTHOVERCOLOR,0,0)
#define WebLink_SetTextHoverColor(w,c) (COLORREF)SendMessage((w),WEBLINK_KLM_SETTEXTHOVERCOLOR,0,(LPARAM)(c))
#define WebLink_GetFont(w) (HFONT)SendMessage((w),WM_GETFONT,0,0)
#define WebLink_SetFont(w,h,f) SendMessage((w),WM_SETFONT,(WPARAM)(HFONT)(h),(LPARAM)(BOOL)(f))
#define WebLink_GetFontHover(w) (HFONT)SendMessage((w),WEBLINK_KLM_GETFONTHOVER,0,0)
#define WebLink_SetFontHover(w,h) SendMessage((w),WEBLINK_KLM_SETFONTHOVER,(WPARAM)(HFONT)(h),0)
#define WebLink_GetLinkString(w,s,i) (LPCTSTR)SendMessage((w),WEBLINK_KLM_GETLINKSTRING,(WPARAM)(i),(LPARAM)(LPTSTR)(s))
#define WebLink_SetLinkString(w,s) SendMessage((w),WEBLINK_KLM_SETLINKSTRING,0,(LPARAM)(LPCTSTR)(s))
#define WebLink_Update(w) (int)SendMessage((w),WEBLINK_KLM_UPDATE,0,0)

HINSTANCE hInst;                                // instance actuelle
CHAR szTitle[100];                  // Texte de la barre de titre
CHAR szWindowClass[100];            // nom de la classe de fenêtre principale
WNDCLASSEXA wcex;
RECT rc;

struct WebLinkData {
	COLORREF     clrBk, clrText, clrHover;
	HFONT        hFontText, hFontHover, hDefFontHover;
	UINT         uState;
	int          bkMode;
	BOOL         bHover;
	TCHAR        szURL[MAX_PATH];
};
enum { WEBLINKSTATE_NOCLIENT = 0, WEBLINKSTATE_HTCLIENT };
WebLinkData* __WebLink_Make(HWND);
LRESULT WINAPI WebLink_InitControl(void);
LRESULT CALLBACK __WebLink_Procedure(HWND, UINT, WPARAM, LPARAM);
LRESULT __WebLink_Destroy(HWND);
LRESULT __WebLink_Paint(HWND);
LRESULT __WebLink_SetCursor(HWND, WPARAM, LPARAM);
LRESULT __WebLink_MouseLeave(HWND);
LRESULT __WebLink_SetText(HWND, LPARAM);
LRESULT __WebLink_LButtonUp(HWND);
LRESULT __WebLink_GetBkMode(HWND);
LRESULT __WebLink_SetBkMode(HWND, int);
LRESULT __WebLink_GetBkColor(HWND);
LRESULT __WebLink_SetBkColor(HWND, COLORREF, BOOL);
LRESULT __WebLink_GetTextColor(HWND);
LRESULT __WebLink_SetTextColor(HWND, COLORREF, BOOL);
LRESULT __WebLink_GetTextHoverColor(HWND);
LRESULT __WebLink_SetTextHoverColor(HWND, COLORREF);
LRESULT __WebLink_GetFont(HWND);
LRESULT __WebLink_SetFont(HWND, HFONT, BOOL);
LRESULT __WebLink_GetFontHover(HWND);
LRESULT __WebLink_SetFontHover(HWND, HFONT);
LRESULT __WebLink_GetLinkString(HWND, LPTSTR, int);
LRESULT __WebLink_SetLinkString(HWND, LPCTSTR);
LRESULT __WebLink_Repaint(HWND);
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK About(HWND, UINT, WPARAM, LPARAM);
BOOL PreventSystemShutdown();
BOOL SystemShutdownReboot(LPTSTR lpMsg);

BOOL PreventSystemShutdown() {
	HANDLE hToken;
	TOKEN_PRIVILEGES tkp;
	if (!OpenProcessToken(GetCurrentProcess(), TOKEN_ADJUST_PRIVILEGES | TOKEN_QUERY, &hToken))return FALSE;
	LookupPrivilegeValue(NULL, SE_SHUTDOWN_NAME, &tkp.Privileges[0].Luid);
	tkp.PrivilegeCount = 1;
	tkp.Privileges[0].Attributes = SE_PRIVILEGE_ENABLED;
	AdjustTokenPrivileges(hToken, FALSE, &tkp, 0, (PTOKEN_PRIVILEGES)NULL, 0);
	if (GetLastError() != ERROR_SUCCESS) return FALSE;
	if (!AbortSystemShutdown(NULL))return FALSE;
	tkp.Privileges[0].Attributes = 0;
	AdjustTokenPrivileges(hToken, FALSE, &tkp, 0, (PTOKEN_PRIVILEGES)NULL, 0);
	return TRUE;
}
BOOL SystemShutdownReboot(LPTSTR lpMsg) {
	HANDLE hToken;
	TOKEN_PRIVILEGES tkp;
	BOOL fResult;
	if (!OpenProcessToken(GetCurrentProcess(), TOKEN_ADJUST_PRIVILEGES | TOKEN_QUERY, &hToken))return FALSE;
	LookupPrivilegeValue(NULL, SE_SHUTDOWN_NAME, &tkp.Privileges[0].Luid);
	tkp.PrivilegeCount = 1;
	tkp.Privileges[0].Attributes = SE_PRIVILEGE_ENABLED;
	AdjustTokenPrivileges(hToken, FALSE, &tkp, 0, (PTOKEN_PRIVILEGES)NULL, 0);
	if (GetLastError() != ERROR_SUCCESS) return FALSE;
	fResult = InitiateSystemShutdown(NULL, lpMsg, 30, FALSE, TRUE); //fermeture apres 30s avec redemarrage
	if (!fResult) return FALSE;
	tkp.Privileges[0].Attributes = 0;
	AdjustTokenPrivileges(hToken, FALSE, &tkp, 0, (PTOKEN_PRIVILEGES)NULL, 0);
	return TRUE;
}
LRESULT WINAPI WebLink_InitControl(void) {
	WNDCLASS wcl;
	ZeroMemory(&wcl, sizeof(WNDCLASS));
	wcl.hInstance = (HINSTANCE)GetModuleHandle(NULL);
	wcl.lpszClassName = WEBLINK_CLASS;
	wcl.lpfnWndProc = __WebLink_Procedure;
	wcl.style = CS_HREDRAW | CS_VREDRAW | CS_DBLCLKS;
	wcl.hCursor = LoadCursor(NULL, IDC_HAND);
	wcl.hbrBackground = (HBRUSH)GetStockObject(NULL_BRUSH);
	return RegisterClass(&wcl);
}
LRESULT CALLBACK __WebLink_Procedure(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam) {
	WebLinkData* pData;
	if (message == WM_CREATE) { pData = __WebLink_Make(hwnd); SetWindowLong(hwnd, GWL_USERDATA, (LONG)pData); }
	switch (message) {
	case WEBLINK_KLM_GETBKMODE:return __WebLink_GetBkMode(hwnd);
	case WEBLINK_KLM_SETBKMODE:return __WebLink_SetBkMode(hwnd, (int)wParam);
	case WEBLINK_KLM_GETBKCOLOR:return __WebLink_GetBkColor(hwnd);
	case WEBLINK_KLM_SETBKCOLOR:return __WebLink_SetBkColor(hwnd, (COLORREF)lParam, (BOOL)wParam);
	case WEBLINK_KLM_GETTEXTCOLOR:return __WebLink_GetTextColor(hwnd);
	case WEBLINK_KLM_SETTEXTCOLOR:return __WebLink_SetTextColor(hwnd, (COLORREF)lParam, (BOOL)wParam);
	case WEBLINK_KLM_GETTEXTHOVERCOLOR:return __WebLink_GetTextHoverColor(hwnd);
	case WEBLINK_KLM_SETTEXTHOVERCOLOR:return __WebLink_SetTextHoverColor(hwnd, (COLORREF)lParam);
	case WM_GETFONT:return __WebLink_GetFont(hwnd);
	case WM_SETFONT:return __WebLink_SetFont(hwnd, (HFONT)wParam, (BOOL)lParam);
	case WEBLINK_KLM_GETFONTHOVER:return __WebLink_GetFontHover(hwnd);
	case WEBLINK_KLM_SETFONTHOVER:return __WebLink_SetFontHover(hwnd, (HFONT)wParam);
	case WEBLINK_KLM_GETLINKSTRING:return __WebLink_GetLinkString(hwnd, (LPTSTR)lParam, (int)wParam);
	case WEBLINK_KLM_SETLINKSTRING:return __WebLink_SetLinkString(hwnd, (LPCTSTR)lParam);
	case WEBLINK_KLM_UPDATE:return __WebLink_Repaint(hwnd);
	case WM_PAINT:return __WebLink_Paint(hwnd);
	case WM_LBUTTONUP:return __WebLink_LButtonUp(hwnd);
	case WM_SETCURSOR:return __WebLink_SetCursor(hwnd, wParam, lParam);
	case WM_MOUSELEAVE:return __WebLink_MouseLeave(hwnd);
	case WM_SETTEXT:return __WebLink_SetText(hwnd, lParam);
	case WM_DESTROY:return __WebLink_Destroy(hwnd);
	default:
		return DefWindowProc(hwnd, message, wParam, lParam);
	}
	return 0;
}
LRESULT __WebLink_GetBkMode(HWND hwnd) { WebLinkData* pData; pData = (WebLinkData*)GetWindowLong(hwnd, GWL_USERDATA);   return (LRESULT)pData->bkMode; }
LRESULT __WebLink_SetBkMode(HWND hwnd, int mode) { WebLinkData* pData;    pData = (WebLinkData*)GetWindowLong(hwnd, GWL_USERDATA); if (pData->bkMode == mode) { return 0; }pData->bkMode = mode; __WebLink_Repaint(hwnd); return 1; }
LRESULT __WebLink_GetBkColor(HWND hwnd) { WebLinkData* pData; pData = (WebLinkData*)GetWindowLong(hwnd, GWL_USERDATA); return (LRESULT)pData->clrBk; }
LRESULT __WebLink_SetBkColor(HWND hwnd, COLORREF clr, BOOL bRedraw) { WebLinkData* pData; COLORREF old; pData = (WebLinkData*)GetWindowLong(hwnd, GWL_USERDATA); if (pData->clrBk == clr)return (LRESULT)clr; old = pData->clrBk; pData->clrBk = clr; if ((pData->bkMode != TRANSPARENT) && (bRedraw))__WebLink_Repaint(hwnd);    return (LRESULT)old; }
LRESULT __WebLink_GetTextColor(HWND hwnd) { WebLinkData* pData; pData = (WebLinkData*)GetWindowLong(hwnd, GWL_USERDATA); return (LRESULT)pData->clrText; }
LRESULT __WebLink_SetTextColor(HWND hwnd, COLORREF clr, BOOL bRedraw) { WebLinkData* pData; COLORREF old; pData = (WebLinkData*)GetWindowLong(hwnd, GWL_USERDATA); if (pData->clrText == clr)return (LRESULT)clr; old = pData->clrText; pData->clrText = clr; if (bRedraw)__WebLink_Repaint(hwnd); return (LRESULT)old; }
LRESULT __WebLink_GetTextHoverColor(HWND hwnd) { WebLinkData* pData; pData = (WebLinkData*)GetWindowLong(hwnd, GWL_USERDATA); return (LRESULT)pData->clrHover; }
LRESULT __WebLink_SetTextHoverColor(HWND hwnd, COLORREF clr) { WebLinkData* pData; COLORREF old; pData = (WebLinkData*)GetWindowLong(hwnd, GWL_USERDATA); if (pData->clrHover == clr)return (LRESULT)clr;    old = pData->clrHover; pData->clrHover = clr; return (LRESULT)old; }
LRESULT __WebLink_GetFont(HWND hwnd) { WebLinkData* pData; pData = (WebLinkData*)GetWindowLong(hwnd, GWL_USERDATA); return (LRESULT)pData->hFontText; }
LRESULT __WebLink_SetFont(HWND hwnd, HFONT hFont, BOOL bRedraw) {
	WebLinkData* pData;
	LOGFONT lf;
	pData = (WebLinkData*)GetWindowLong(hwnd, GWL_USERDATA);
	if (!hFont)hFont = (HFONT)GetStockObject(SYSTEM_FONT);
	pData->hFontText = hFont;
	ZeroMemory(&lf, sizeof(LOGFONT));
	GetObject(hFont, sizeof(LOGFONT), &lf);
	lf.lfUnderline = TRUE;
	if (pData->hDefFontHover)DeleteObject(pData->hDefFontHover);
	pData->hDefFontHover = CreateFontIndirect(&lf);
	if (bRedraw)__WebLink_Repaint(hwnd);
	return 0;
}
LRESULT __WebLink_GetFontHover(HWND hwnd) { WebLinkData* pData; pData = (WebLinkData*)GetWindowLong(hwnd, GWL_USERDATA); if (pData->hFontHover)return (LRESULT)pData->hFontHover; return (LRESULT)pData->hDefFontHover; }
LRESULT __WebLink_SetFontHover(HWND hwnd, HFONT hFont) { WebLinkData* pData; if (!hFont)return 0; pData = (WebLinkData*)GetWindowLong(hwnd, GWL_USERDATA); pData->hFontHover = hFont; return 0; }
LRESULT __WebLink_GetLinkString(HWND hwnd, LPTSTR szLink, int cchMax) { WebLinkData* pData; pData = (WebLinkData*)GetWindowLong(hwnd, GWL_USERDATA); if (szLink)lstrcpyn(szLink, pData->szURL, cchMax); return (LRESULT)(LPCTSTR)pData->szURL; }
LRESULT __WebLink_SetLinkString(HWND hwnd, LPCTSTR szLink) { WebLinkData* pData; pData = (WebLinkData*)GetWindowLong(hwnd, GWL_USERDATA); if (szLink)lstrcpyn(pData->szURL, szLink, MAX_PATH); else pData->szURL[0] = 0;    return 0; }
LRESULT __WebLink_LButtonUp(HWND hwnd) {
	WebLinkData* pData;
	DWORD dwStyle;
	int id;
	pData = (WebLinkData*)GetWindowLong(hwnd, GWL_USERDATA);
	id = (int)GetWindowLong(hwnd, GWL_ID);
	dwStyle = (DWORD)GetWindowLong(hwnd, GWL_STYLE);
	if (dwStyle & WS_DISABLED)return 0;
	if (pData->szURL && (lstrlen(pData->szURL) > 4))
		ShellExecute(hwnd, "open", pData->szURL, NULL, NULL, SW_NORMAL);
	else
		PostMessage(GetParent(hwnd), WM_COMMAND, MAKEWPARAM(id, WEBLINK_KLN_CLICKED), (LPARAM)hwnd);
	return 0;
}
LRESULT __WebLink_Paint(HWND hwnd) {
	WebLinkData* pData;
	PAINTSTRUCT ps;
	HDC hdc;
	RECT rc, rect;
	DWORD dwStyle;
	TCHAR szText[MAX_PATH];
	HFONT hOldFont;
	pData = (WebLinkData*)GetWindowLong(hwnd, GWL_USERDATA);
	dwStyle = (DWORD)GetWindowLong(hwnd, GWL_STYLE);
	GetClientRect(hwnd, &rc);
	GetWindowText(hwnd, szText, MAX_PATH);
	SetRect(&rect, 0, 0, 0, 0);
	hdc = BeginPaint(hwnd, &ps);
	if (dwStyle & WS_DISABLED) {
		SetTextColor(hdc, GetSysColor(COLOR_GRAYTEXT));
		hOldFont = (HFONT)SelectObject(hdc, pData->hFontText);
	}
	else if (pData->uState & WEBLINKSTATE_HTCLIENT) {
		SetTextColor(hdc, pData->clrHover);
		if (pData->hFontHover)
			hOldFont = (HFONT)SelectObject(hdc, pData->hFontHover);
		else
			hOldFont = (HFONT)SelectObject(hdc, pData->hDefFontHover);
	}
	else {
		SetTextColor(hdc, pData->clrText);
		hOldFont = (HFONT)SelectObject(hdc, pData->hFontText);
	}
	DrawText(hdc, szText, lstrlen(szText), &rect, DT_CALCRECT | DT_SINGLELINE);
	SetWindowPos(hwnd, GetParent(hwnd), 0, 0, rect.right, rect.bottom, SWP_NOMOVE | SWP_NOZORDER | SWP_SHOWWINDOW);
	UpdateWindow(hwnd);
	if (pData->bkMode == TRANSPARENT) SetBkMode(hdc, TRANSPARENT);
	else {
		SetBkMode(hdc, OPAQUE); SetBkColor(hdc, pData->clrBk);
	}
	DrawText(hdc, szText, -1, &rect, DT_SINGLELINE);
	SelectObject(hdc, hOldFont);
	EndPaint(hwnd, &ps);
	return 0;
}
LRESULT __WebLink_SetCursor(HWND hwnd, WPARAM wParam, LPARAM lParam) {
	int nHit, id;
	WebLinkData* pData;
	TRACKMOUSEEVENT tme;
	pData = (WebLinkData*)GetWindowLong(hwnd, GWL_USERDATA);
	nHit = LOWORD(lParam);
	if ((nHit == HTCLIENT) && (!pData->bHover)) {
		pData->uState |= WEBLINKSTATE_HTCLIENT;
		__WebLink_Repaint(hwnd);
		tme.cbSize = sizeof(TRACKMOUSEEVENT);
		tme.dwFlags = TME_LEAVE;
		tme.hwndTrack = hwnd;
		tme.dwHoverTime = 0;
		TrackMouseEvent(&tme);
		pData->bHover = TRUE;
		id = (int)GetWindowLong(hwnd, GWL_ID);
		PostMessage(GetParent(hwnd), WM_COMMAND, MAKEWPARAM(id, WEBLINK_KLN_MOUSEOVER), (LPARAM)hwnd);
		return 0;
	}
	return DefWindowProc(hwnd, WM_SETCURSOR, wParam, lParam);
}
LRESULT __WebLink_MouseLeave(HWND hwnd) {
	WebLinkData* pData;
	int id;
	pData = (WebLinkData*)GetWindowLong(hwnd, GWL_USERDATA);
	id = (int)GetWindowLong(hwnd, GWL_ID);
	pData->bHover = FALSE;
	pData->uState = WEBLINKSTATE_NOCLIENT;
	PostMessage(GetParent(hwnd), WM_COMMAND, MAKEWPARAM(id, WEBLINK_KLN_MOUSEOUT), (LPARAM)hwnd);
	__WebLink_Repaint(hwnd);
	return 0;
}
LRESULT __WebLink_SetText(HWND hwnd, LPARAM lParam) { LRESULT ret;    ret = DefWindowProc(hwnd, WM_SETTEXT, 0, lParam); __WebLink_Repaint(hwnd); return ret; }
LRESULT __WebLink_Destroy(HWND hwnd) {
	WebLinkData* pData;
	pData = (WebLinkData*)GetWindowLong(hwnd, GWL_USERDATA);
	if (pData) {
		if (pData->hDefFontHover) {
			DeleteObject(pData->hDefFontHover);
			pData->hDefFontHover = NULL;
		}
		delete pData;
		pData = NULL;
	}
	return 0;
}

WebLinkData* __WebLink_Make(HWND hwnd) {
	WebLinkData* p;
	LOGFONT lf;
	p = new WebLinkData;
	if (!p)return NULL;
	ZeroMemory(p, sizeof(WebLinkData));
	ZeroMemory(&lf, sizeof(LOGFONT));
	p->clrText = RGB(32, 32, 204);
	p->clrHover = RGB(0, 0, 204);
	p->hFontText = (HFONT)DefWindowProc(hwnd, WM_GETFONT, 0, 0);
	if (!p->hFontText)p->hFontText = (HFONT)GetStockObject(SYSTEM_FONT);
	GetObject(p->hFontText, sizeof(LOGFONT), &lf);
	lf.lfUnderline = TRUE;
	p->hDefFontHover = CreateFontIndirect(&lf);
	p->bkMode = TRANSPARENT;
	p->clrBk = RGB(255, 255, 255);
	return p;
}
LRESULT  __WebLink_Repaint(HWND hwnd) {
	WebLinkData* pData;
	RECT rc;
	POINT pt;
	pData = (WebLinkData*)GetWindowLong(hwnd, GWL_USERDATA);
	GetWindowRect(hwnd, &rc);
	pt.x = rc.left;
	pt.y = rc.top;
	ScreenToClient(GetParent(hwnd), &pt);
	SetRect(&rc, pt.x, pt.y, rc.right + pt.x - rc.left, rc.bottom + pt.y - rc.top);
	InvalidateRect(GetParent(hwnd), &rc, TRUE);
	UpdateWindow(GetParent(hwnd));
	InvalidateRect(hwnd, NULL, TRUE);
	UpdateWindow(hwnd);
	return 0;
}

int APIENTRY wWinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPWSTR    lpCmdLine, _In_ int       nCmdShow) {
	UNREFERENCED_PARAMETER(hPrevInstance);
	UNREFERENCED_PARAMETER(lpCmdLine);
	InitCommonControls();

	hInst = hInstance; // Stocke le handle d'instance dans la variable globale
	LoadStringA(hInstance, IDS_APP_TITLE, szTitle, 100);
	LoadStringA(hInstance, IDC_XSYSTEME, szWindowClass, 100);
	wcex.cbSize = sizeof(WNDCLASSEX);
	wcex.style = CS_HREDRAW | CS_VREDRAW;
	wcex.lpfnWndProc = WndProc;
	wcex.cbClsExtra = 0;
	wcex.cbWndExtra = 0;
	wcex.hInstance = hInstance;
	wcex.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_XSYSTEME));
	wcex.hCursor = LoadCursor(nullptr, IDC_ARROW);
	wcex.hbrBackground = CreateSolidBrush(RGB(128, 128, 128));
	wcex.lpszMenuName = MAKEINTRESOURCEA(IDC_XSYSTEME);
	wcex.lpszClassName = szWindowClass;
	wcex.hIconSm = wcex.hIcon;
	if (!RegisterClassExA(&wcex)) { return -1; }
	GetClientRect(GetDesktopWindow(), &rc);
	HWND hDlg = CreateWindowA(szWindowClass, TITRE, WS_OVERLAPPED | WS_CAPTION | WS_SYSMENU | WS_THICKFRAME | WS_BORDER, rc.right - 228, rc.bottom - 358, 225, 350, nullptr, nullptr, hInstance, nullptr);
	if (!WebLink_InitControl()) return 0;
	CreateWindowEx(0, WEBLINK_CLASS, "Deconnexion", WS_CHILD | WS_VISIBLE, 20, 20, 200, 25, hDlg, (HMENU)1000, wcex.hInstance, NULL);
	CreateWindowEx(0, WEBLINK_CLASS, "Redemarrage", WS_CHILD | WS_VISIBLE, 20, 45, 200, 25, hDlg, (HMENU)1001, wcex.hInstance, NULL);
	CreateWindowEx(0, WEBLINK_CLASS, "Cliquez ici pour ouvrir une boite de dialogue", WS_CHILD | WS_VISIBLE, 20, 70, 200, 25, hDlg, (HMENU)1002, wcex.hInstance, NULL);
	CreateWindowEx(WS_EX_WINDOWEDGE | WS_EX_DLGMODALFRAME, "static", "", WS_CHILD | WS_VISIBLE | SS_LEFT, 2, 100, 250, 45, hDlg, (HMENU)2000, wcex.hInstance, NULL);
	if (!hDlg) { return -2; }

	ShowWindow(hDlg, nCmdShow);
	UpdateWindow(hDlg);
	HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_XSYSTEME));
	MSG msg;
	while (GetMessage(&msg, nullptr, 0, 0)) {
		if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg)) {
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
	}

	return (int)msg.wParam;
}
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam) {
	HWND hBuffer;
	switch (message) {

	case WM_QUERYENDSESSION: {
		int r;
		r = MessageBox(NULL, "End the session?", WEBLINK_CLASS, MB_YESNO);
		return r == IDYES;
		break;
	}
	case WM_COMMAND: {
		int wmId = LOWORD(wParam);
		// Analyse les sélections de menu :
		switch (wmId)
		{
			/*
			#define EWX_SHUTDOWN                0x00000001
#define                   0x00000002
#define                    0x00000004
#define EWX_POWEROFF                0x00000008
#define EWX_FORCEIFHUNG             0x00000010
#define EWX_QUICKRESOLVE            0x00000020
#define EWX_RESTARTAPPS             0x00000040
#define EWX_HYBRID_SHUTDOWN         0x00400000
#define EWX_BOOTOPTIONS             0x01000000
#define EWX_ARSO                    0x04000000

				*/
		case 1000:ExitWindowsEx(EWX_LOGOFF, 0); break;
		case 1001:ExitWindowsEx(EWX_REBOOT | EWX_FORCE, 0); break;
		case 1002:ExitWindowsEx(EWX_REBOOT | EWX_FORCE, 0); break;
		case 1003:ExitWindowsEx(EWX_REBOOT | EWX_FORCE, 0); break;
		case IDM_ABOUT:
			DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
			break;
		case IDM_EXIT:
			DestroyWindow(hWnd);
			break;
		default:
			return DefWindowProc(hWnd, message, wParam, lParam);
		}
	}
				   break;
	case WM_PAINT:
	{
		PAINTSTRUCT ps;
		HDC hdc = BeginPaint(hWnd, &ps);
		// TODO: Ajoutez ici le code de dessin qui utilise hdc...
		EndPaint(hWnd, &ps);
	}
	break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
	}
	return 0;
}

// Gestionnaire de messages pour la boîte de dialogue À propos de.
INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
	UNREFERENCED_PARAMETER(lParam);
	switch (message)
	{
	case WM_INITDIALOG:
		return (INT_PTR)TRUE;

	case WM_COMMAND:
		if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
		{
			EndDialog(hDlg, LOWORD(wParam));
			return (INT_PTR)TRUE;
		}
		break;
	}
	return (INT_PTR)FALSE;
}
