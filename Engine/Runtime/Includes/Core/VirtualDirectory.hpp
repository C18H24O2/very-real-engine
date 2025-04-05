#ifndef SQUID_CORE_VIRTUAL_DIRECTORY_HPP__
#define SQUID_CORE_VIRTUAL_DIRECTORY_HPP__

#include <Core/PreCompiled.hpp>
#include <Utils/NonCopyable.hpp>
#include <Core/VirtualPath.hpp>
#include <Core/File.hpp>

namespace Squid
{
	struct FileEntry
	{
		SharedPtr<File> file;
	};

	struct DirectoryEntry
	{
		SharedPtr<class VirtualDirectory> virtual_directory;
	};

	struct Entry
	{
		std::string name;
		std::variant<FileEntry, DirectoryEntry> entry;

		Entry(const std::string& n, std::variant<FileEntry, DirectoryEntry> e) : name(n), entry(e) {}
	};

	class SQUID_CORE_API VirtualDirectory : public NonCopyable, EnableSharedFromThis<VirtualDirectory>
	{
		public:
			VirtualDirectory(const WeakPtr<VirtualDirectory>& parent, const std::string& name);

			void MountRealDirectory(const std::filesystem::path& path);

			template <typename F>
			inline void ForEachEntries(F&& f);

			FileEntry GetFileEntry(std::string_view path);
			DirectoryEntry GetDirectoryEntry(std::string_view path);

			~VirtualDirectory();

		private:
			void ReleaseFromParent() noexcept;

		private:
			std::string m_name;
			std::vector<std::filesystem::path> m_mounted_directories;
			std::vector<Entry> m_entries;
			WeakPtr<VirtualDirectory> m_parent;
	};
}

#include <Core/VirtualDirectory.inl>

#endif
