#ifndef FORM_H
#define FORM_H

#include <cstdint>

class MainWindow;

class Form
{
public:
    Form( MainWindow *main );

    uint32_t m_icon;
    MainWindow *main_window;
};

#endif // FORM_H
