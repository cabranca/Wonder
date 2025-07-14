#pragma once

#include <memory>
#include "Core.h"
#include "spdlog/spdlog.h"

namespace Wonder {
	// Wrapper for logging messages
	class WONDER_API Log {
	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger> GetCoreLogger() {
			return m_CoreLogger;
		}
		inline static std::shared_ptr<spdlog::logger> GetClientLogger() {
			return m_ClientLogger;
		}

	private:
		static std::shared_ptr<spdlog::logger> m_CoreLogger;
		static std::shared_ptr<spdlog::logger> m_ClientLogger;
	};
}

// Core log macros
#define WD_CORE_TRACE(...)    ::Wonder::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define WD_CORE_INFO(...)     ::Wonder::Log::GetCoreLogger()->info(__VA_ARGS__)
#define WD_CORE_WARN(...)     ::Wonder::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define WD_CORE_ERROR(...)    ::Wonder::Log::GetCoreLogger()->error(__VA_ARGS__)
#define WD_CORE_FATAL(...)    ::Wonder::Log::GetCoreLogger()->fatal(__VA_ARGS__)

// Client log macros
#define WD_TRACE(...)  ::Wonder::Log::GetClientLogger()->trace(__VA_ARGS__)
#define WD_INFO(...)   ::Wonder::Log::GetClientLogger()->info(__VA_ARGS__)
#define WD_WARN(...)   ::Wonder::Log::GetClientLogger()->warn(__VA_ARGS__)
#define WD_ERROR(...)  ::Wonder::Log::GetClientLogger()->error(__VA_ARGS__)
#define WD_FATAL(...)  ::Wonder::Log::GetClientLogger()->fatal(__VA_ARGS__)
