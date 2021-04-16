#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "ArgsParser.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow( int argc, char* argv[], QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    ArgsParser args;
};
#endif // MAINWINDOW_H
