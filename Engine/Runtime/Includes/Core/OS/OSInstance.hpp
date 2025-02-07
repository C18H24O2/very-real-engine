#ifndef MLK_CORE_OS_INSTANCE_HPP__
#define MLK_CORE_OS_INSTANCE_HPP__

#include <Core/OS/LibLoader.hpp>
#include <Core/PreCompiled.hpp>
#include <Maths/Vec4.hpp>

namespace Mlk
{
	class OSInstance
	{
		public:
			virtual void Init() {}
			virtual void Shutdown() = 0;

			virtual std::filesystem::path GetExecutablePath() = 0;
			virtual std::filesystem::path GetCurrentWorkingDirectoryPath() = 0;
			virtual bool OpenURL([[maybe_unused]] const std::string& url) { return false; }
			virtual void Delay([[maybe_unused]] std::uint32_t us) {}

			inline static OSInstance& Get() noexcept { return *s_instance; }
			inline static LibLoader& GetLibLoader() noexcept { return *s_lib_loader; }

		protected:
			OSInstance() = default;
			inline void SetInstance(OSInstance* instance) { s_instance = instance; }
			inline void SetLibLoader(LibLoader* instance) { s_lib_loader = instance; }
			virtual ~OSInstance() = default;

		private:
			inline static OSInstance* s_instance = nullptr;
			inline static LibLoader* s_lib_loader = nullptr;
	};
}

#endif
