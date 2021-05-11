#define LearningChapter "ex6-6"
//page 265

#include <Windows.h>
#include <tchar.h>
#include <stdio.h>
#include "resource.h"

LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg, WPARAM wParam, LPARAM lParam);
static LPCTSTR WindowClassName = _T(LearningChapter) _T(" Class");
static LPCTSTR WindowTitleName = _T(LearningChapter);
static const int WindowPosition[2] = { 400, 200 };
static const int WindowSize[2] = { 720, 480 };

//BOOL CALLBACK Dlg6_xProc(HWND hDlg, UINT iMsg, WPARAM wParam, LPARAM lParam);
BOOL CALLBACK Dlg6_2Proc(HWND hDlg, UINT iMsg, WPARAM wParam, LPARAM lParam);
BOOL CALLBACK Dlg6_3Proc(HWND hDlg, UINT iMsg, WPARAM wParam, LPARAM lParam);
BOOL CALLBACK Dlg6_4Proc(HWND hDlg, UINT iMsg, WPARAM wParam, LPARAM lParam);
BOOL CALLBACK Dlg6_5Proc(HWND hDlg, UINT iMsg, WPARAM wParam, LPARAM lParam);
BOOL CALLBACK Dlg6_6Proc(HWND hDlg, UINT iMsg, WPARAM wParam, LPARAM lParam);
HINSTANCE g_hInstance;

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpszCmdLine, int nCmdShow)
{
	HWND hwnd;
	MSG msg;
	WNDCLASS WndClass;
	g_hInstance = hInstance;
	WndClass.style = CS_HREDRAW | CS_VREDRAW;
	WndClass.lpfnWndProc = WndProc;
	WndClass.cbClsExtra = 0;
	WndClass.cbWndExtra = 0;
	WndClass.hInstance = hInstance;
	WndClass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	WndClass.hCursor = LoadCursor(NULL, IDC_ARROW);
	WndClass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	WndClass.lpszMenuName = MAKEINTRESOURCE(IDR_MENU6_3);
	WndClass.lpszClassName = WindowClassName;

	RegisterClass(&WndClass);
	hwnd = CreateWindow(WindowClassName, WindowTitleName,
		WS_OVERLAPPEDWINDOW,
		WindowPosition[0], WindowPosition[1],
		WindowSize[0], WindowSize[1],
		NULL, NULL, hInstance, NULL
	);

	ShowWindow(hwnd, nCmdShow);
	UpdateWindow(hwnd);
	while (GetMessage(&msg, NULL, 0, 0)) {
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	return (int)msg.wParam;
}

LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg, WPARAM wParam, LPARAM lParam)
{
	switch (iMsg) {
	case WM_CREATE:
		return 0;
	case WM_COMMAND:
		switch (LOWORD(wParam)) {
		case ID_6_3_MENU:
			DialogBox(g_hInstance, MAKEINTRESOURCE(IDD_DIALOG6_3), hwnd, (DLGPROC)Dlg6_3Proc);
			break;
		case ID_6_4_MENU:
			DialogBox(g_hInstance, MAKEINTRESOURCE(IDD_DIALOG6_4), hwnd, (DLGPROC)Dlg6_4Proc);
			break;
		case ID_6_5_MENU:
			DialogBox(g_hInstance, MAKEINTRESOURCE(IDD_DIALOG6_5), hwnd, (DLGPROC)Dlg6_5Proc);
			break;
		case ID_6_6_MENU:
			DialogBox(g_hInstance, MAKEINTRESOURCE(IDD_DIALOG6_6), hwnd, (DLGPROC)Dlg6_6Proc);
			break;
		case ID_6_7_MENU:
			MessageBox(hwnd, _T("실습6-7 대화상자가 준비되지 않았습니다."), _T("알림"), MB_OK);
			break;
		case ID_6_8_MENU:
			MessageBox(hwnd, _T("실습6-8 대화상자가 준비되지 않았습니다."), _T("알림"), MB_OK);
			break;
		case ID_6_9_MENU:
			MessageBox(hwnd, _T("실습6-9 대화상자가 준비되지 않았습니다."), _T("알림"), MB_OK);
			break;
		case ID_6_10_MENU:
			MessageBox(hwnd, _T("실습6-10 대화상자가 준비되지 않았습니다."), _T("알림"), MB_OK);
			break;
		case ID_6_11_MENU:
			MessageBox(hwnd, _T("실습6-11 대화상자가 준비되지 않았습니다."), _T("알림"), MB_OK);
			break;
		case ID_6_12_MENU:
			MessageBox(hwnd, _T("실습6-12 대화상자가 준비되지 않았습니다."), _T("알림"), MB_OK);
			break;
		case ID_6_13_MENU:
			MessageBox(hwnd, _T("실습6-13 대화상자가 준비되지 않았습니다."), _T("알림"), MB_OK);
			break;
		}
		return 0;
	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
	}
	return DefWindowProc(hwnd, iMsg, wParam, lParam);
}

/*
BOOL CALLBACK Dlg6_xProc(HWND hDlg, UINT iMsg, WPARAM wParam, LPARAM lParam)
{
	switch (iMsg)
	{
	case WM_INITDIALOG:
		return TRUE;
	case WM_COMMAND:
		switch (LOWORD(wParam))
		{
		case IDCANCEL:
			EndDialog(hDlg, 0);
			break;
		}
		break;
	}
	return FALSE;
}
*/

