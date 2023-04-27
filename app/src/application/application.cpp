#include "application.h"

#ifdef __linux__
    int getch()
    {
        struct termios oldattr, newattr;

        tcgetattr(STDIN_FILENO, &oldattr);

        newattr = oldattr;
        newattr.c_lflag &= ~(ICANON | ECHO);
        tcsetattr(STDIN_FILENO, TCSANOW, &newattr);
        int ch = getchar();

        tcsetattr(STDIN_FILENO, TCSANOW, &oldattr);

        return ch;
    }
#endif

Application::Application()
{
    this->is_running = true;
}

Application::~Application()
{
    this->is_running = false;
}

void Application::run()
{
    while (this->is_running) {
        int ch = getch();

        if (ch == 'q') {
            this->is_running = false;
        } else {
            std::cout << "character: " << ch << std::endl;
        }
    }
}
