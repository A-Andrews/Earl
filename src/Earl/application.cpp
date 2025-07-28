#include <Earl/application.hpp>
#include <iostream>
#include <Earl/log.hpp>

namespace Earl
{
    Application::Application()
    {
    }
    Application::~Application()
    {
    }
    void Application::run()
    {
        EARL_CORE_INFO("Application is running!");
    }
}
