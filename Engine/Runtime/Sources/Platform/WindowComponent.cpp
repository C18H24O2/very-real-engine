#include <Platform/WindowComponent.hpp>
#include <Core/Memory/MemoryManager.hpp>

namespace Mlk
{
	WindowComponent::WindowComponent(std::size_t width, std::size_t height, WindowStyle style) : ComponentBase("__WindowComponent")
	{
	}

	WindowComponent::WindowComponent(std::size_t width, std::size_t height, const std::string& title, WindowStyle style) : ComponentBase("__WindowComponent")
	{
	}

	void WindowComponent::OnAttach() noexcept
	{
	}

	void WindowComponent::OnQuit() noexcept
	{
	}
}
