#ifndef SQUID_PLATFORM_WINDOW_HPP__ 
#define SQUID_PLATFORM_WINDOW_HPP__

#include <Core/PreCompiled.hpp>

#include <Maths/Vec2.hpp>

namespace Squid
{
	class SQUID_PLATFORM_API Window
	{
		public:
			Window() = default;
			~Window() = default;
		
			bool IsSupported() const noexcept;

			void SetPosition(const Vec2i& position) noexcept;
			void SetPosition(std::uint32_t posx, std::uint32_t posy) noexcept;
			void SetSize(const Vec2i& size) noexcept;
			void SetSize(std::uint32_t sizex, std::uint32_t sizey) noexcept;
			void SetMaxSize(const Vec2i& size) noexcept;
			void SetMaxSize(std::uint32_t sizex, std::uint32_t sizey) noexcept;
			void SetMinSize(const Vec2i& size) noexcept;
			void SetMinSize(std::uint32_t sizex, std::uint32_t sizey) noexcept;
			void SetTitle(const std::string& title);
			const std::string& GetTitle() const;
			const Vec2i& GetPosition() const noexcept;
			const Vec2i& GetSize() const noexcept;
			const Vec2i& GetMinSize() const noexcept;
			const Vec2i& GetMaxSize() const noexcept;

		private:
			Window(const Window&) = delete;
			Window& operator=(const Window&) = delete;
	};
}

#endif
