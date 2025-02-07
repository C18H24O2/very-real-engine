#ifndef MLK_PLATFORM_WINDOW_COMPONENT_HPP__
#define MLK_PLATFORM_WINDOW_COMPONENT_HPP__

#include <Platform/PreCompiled.hpp>
#include <Core/ComponentBase.hpp>
#include <Platform/Enums.hpp>
#include <Maths/Vec2.hpp>

namespace Mlk
{
	class MLK_PLATFORM_API WindowComponent : public ComponentBase
	{
		public:
			WindowComponent(std::size_t width, std::size_t height, WindowStyle style = 0);
			WindowComponent(std::size_t width, std::size_t height, const std::string& title, WindowStyle style = 0);

			void OnAttach() noexcept override;
			MLK_FORCEINLINE void OnFixedUpdate() noexcept override;
			void OnQuit() noexcept override;

			MLK_FORCEINLINE std::size_t GetWidth() const noexcept;
			MLK_FORCEINLINE std::size_t GetHeight() const noexcept;
			MLK_FORCEINLINE void SetPosition(const Vec2i& position) noexcept;
			MLK_FORCEINLINE void SetPosition(std::uint32_t posx, std::uint32_t posy) noexcept;
			MLK_FORCEINLINE void SetSize(const Vec2i& size) noexcept;
			MLK_FORCEINLINE void SetSize(std::uint32_t sizex, std::uint32_t sizey) noexcept;
			MLK_FORCEINLINE void SetMaxSize(const Vec2i& size) noexcept;
			MLK_FORCEINLINE void SetMaxSize(std::uint32_t sizex, std::uint32_t sizey) noexcept;
			MLK_FORCEINLINE void SetMinSize(const Vec2i& size) noexcept;
			MLK_FORCEINLINE void SetMinSize(std::uint32_t sizex, std::uint32_t sizey) noexcept;
			MLK_FORCEINLINE void SetTitle(const std::string& title);
			MLK_FORCEINLINE const std::string& GetTitle() const;
			MLK_FORCEINLINE const Vec2i& GetPosition() const noexcept;
			MLK_FORCEINLINE const Vec2i& GetSize() const noexcept;
			MLK_FORCEINLINE const Vec2i& GetMinSize() const noexcept;
			MLK_FORCEINLINE const Vec2i& GetMaxSize() const noexcept;

			~WindowComponent() = default;
	};
}

#include <Platform/WindowComponent.inl>

#endif
