#include "Window.h"


LRESULT CALLBACK Owl::Graph::Window::WindowProcedure(HWND hwnd, UINT Msg, WPARAM wParam, LPARAM lParam)
{
	switch (Msg)
	{
	// case WM_DESTROY:
	// 	PostQuitMessage(WM_QUIT);
	// 	break;
	case WM_PAINT:
		{
			// /* */
			// PAINTSTRUCT ps;
			// HDC hdc;
			// RECT rc;
			// hdc = BeginPaint(hwnd, &ps);
			//
			// GetClientRect(hwnd, &rc);
			// SetTextColor(hdc, 0);
			// SetBkMode(hdc, TRANSPARENT);
			// DrawText(hdc, L"HELLO WORLD", -1, &rc, DT_CENTER | DT_SINGLELINE | DT_VCENTER);
			//
			// EndPaint(hwnd, &ps);
			// /* */
			// break;
		}
		break;
	default:
		return DefWindowProc(hwnd, Msg, wParam, lParam);
	}
	return 0;
}

Owl::Graph::Window::Window(bool _isShow)
{
	LRESULT CALLBACK WndProc(HWND hwnd, UINT Msg, WPARAM wParam, LPARAM lParam);
	
	WNDCLASSEX WndClsEx = {};
	WndClsEx.cbSize = sizeof(WNDCLASSEX);
	WndClsEx.lpfnWndProc = WndProc;
	WndClsEx.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	WndClsEx.lpszClassName = L"ClassName";
	RegisterClassEx(&WndClsEx);

	
	m_windowHandle = CreateWindowEx(WS_EX_LEFT,
		L"ClassName",
		L"Window Title",
		// (WS_OVERLAPPED | WS_CAPTION | WS_SYSMENU | WS_MINIMIZEBOX),
		(WS_THICKFRAME | WS_MAXIMIZEBOX),
		0,
		0,
		0,
		0,
		NULL,
		NULL,
		NULL,
		NULL);
	
	SetVisible(_isShow);
}

void Owl::Graph::Window::SetVisible(bool _visible)
{
	ShowWindow(m_windowHandle, _visible ? SW_SHOW : SW_HIDE);
	UpdateWindow(m_windowHandle);
}
