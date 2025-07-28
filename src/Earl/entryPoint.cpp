#include <Earl/entryPoint.hpp>

int main(int argc, char **argv)
{
    auto app = Earl::CreateApplication();
    app->run();
    return 0;
}
