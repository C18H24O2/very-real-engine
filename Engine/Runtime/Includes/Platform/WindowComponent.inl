#pragma once
#include <Platform/WindowComponent.hpp>

namespace Squid
{
	void WindowComponent::OnFixedUpdate() noexcept
	{
	}

	void WindowComponent::SetPosition(const Vec2i& position) noexcept
	{
		m_window->SetPosition(position);
	}
	
	void WindowComponent::SetPosition(std::uint32_t posx, std::uint32_t posy) noexcept
	{
		m_window->SetPosition(posx, posy);
	}
	
	void WindowComponent::SetSize(const Vec2i& size) noexcept
	{
		m_window->SetSize(size);
	}
	
	void WindowComponent::SetSize(std::uint32_t sizex, std::uint32_t sizey) noexcept
	{
		m_window->SetSize(sizex, sizey);
	}
	
	void WindowComponent::SetMaxSize(const Vec2i& size) noexcept
	{
		m_window->SetMaxSize(size);
	}
	
	void WindowComponent::SetMaxSize(std::uint32_t sizex, std::uint32_t sizey) noexcept
	{
		m_window->SetMaxSize(sizex, sizey);
	}
	
	void WindowComponent::SetMinSize(const Vec2i& size) noexcept
	{
		m_window->SetMinSize(size);
	}
	
	void WindowComponent::SetMinSize(std::uint32_t sizex, std::uint32_t sizey) noexcept
	{
		m_window->SetMinSize(sizex, sizey);
	}
	
	void WindowComponent::SetTitle(const std::string& title)
	{
		m_window->SetTitle(title);
	}
	
	const std::string& WindowComponent::GetTitle() const
	{
		return m_window->GetTitle();
	}
	
	const Vec2i& WindowComponent::GetPosition() const noexcept
	{
		return m_window->GetPosition();
	}
	
	const Vec2i& WindowComponent::GetSize() const noexcept
	{
		return m_window->GetSize();
	}
	
	const Vec2i& WindowComponent::GetMinSize() const noexcept
	{
		return m_window->GetMinSize();
	}

	const Vec2i& WindowComponent::GetMaxSize() const noexcept
	{
		return m_window->GetMaxSize();
	}
}
