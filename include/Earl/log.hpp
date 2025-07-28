#pragma once
#include <memory>
#include <spdlog/spdlog.h>

#ifdef EARL_DEBUG

// Engine logging macros
#define EARL_CORE_TRACE(...) ::Earl::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define EARL_CORE_INFO(...) ::Earl::Log::GetCoreLogger()->info(__VA_ARGS__)
#define EARL_CORE_WARN(...) ::Earl::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define EARL_CORE_ERROR(...) ::Earl::Log::GetCoreLogger()->error(__VA_ARGS__)
#define EARL_CORE_CRITICAL(...) ::Earl::Log::GetCoreLogger()->critical(__VA_ARGS__)

// Application logging macros
#define APP_TRACE(...) ::Earl::Log::GetClientLogger()->trace(__VA_ARGS__)
#define APP_INFO(...) ::Earl::Log::GetClientLogger()->info(__VA_ARGS__)
#define APP_WARN(...) ::Earl::Log::GetClientLogger()->warn(__VA_ARGS__)
#define APP_ERROR(...) ::Earl::Log::GetClientLogger()->error(__VA_ARGS__)
#define APP_CRITICAL(...) ::Earl::Log::GetClientLogger()->critical(__VA_ARGS__)

#else

#define EARL_CORE_TRACE(...)
#define EARL_CORE_INFO(...)
#define EARL_CORE_WARN(...)
#define EARL_CORE_ERROR(...)
#define EARL_CORE_CRITICAL(...)

#define APP_TRACE(...)
#define APP_INFO(...)
#define APP_WARN(...)
#define APP_ERROR(...)
#define APP_CRITICAL(...)

#endif

namespace Earl
{
    class Log
    {
    public:
        static void Init();
        inline static const std::shared_ptr<spdlog::logger> &GetCoreLogger() { return s_CoreLogger; }
        inline static const std::shared_ptr<spdlog::logger> &GetClientLogger() { return s_ClientLogger; }

    private:
        static std::shared_ptr<spdlog::logger> s_CoreLogger;
        static std::shared_ptr<spdlog::logger> s_ClientLogger;
    };
}
