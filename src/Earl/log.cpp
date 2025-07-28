#include <Earl/log.hpp>
#include <spdlog/sinks/stdout_color_sinks.h>
#include <spdlog/sinks/basic_file_sink.h>
#include <filesystem>

namespace Earl
{
    std::shared_ptr<spdlog::logger> Log::s_CoreLogger;
    std::shared_ptr<spdlog::logger> Log::s_ClientLogger;

    void Log::Init()
    {
        if (!std::filesystem::exists("logs"))
        {
            std::filesystem::create_directory("logs");
        }
        spdlog::set_pattern("%^[%T] %n: %v%$");
        s_CoreLogger = spdlog::stdout_color_mt("EARL");
        s_CoreLogger->set_level(spdlog::level::trace);

        s_ClientLogger = spdlog::stdout_color_mt("APP");
        s_ClientLogger->set_level(spdlog::level::trace);

        // Create file sink (logs will go to 'logs/engine.log')
        auto fileSink = std::make_shared<spdlog::sinks::basic_file_sink_mt>("logs/engine.log", true);
        fileSink->set_level(spdlog::level::trace);
    }
}
