#include <quill/Backend.h>
#include <quill/Frontend.h>
#include <quill/LogMacros.h>
#include <quill/Logger.h>
#include <quill/sinks/ConsoleSink.h>

#include <cstdio>
#include <cstdlib>
#include <exception>
#include <string>
#include <utility>

#include "tf/core/version.hpp"

int main() {
    try {
        quill::Backend::start();
        auto sink = quill::Frontend::create_or_get_sink<quill::ConsoleSink>("console");
        quill::Logger* logger = quill::Frontend::create_or_get_logger("tf", std::move(sink));
        LOG_INFO(logger, "tickforge {} starting", std::string{tf::version()});
        return EXIT_SUCCESS;
    } catch (const std::exception& e) {
        static_cast<void>(std::fputs(e.what(), stderr));
        return EXIT_FAILURE;
    }
}
