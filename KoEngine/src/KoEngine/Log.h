#pragma once

#include "Core.h"
#include "spdlog/spdlog.h"

namespace KoEngine
{
    class KOENGINE_API Log
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

// Core logs
#define KE_CORE_LOG_ERROR(...)      ::KoEngine::Log::GetCoreLogger()->error(__VA_ARGS__)
#define KE_CORE_LOG_WARN(...)       ::KoEngine::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define KE_CORE_LOG_INFO(...)       ::KoEngine::Log::GetCoreLogger()->info(__VA_ARGS__)

// Client logs
#define KE_LOG_ERROR(...)           ::KoEngine::Log::GetClientLogger()->error(__VA_ARGS__)
#define KE_LOG_WARN(...)            ::KoEngine::Log::GetClientLogger()->warn(__VA_ARGS__)
#define KE_LOG_INFO(...)            ::KoEngine::Log::GetClientLogger()->info(__VA_ARGS__)