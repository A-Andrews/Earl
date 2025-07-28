#pragma once
#include <memory>
#include <Earl/application.hpp>

namespace Earl
{
    std::unique_ptr<Application> CreateApplication();
}
