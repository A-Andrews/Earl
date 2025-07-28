#include <Earl/entryPoint.hpp>

int main(int argc, char **argv)
{
    Earl::Log::Init();
    auto app = Earl::CreateApplication();
    app->run();
    return 0;
}
