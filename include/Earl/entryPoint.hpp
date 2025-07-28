#pragma once
#include <memory>
#include <Earl/application.hpp>
#include <Earl/log.hpp>

namespace Earl
{
    std::unique_ptr<Application> CreateApplication();
}
