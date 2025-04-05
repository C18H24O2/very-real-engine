#include <Core/VirtualFileSystem.hpp>

namespace Squid
{
	VirtualFileSystem::VirtualFileSystem() : m_root({}, "/")
	{
		DebugLog("Virtual Filesystem is up");
	}

	bool VirtualFileSystem::CreateVirtualDirectory(std::string_view path, std::string_view directory_name)
	{
	}

	bool VirtualFileSystem::MountVirtualDirectory(const std::filesystem::path& real_directory, const VirtualPath& virtual_directory)
	{
	}
}
