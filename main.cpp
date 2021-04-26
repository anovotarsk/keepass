#include "mainwindow.h"
#include <QApplication>

#include "kdbx.hh"
#include "key.hh"
#include "ArgsParser.h"
#include <iostream>

using namespace keepass;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv );
    MainWindow w( argc, argv, a.clipboard( ) );
    w.show();
    return a.exec();
}
