#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTreeWidget>
#include <QTreeWidgetItem>
#include <QIcon>

#include <iostream>

#include <kdbx.hh>
#include <kdb.hh>
#include <key.hh>

#include "ArgsParser.h"
#include "UTreeWidgetItem.h"

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

    void fillTreeViev( UTreeWidgetItem *parent = nullptr,
                       const std::vector<std::shared_ptr<Group>>* groups = nullptr );

private slots:
    void on_treeWidget_itemClicked( QTreeWidgetItem *item, int column );

private:
    const std::vector<std::shared_ptr<Entry>> get_entries_by_uuid( std::array<uint8_t, 16>& uuid );
    const std::vector<std::shared_ptr<Entry>> get_entries_by_uuid(
            std::array<uint8_t, 16>& uuid,
            const std::vector<std::shared_ptr<Group>>& Groups
            );

private:
    Ui::MainWindow *ui;
    std::unique_ptr< Database > dt;

    ArgsParser args;
    FileType type;

    std::array<uint8_t, 16> current_uuid;
};
#endif // MAINWINDOW_H
