#ifndef SQUID_DRIVERS_UNIX_INSTANCE_HPP__
#define SQUID_DRIVERS_UNIX_INSTANCE_HPP__

#include <Core/Unix/PreCompiled.hpp>
#include <Core/OS/OSInstance.hpp>

namespace Squid
{
	class SQUID_UNIX_API UnixInstance final : public OSInstance
	{
		public:
			UnixInstance() = default;

			void Init(int ac, char** av);
			void Shutdown() override;

			[[nodiscard]]
			std::filesystem::path GetExecutablePath() override;
			[[nodiscard]]
			std::filesystem::path GetCurrentWorkingDirectoryPath() override;
			bool OpenURL([[maybe_unused]] const std::string& url) override;
			void Delay(std::uint32_t us) override;

			~UnixInstance() override = default;

		private:
			char** m_av = nullptr;
			int m_ac;
	};
}

#endif
