#ifndef SQUID_PLATFORM_WINDOW_COMPONENT_HPP__
#define SQUID_PLATFORM_WINDOW_COMPONENT_HPP__

#include <Platform/PreCompiled.hpp>

#include <Core/Memory/UniquePtr.hpp>
#include <Core/ComponentBase.hpp>
#include <Platform/Enums.hpp>
#include <Platform/Window.hpp>

namespace Squid
{
	class SQUID_PLATFORM_API WindowComponent : public ComponentBase
	{
		public:
			WindowComponent(std::size_t width, std::size_t height, WindowStyle style = 0);
			WindowComponent(std::size_t width, std::size_t height, const std::string& title, WindowStyle style = 0);

			void OnAttach() noexcept override;
			SQUID_FORCEINLINE void OnFixedUpdate() noexcept override;
			void OnQuit() noexcept override;

			SQUID_FORCEINLINE void SetPosition(const Vec2i& position) noexcept;
			SQUID_FORCEINLINE void SetPosition(std::uint32_t posx, std::uint32_t posy) noexcept;
			SQUID_FORCEINLINE void SetSize(const Vec2i& size) noexcept;
			SQUID_FORCEINLINE void SetSize(std::uint32_t sizex, std::uint32_t sizey) noexcept;
			SQUID_FORCEINLINE void SetMaxSize(const Vec2i& size) noexcept;
			SQUID_FORCEINLINE void SetMaxSize(std::uint32_t sizex, std::uint32_t sizey) noexcept;
			SQUID_FORCEINLINE void SetMinSize(const Vec2i& size) noexcept;
			SQUID_FORCEINLINE void SetMinSize(std::uint32_t sizex, std::uint32_t sizey) noexcept;
			SQUID_FORCEINLINE void SetTitle(const std::string& title);
			SQUID_FORCEINLINE const std::string& GetTitle() const;
			SQUID_FORCEINLINE const Vec2i& GetPosition() const noexcept;
			SQUID_FORCEINLINE const Vec2i& GetSize() const noexcept;
			SQUID_FORCEINLINE const Vec2i& GetMinSize() const noexcept;
			SQUID_FORCEINLINE const Vec2i& GetMaxSize() const noexcept;

			~WindowComponent() = default;

		private:
			UniquePtr<Window> m_window;
	};
}

#include <Platform/WindowComponent.inl>

#endif
