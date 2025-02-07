#ifndef MLK_CORE_ENGINE_CONFIG_HPP__
#define MLK_CORE_ENGINE_CONFIG_HPP__

#include <Core/PreCompiled.hpp>
#include <Renderer/Enums.hpp>

namespace Mlk
{
	struct EngineConfig
	{
		std::filesystem::path vfs_root_directory;
		RendererDrivers preffered_render_api = RendererDrivers::Auto;
	};
}

#endif
