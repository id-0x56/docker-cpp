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
    this->isExecute(true);
}

Application::~Application()
{
    this->isExecute(false);
}

bool Application::isExecute() const
{
    return this->m_isExecute;
}

void Application::isExecute(bool isExecute)
{
    this->m_isExecute = isExecute;
}

void Application::execute()
{
    while (this->isExecute()) {
        int ch = getch();

        if (ch == 'q') {
            this->isExecute(false);
        } else {
            std::cout << "character: " << ch << std::endl;
        }
    }
}