BOOL CALLBACK Dlg6_6Proc(HWND hDlg, UINT iMsg, WPARAM wParam, LPARAM lParam)
{
	static HWND hCombo;
	static int selection;
	TCHAR name[20];

	switch (iMsg)
	{
	case WM_INITDIALOG:
		hCombo = GetDlgItem(hDlg, IDC_COMBO_LIST);
		return TRUE;
	case WM_COMMAND:
		switch (LOWORD(wParam))
		{
		case IDCANCEL:
			EndDialog(hDlg, 0);
			break;
		}
		break;
	}
	return FALSE;
}



BOOL CALLBACK Dlg6_2Proc(HWND hDlg, UINT iMsg, WPARAM wParam, LPARAM lParam)
{
	HDC hdc;
	LPCTSTR str;
	switch (iMsg)
	{
	case WM_INITDIALOG:
		return 1;
	case WM_COMMAND:
		switch (LOWORD(wParam))
		{
		case ID_BUTTON_PRINT:
			hdc = GetDC(hDlg);
			str = _T("The Quick Brown Fox Jumps Over the Lazy Dog.");
			TextOut(hdc, 10, 10, str, _tcslen(str));
			ReleaseDC(hDlg, hdc);
			break;
		case ID_BUTTON_END:
			EndDialog(hDlg, 0);
			break;
		}
	}
	return 0;
}

BOOL CALLBACK Dlg6_3Proc(HWND hDlg, UINT iMsg, WPARAM wParam, LPARAM lParam)
{
	HWND hButton;

	switch (iMsg)
	{
	case WM_INITDIALOG:
		hButton = GetDlgItem(hDlg, ID_PAUSE);
		EnableWindow(hButton, FALSE);
		return 1;
	case WM_COMMAND:
		switch (LOWORD(wParam))
		{
		case ID_START:
			hButton = GetDlgItem(hDlg, ID_START);
			EnableWindow(hButton, FALSE);
			hButton = GetDlgItem(hDlg, ID_PAUSE);
			EnableWindow(hButton, TRUE);
			break;
		case ID_PAUSE:
			hButton = GetDlgItem(hDlg, ID_START);
			EnableWindow(hButton, TRUE);
			hButton = GetDlgItem(hDlg, ID_PAUSE);
			EnableWindow(hButton, FALSE);
			break;
		case ID_CLOSE:
			EndDialog(hDlg, 0);
			break;
		case IDCANCEL:
			EndDialog(hDlg, 0);
			break;
		}
		break;
	}

	return FALSE;
}

BOOL CALLBACK Dlg6_4Proc(HWND hDlg, UINT iMsg, WPARAM wParam, LPARAM lParam)
{
	TCHAR word[100];

	switch (iMsg)
	{
	case WM_INITDIALOG:
		return TRUE;
	case WM_COMMAND:
		switch (LOWORD(wParam))
		{
		case ID_BUTTON_COPY:
			GetDlgItemText(hDlg, IDC_EDIT_SOURCE, word, 100);
			SetDlgItemText(hDlg, IDC_EDIT_COPY, word);
			break;
		case ID_BUTTON_CLEAR:
			SetDlgItemText(hDlg, IDC_EDIT_SOURCE, _T(""));
			SetDlgItemText(hDlg, IDC_EDIT_COPY, _T(""));
			break;
		case IDCANCEL:
			EndDialog(hDlg, 0);
			break;
		}
		break;
	}
	return FALSE;
}

BOOL CALLBACK Dlg6_5Proc(HWND hDlg, UINT iMsg, WPARAM wParam, LPARAM lParam)
{
	static int Check[3], Radio;
	TCHAR hobby[][30] = { _T("독서"), _T("음악감상"), _T("인터넷") };
	TCHAR sex[][30] = { _T("여자"), _T("남자") };
	TCHAR output[200];

	switch (iMsg)
	{
	case WM_INITDIALOG:
		CheckRadioButton(hDlg, IDC_RADIO_FEMALE, IDC_RADIO_MALE, IDC_RADIO_FEMALE);
		return TRUE;
	case WM_COMMAND:
		switch (LOWORD(wParam))
		{
		case IDC_CHECK_READING:
			Check[0] = 1 - Check[0];
			break;
		case IDC_CHECK_MUSIC:
			Check[1] = 1 - Check[1];
			break;
		case IDC_CHECK_INTERNET:
			Check[2] = 1 - Check[2];
			break;
		case IDC_RADIO_FEMALE:
			Radio = 0;
			break;
		case IDC_RADIO_MALE:
			Radio = 1;
			break;
		case IDC_BUTTON_OUTPUT:
			_stprintf_s(output, _T("선택한 취미는 %s %s %s입니다.\r\n")
				_T("선택한 성별은 %s입니다."),
				Check[0] ? hobby[0] : _T(""), Check[1] ? hobby[1] : _T(""), Check[2] ? hobby[2] : _T(""),
				sex[Radio]);
			SetDlgItemText(hDlg, IDC_EDIT_OUTPUT, output);
			break;
		case IDCANCEL:
			EndDialog(hDlg, 0);
			break;
		}
		break;
	}
	return FALSE;
}