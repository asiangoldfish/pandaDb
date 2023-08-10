#include "core/Application.h"

int main(void)
{
    Application *app = new Application();
    
    if (!app->init())
    {
        return 1;
    }

    app->run();

    delete app;

    return 0;
}
