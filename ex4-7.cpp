#define LearningChapter "ex4-7"

#include <Windows.h>
#include <tchar.h>
#include <stdio.h>
#include "resource.h"

LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg, WPARAM wParam, LPARAM lParam);
static LPCTSTR WindowClassName = _T(LearningChapter) _T(" Class");
static LPCTSTR WindowTitleName = _T(LearningChapter);
static const int WindowPosition[2] = { 400, 200 };
static const int WindowSize[2] = { 720, 480 };

void wincmd_fileopen(HWND hwnd);
void wincmd_filesave(HWND hwnd);
int wincmd_fontdlg(HWND hwnd, LPCHOOSEFONT FONT, LPLOGFONT LogFont);
void OutFromFile(TCHAR filename[], HWND hwnd);

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpszCmdLine, int nCmdShow)
{
	HWND hwnd;
	MSG msg;
	WNDCLASS WndClass;
	WndClass.style = CS_HREDRAW | CS_VREDRAW;
	WndClass.lpfnWndProc = WndProc;
	WndClass.cbClsExtra = 0;
	WndClass.cbWndExtra = 0;
	WndClass.hInstance = hInstance;
	WndClass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	WndClass.hCursor = LoadCursor(NULL, IDC_ARROW);
	WndClass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	WndClass.lpszMenuName = MAKEINTRESOURCE(IDR_MENU4_7);
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
	static CHOOSEFONT FONT;
	static LOGFONT LogFont;

	PAINTSTRUCT ps;
	HDC hdc;
	HFONT hFont, oldFont;

	switch (iMsg) {
	case WM_CREATE:
		return 0;
	case WM_PAINT:
		hdc = BeginPaint(hwnd, &ps);
		hFont = CreateFontIndirect(&LogFont);
		oldFont = (HFONT)SelectObject(hdc, hFont);
		SetTextColor(hdc, FONT.rgbColors);
		TextOut(hdc, 10, 10, _T("The quick brown fox jumps over the lazy dog."), 46);
		SelectObject(hdc, oldFont);
		DeleteObject(hFont);
		EndPaint(hwnd, &ps);
		return 0;
	case WM_COMMAND:
		switch (LOWORD(wParam))
		{
		case ID_FILENEW:
			MessageBox(hwnd,
				_T("�� ������ ���ðڽ��ϱ�?"),
				_T("�� ���� ����"),
				MB_OKCANCEL);
			break;
		case ID_FILEOPEN:
			wincmd_fileopen(hwnd);
			break;
		case ID_FILESAVE:
			wincmd_filesave(hwnd);
			break;
		case ID_FONTDLG:
			if (wincmd_fontdlg(hwnd, &FONT, &LogFont) != 0)
				InvalidateRgn(hwnd, NULL, TRUE);
			break;
		case ID_EXIT:
			int answer = MessageBox(hwnd,
				_T("������ �����ϰ� �����ڽ��ϱ�?"),
				_T("������ ����"),
				MB_YESNOCANCEL);
			if (answer == IDYES)
			{
				wincmd_filesave(hwnd);
				PostQuitMessage(0);
			}
			break;
		}
		return 0;
	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
	}
	return DefWindowProc(hwnd, iMsg, wParam, lParam);
}

void wincmd_fileopen(HWND hwnd)
{
	OPENFILENAME OFN;
	TCHAR str[100], lpstrFile[100] = _T("");
	TCHAR filter[] = _T(
		"Every File(*.*)\0"
		"*.*\0"
		"Text File(*.txt, *.doc)\0"
		"*.txt;*.doc\0");

	memset(&OFN, 0, sizeof(OPENFILENAME));
	OFN.lStructSize = sizeof(OPENFILENAME);
	OFN.hwndOwner = hwnd;
	OFN.lpstrFilter = filter;
	OFN.lpstrFile = lpstrFile;
	OFN.nMaxFile = 100;
	OFN.lpstrInitialDir = _T(".");
	if (GetOpenFileName(&OFN) != 0)
		OutFromFile(OFN.lpstrFile, hwnd);
}

void wincmd_filesave(HWND hwnd)
{
	OPENFILENAME SFN;
	TCHAR str[100], lpstrFile[100] = _T("");
	TCHAR filter[] = _T(
		"Every File(*.*)\0"
		"*.*\0"
		"Text File(*.txt, *.doc)\0"
		"*.txt;*.doc\0");

	memset(&SFN, 0, sizeof(OPENFILENAME));
	SFN.lStructSize = sizeof(OPENFILENAME);
	SFN.hwndOwner = hwnd;
	SFN.lpstrFilter = filter;
	SFN.lpstrFile = lpstrFile;
	SFN.nMaxFile = 256;
	SFN.lpstrInitialDir = _T(".");
	if (GetSaveFileName(&SFN) != 0)
	{
		_stprintf_s(str, _T("%s ���Ϸ� �����Ͻðڽ��ϱ�?"), SFN.lpstrFile);
		MessageBox(hwnd, str, _T("�����ϱ� ����"), MB_OK);
	}
}

int wincmd_fontdlg(HWND hwnd, LPCHOOSEFONT FONT, LPLOGFONT LogFont)
{
	memset(FONT, 0, sizeof(CHOOSEFONT));
	FONT->lStructSize = sizeof(CHOOSEFONT);
	FONT->hwndOwner = hwnd;
	FONT->lpLogFont = LogFont;
	FONT->Flags = CF_EFFECTS | CF_SCREENFONTS;
	return ChooseFont(FONT);
}

void OutFromFile(TCHAR filename[], HWND hwnd)
{
	FILE* fPtr;
	HDC hdc;
	int line;
	TCHAR buffer[500];
	line = 0;
	hdc = GetDC(hwnd);

#ifdef _UNICODE
	_tfopen_s(&fPtr, filename, _T("r, ccs = UNICODE"));
#else 
	_tfopen_s(&fPtr, filename, _T("r"));
#endif
	while (_fgetts(buffer, 100, fPtr) != NULL)
	{
		if (buffer[_tcslen(buffer) - 1] == _T('\n'))
			buffer[_tcslen(buffer) - 1] = NULL;
		TextOut(hdc, 0, line * 20, buffer, _tcslen(buffer));
		line++;
	}
	fclose(fPtr);
	ReleaseDC(hwnd, hdc);
}