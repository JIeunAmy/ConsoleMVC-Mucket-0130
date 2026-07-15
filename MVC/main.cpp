#include <windows.h>

#include "Controller/MainController.h"

int main()
{
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    Controller::MainController controller;
    controller.Run();

    return 0;
}
