#include <Earl/application.hpp>
#include <iostream>

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
        std::printf("Earl is running!\n");
    }
}
