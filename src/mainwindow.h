#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTreeWidget>
#include <QTreeWidgetItem>

#include <iostream>

#include <kdbx.hh>
#include <kdb.hh>
#include <key.hh>

#include "ArgsParser.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

using namespace keepass;
using namespace std;

enum FileType
{
    NoFile = 0,
    Kdbx,
    Kdb,
    ErrorType
};

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow( int argc, char* argv[], QWidget *parent = nullptr);
    ~MainWindow( );

    void fillTreeViev( );

private slots:
    void on_treeWidget_itemClicked(QTreeWidgetItem *item, int column);

private:
    Ui::MainWindow *ui;
    std::unique_ptr< Database > dt;

    ArgsParser args;
    FileType type;
};
#endif // MAINWINDOW_H
