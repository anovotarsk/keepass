#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTreeWidget>
#include <QTreeWidgetItem>
#include <QIcon>
#include <QClipboard>
#include <QMessageBox>
#include <QFileDialog>
#include <QInputDialog>

#include <iostream>
#include <exception>
#include <memory>

#include <kdbx.hh>
#include <kdb.hh>
#include <key.hh>

#include "ArgsParser.h"
#include "UTreeWidgetItem.h"
#include "EntryForm.h"
#include "GroupForm.h"

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

typedef struct EntryInfo
{
    std::string title;
    std::string user_name;
    std::string password;
    std::string url;
    std::string notes;
    int icon;

} EntryInfo;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow( int argc, char* argv[], QClipboard *clipboard, QWidget *parent = nullptr);
    ~MainWindow( );

    void fillTreeViev( UTreeWidgetItem *parent = nullptr,
                       const std::vector<std::shared_ptr<Group>>* groups = nullptr );

private slots:
    void on_actionOpen_File_triggered();
    void on_actionNew_File_triggered();
    void on_actionAdd_Group_triggered();
    void on_actionAdd_Entry_triggered();

private slots:
    void on_treeWidget_itemDoubleClicked(QTreeWidgetItem *item, int column);
    void on_passList_itemDoubleClicked(QTreeWidgetItem *item, int column);
    void on_treeWidget_itemClicked( QTreeWidgetItem *item, int column );

private:


private:
    Ui::MainWindow *ui;
    std::unique_ptr< Database > dt;

    ArgsParser args;
    FileType type;

    std::array<uint8_t, 16> current_uuid;

    QClipboard *m_clipboard;

    EntryForm *m_entry_form;
    GroupForm *m_group_form;

    friend class Form;
    friend class EntryForm;
    friend class GroupForm;
    friend class IconChooser;
};
#endif // MAINWINDOW_H
