#pragma once
#include <windows.h>

namespace Owl::Graph
{
	class Window
	{
	private:
		HWND m_windowHandle;

		LRESULT CALLBACK WindowProcedure(HWND hwnd, UINT Msg, WPARAM wParam, LPARAM lParam);
	public:
		Window(bool _isShow = true);
		~Window() = default;

		Window(const Window& _other) = default;
		Window(Window&& _other) noexcept = default;
		Window& operator=(const Window& _other) = default;
		Window& operator=(Window&& _other) noexcept = default;

		void SetVisible(bool _visible = true);
		bool IsVisible() const { return IsWindowVisible(m_windowHandle); } 

		//test
		void tupdate()
		{
			MSG Msg;
			while (GetMessage(&Msg, m_windowHandle, 0, 0))
			{
				TranslateMessage(&Msg);
				DispatchMessage(&Msg);
			}

		}
	};
}
