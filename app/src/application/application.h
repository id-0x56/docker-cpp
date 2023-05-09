#ifndef APPLICATION_H
    #define APPLICATION_H

    #include <iostream>

    #ifdef __linux__
        #include <unistd.h>
        #include <termios.h>
    #else
        #include <conio.h>
    #endif

    class Application
    {
        public:
            Application();

            ~Application();

            bool isExecute() const;
            void isExecute(bool isExecute);

            void execute();

        private:
            bool m_isExecute;
    };
#endif
