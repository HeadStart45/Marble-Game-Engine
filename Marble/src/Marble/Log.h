#pragma once
#include "mbpch.h"

#include "Core.h"
#include <spdlog/spdlog.h>
#include <spdlog/fmt/ostr.h>




/// <summary>
/// Static logging interface.
/// Abstracts spd logging library for simpler logging in engine
/// </summary>
namespace Marble
{
	class MARBLE_API Log
	{
	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }
	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;


	};

	
}

///CORE MACRO LOG FUNCTIONS///
#define MB_CORE_ERROR(...) ::Marble::Log::GetCoreLogger()->error(__VA_ARGS__)
#define MB_CORE_WARN(...) ::Marble::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define MB_CORE_LOG(...) ::Marble::Log::GetCoreLogger()->info(__VA_ARGS__)
#define MB_CORE_TRACE(...) ::Marble::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define MB_CORE_FATAL(...) ::Marble::Log::GetCoreLogger()->fatal(__VA_ARGS__)

//CLIENT MACRO LOG FUNCTIONS//
#define MB_ERROR(...) ::Marble::Log::GetClientLogger()->error(__VA_ARGS__)
#define MB_WARN(...) ::Marble::Log::GetClientLogger()->warn(__VA_ARGS__)
#define MB_LOG(...) ::Marble::Log::GetClientLogger()->info(__VA_ARGS__)
#define MB_TRACE(...) ::Marble::Log::GetClientLogger()->trace(__VA_ARGS__)
#define MB_FATAL(...) ::Marble::Log::GetClientLogger()->fatal(__VA_ARGS__)

