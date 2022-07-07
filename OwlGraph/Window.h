#pragma once

namespace Owl::Graph
{
	class Window
	{
	public:
		Window();
		~Window() = default;

		Window(const Window& _other) = default;
		Window(Window&& _other) noexcept = default;
		Window& operator=(const Window& _other) = default;
		Window& operator=(Window&& _other) noexcept = default;
	};
}
