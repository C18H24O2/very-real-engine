#ifndef SQUID_CORE_FILE_HPP__
#define SQUID_CORE_FILE_HPP__

#include <Core/PreCompiled.hpp>
#include <Core/Enums.hpp>

namespace Squid
{
	class SQUID_CORE_API File
	{
		public:
			File(const std::filesystem::path& filepaht);
			File(const std::filesystem::path& filepath, std::uint32_t flags);

			bool Open(std::uint32_t flags);
			void Close();

			template <typename T>
			inline void operator<<(T&& t) { m_stream << std::forward<T>(t); }

			inline bool IsOpen() const { return m_stream.is_open(); }
			inline bool Exists() const { return std::filesystem::exists(m_filepath); }

			inline std::size_t GetSize() const { return  std::filesystem::file_size(m_filepath); }
			inline std::filesystem::path GetPath() const { return m_filepath; }
			inline std::filesystem::path GetDirectory() const { return m_filepath.parent_path(); }

			~File() = default;

		private:
			std::fstream m_stream;
			std::filesystem::path m_filepath;
	};
}

#endif
