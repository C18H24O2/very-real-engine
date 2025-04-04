#ifndef SQUID_CORE_ENGINE_CONFIG_HPP__
#define SQUID_CORE_ENGINE_CONFIG_HPP__

#include <Core/PreCompiled.hpp>
#include <Renderer/Enums.hpp>

namespace Squid
{
	struct EngineConfig
	{
		std::filesystem::path vfs_root_directory;
		RendererDrivers preffered_render_api = RendererDrivers::Auto;
	};
}

#endif
