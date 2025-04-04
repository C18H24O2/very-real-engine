#pragma once
#include <Platform/WindowComponent.hpp>

namespace Squid
{
	void WindowComponent::OnFixedUpdate() noexcept
	{
	}

	std::size_t WindowComponent::GetWidth() const noexcept
	{
		return 0;
	}
	
	std::size_t WindowComponent::GetHeight() const noexcept
	{
		return 0;
	}
	
	void WindowComponent::SetPosition(const Vec2i& position) noexcept
	{
	}
	
	void WindowComponent::SetPosition(std::uint32_t posx, std::uint32_t posy) noexcept
	{
	}
	
	void WindowComponent::SetSize(const Vec2i& size) noexcept
	{
	}
	
	void WindowComponent::SetSize(std::uint32_t sizex, std::uint32_t sizey) noexcept
	{
	}
	
	void WindowComponent::SetMaxSize(const Vec2i& size) noexcept
	{
	}
	
	void WindowComponent::SetMaxSize(std::uint32_t sizex, std::uint32_t sizey) noexcept
	{
	}
	
	void WindowComponent::SetMinSize(const Vec2i& size) noexcept
	{
	}
	
	void WindowComponent::SetMinSize(std::uint32_t sizex, std::uint32_t sizey) noexcept
	{
	}
	
	void WindowComponent::SetTitle(const std::string& title)
	{
	}
	
	const std::string& WindowComponent::GetTitle() const
	{
		return {};
	}
	
	const Vec2i& WindowComponent::GetPosition() const noexcept
	{
		return {};
	}
	
	const Vec2i& WindowComponent::GetSize() const noexcept
	{
		return {};
	}
	
	const Vec2i& WindowComponent::GetMinSize() const noexcept
	{
		return {};
	}

	const Vec2i& WindowComponent::GetMaxSize() const noexcept
	{
		return {};
	}
}
