#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow( int argc, char* argv[], QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , args( { argc, argv } )
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

