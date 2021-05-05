#include <QApplication>

#include <iostream>

#include "kdbx.hh"
#include "key.hh"

#include "mainwindow.h"

using namespace keepass;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv );
    MainWindow w( argc, argv, a.clipboard( ) );
    w.show();
    return a.exec();
}
