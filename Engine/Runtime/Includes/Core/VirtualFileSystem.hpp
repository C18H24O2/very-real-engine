#ifndef SQUID_CORE_VIRTUAL_FILE_SYSTEM_HPP__
#define SQUID_CORE_VIRTUAL_FILE_SYSTEM_HPP__

#include <Core/PreCompiled.hpp>
#include <Core/File.hpp>
#include <Core/VirtualPath.hpp>
#include <Core/VirtualDirectory.hpp>

namespace Squid
{
	class SQUID_CORE_API VirtualFileSystem
	{
		friend class CoreModule;

		public:
			bool CreateVirtualDirectory(std::string_view path, std::string_view directory_name);
			bool MountVirtualDirectory(const std::filesystem::path& real_directory, const VirtualPath& virtual_directory);

		private:
			VirtualFileSystem();
			~VirtualFileSystem() = default;

		private:
			VirtualDirectory m_root;
	};
}

#endif
