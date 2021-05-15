#define LearningChapter "ex5-4"
//page 202

#include <Windows.h>
#include <tchar.h>
#include "resource.h"

LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg, WPARAM wParam, LPARAM lParam);
static LPCTSTR WindowClassName = _T(LearningChapter) _T(" Class");
static LPCTSTR WindowTitleName = _T(LearningChapter);
static const int WindowPosition[2] = { 400, 200 };
static const int WindowSize[2] = { 720, 480 };

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
	WndClass.lpszMenuName = NULL;//MAKEINTRESOURCE(IDR_MENU0_0);
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
	static HINSTANCE hInstance;
	static HBITMAP hBitmap, oldBitmap;
	HDC hdc, memdc;
	PAINTSTRUCT ps;
	RECT rt_hwnd;

	TCHAR word[] = _T("내년이 올까?");
	static int xPos = 0;
	static int yPos = 0;

	switch (iMsg) {
	case WM_CREATE:
		hInstance = ((LPCREATESTRUCT)lParam)->hInstance;
		hBitmap = LoadBitmap(hInstance, MAKEINTRESOURCE(IDB_BITMAP6));
		
		SetTimer(hwnd, 1, 2, NULL);
		return 0;

	case WM_PAINT:
		hdc = BeginPaint(hwnd, &ps);
		memdc = CreateCompatibleDC(hdc);
		oldBitmap = (HBITMAP)SelectObject(memdc, hBitmap);

		GetClientRect(hwnd, &rt_hwnd);
		BitBlt(hdc, 0, 0, rt_hwnd.right, rt_hwnd.bottom, memdc, 0, 0, SRCCOPY);

		TextOut(hdc, xPos, yPos, word, _tcslen(word));

		SelectObject(memdc, oldBitmap);
		DeleteDC(memdc);
		EndPaint(hwnd, &ps);
		return 0;

	case WM_MOUSEMOVE:
		xPos = LOWORD(lParam);
		yPos = HIWORD(lParam);
		return 0;
	case WM_TIMER:
		//GetClientRect(hwnd, &rt_hwnd);
		//if (ypos > rt_hwnd.bottom) ypos = 0;
		InvalidateRgn(hwnd, NULL, FALSE);
		return 0;

	case WM_DESTROY:
		KillTimer(hwnd, 1);
		PostQuitMessage(0);
		return 0;
	}
	return DefWindowProc(hwnd, iMsg, wParam, lParam);
}
