#define LearningChapter "ex5-5"
//page 205

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

void TextPrint(HDC hdc, int x, int y, TCHAR text[])
{
	int i, j;
	SetTextColor(hdc, RGB(255, 255, 255));
	for (i = -1; i <= 1; i++)
		for (j = -1; j <= 1; j++)
			TextOut(hdc, x + i, y + j, text, _tcslen(text));
	SetTextColor(hdc, RGB(0, 0, 0));
	TextOut(hdc, x, y, text, _tcslen(text));
}

BOOL IsTextInOfRect(HWND hwnd, HDC hdc, TCHAR text[], int x, int y)
{
	BOOL result = FALSE;
	RECT rt_hwnd;
	SIZE size;
	GetClientRect(hwnd, &rt_hwnd);
	GetTextExtentPoint(hdc, text, _tcslen(text), &size);
	if (rt_hwnd.left < x && x + size.cx < rt_hwnd.right)
		result = TRUE;
	if (rt_hwnd.top < y && y + size.cy < rt_hwnd.bottom)
		result = TRUE;

	return result;
}

LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg, WPARAM wParam, LPARAM lParam)
{
	static HINSTANCE hInstance;
	static HBITMAP hBitmap[2], oldBitmap[2];
	static BITMAP bitmap;
	HDC hdc, memdc[2];
	PAINTSTRUCT ps;
	RECT rt_hwnd;

	TCHAR word[] = _T("내년이 올까?");
	SIZE szWord;

	static int xPos = 0;
	static int yPos = 0;
	static int xSpeed = 0;
	static int ySpeed = 0;
	static int accelVal = 1;
	static int keyFlag[4] = { 0, };

	switch (iMsg) {
	case WM_CREATE:
		hInstance = ((LPCREATESTRUCT)lParam)->hInstance;
		hBitmap[1] = LoadBitmap(hInstance, MAKEINTRESOURCE(IDB_BITMAP12));
		GetObject(hBitmap[1], sizeof(BITMAP), &bitmap);

		SetTimer(hwnd, 1, 30, NULL);
		return 0;

	case WM_PAINT:
		hdc = BeginPaint(hwnd, &ps);
		memdc[0] = CreateCompatibleDC(hdc);
		memdc[1] = CreateCompatibleDC(memdc[0]);
		if (hBitmap[0] == NULL)
			hBitmap[0] = CreateCompatibleBitmap(hdc, bitmap.bmWidth, bitmap.bmHeight);
		GetClientRect(hwnd, &rt_hwnd);

		oldBitmap[0] = (HBITMAP)SelectObject(memdc[0], hBitmap[0]);
		oldBitmap[1] = (HBITMAP)SelectObject(memdc[1], hBitmap[1]);
		BitBlt(memdc[0], 0, 0, rt_hwnd.right, rt_hwnd.bottom, memdc[1], 0, 0, SRCCOPY);
		SetBkMode(memdc[0], TRANSPARENT);
		TextPrint(memdc[0], xPos, yPos, word);
		BitBlt(hdc, 0, 0, rt_hwnd.right, rt_hwnd.bottom, memdc[0], 0, 0, SRCCOPY);

		SelectObject(memdc[0], oldBitmap[0]);
		SelectObject(memdc[1], oldBitmap[1]);
		DeleteDC(memdc[0]);
		DeleteDC(memdc[1]);
		EndPaint(hwnd, &ps);
		return 0;
	/*
	case WM_MOUSEMOVE:
		xPos = LOWORD(lParam);
		yPos = HIWORD(lParam);
		return 0;
		*/
	case WM_KEYDOWN:
		switch (wParam)
		{
		case VK_LEFT:
			keyFlag[0] = 1;
			break;
		case VK_RIGHT:
			keyFlag[1] = 1;
			break;
		case VK_UP:
			keyFlag[2] = 1;
			break;
		case VK_DOWN:
			keyFlag[3] = 1;
			break;
		}
		return 0;
	case WM_KEYUP:
		switch (wParam)
		{
		case VK_LEFT:
			keyFlag[0] = 0;
			break;
		case VK_RIGHT:
			keyFlag[1] = 0;
			break;
		case VK_UP:
			keyFlag[2] = 0;
			break;
		case VK_DOWN:
			keyFlag[3] = 0;
			break;
		}
		return 0;
	case WM_TIMER:
		//if (ypos > rt_hwnd.bottom) ypos = 0;
		if (keyFlag[0])
			xSpeed -= accelVal;
		if (keyFlag[1])
			xSpeed += accelVal;
		if (keyFlag[2])
			ySpeed -= accelVal;
		if (keyFlag[3])
			ySpeed += accelVal;
		xPos += xSpeed;
		yPos += ySpeed;

		hdc = GetDC(hwnd);
		if (!IsTextInOfRect(hwnd, hdc, word, xPos, yPos))
		{
			xPos = yPos = 0;
			xSpeed = ySpeed = 0;
		}
		ReleaseDC(hwnd, hdc);

		InvalidateRgn(hwnd, NULL, FALSE);
		return 0;

	case WM_DESTROY:
		if (hBitmap[0] != NULL) DeleteObject(hBitmap[0]);
		KillTimer(hwnd, 1);
		PostQuitMessage(0);
		return 0;
	}
	return DefWindowProc(hwnd, iMsg, wParam, lParam);
}
