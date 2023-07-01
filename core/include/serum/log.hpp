#pragma once

#include "spdlog/logger.h"

namespace Serum {
class Log {
public:
    static void init();

    static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return coreLogger; }
    static std::shared_ptr<spdlog::logger>& GetClientLogger() { return clientLogger; }

private:
    static std::shared_ptr<spdlog::logger> coreLogger;
    static std::shared_ptr<spdlog::logger> clientLogger;
};
}

#define SERUM_CORE_TRACE(...) ::Serum::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define SERUM_CORE_INFO(...) ::Serum::Log::GetCoreLogger()->info(__VA_ARGS__)
#define SERUM_CORE_WARN(...) ::Serum::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define SERUM_CORE_ERROR(...) ::Serum::Log::GetCoreLogger()->error(__VA_ARGS__)
#define SERUM_CORE_CRITICAL(...) ::Serum::Log::GetCoreLogger()->critical(__VA_ARGS__)

#define SERUM_TRACE(...) ::Serum::Log::GetClientLogger()->trace(__VA_ARGS__)
#define SERUM_INFO(...) ::Serum::Log::GetClientLogger()->info(__VA_ARGS__)
#define SERUM_WARN(...) ::Serum::Log::GetClientLogger()->warn(__VA_ARGS__)
#define SERUM_ERROR(...) ::Serum::Log::GetClientLogger()->error(__VA_ARGS__)
#define SERUM_CRITICAL(...) ::Serum::Log::GetClientLogger()->critical(__VA_ARGS__)