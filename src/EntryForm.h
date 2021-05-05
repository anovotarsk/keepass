#ifndef ENTRYFORM_H
#define ENTRYFORM_H

#include <QDialog>
#include <QMainWindow>
#include <QTableWidget>
#include <QTableWidgetItem>

#include <memory>
#include <algorithm>

#include <entry.hh>

#include <Form.h>

class MainWindow;
class IconChooser;

using namespace keepass;

namespace Ui {
    class EntryForm;
}

class EntryForm : public QDialog, private Form
{
    Q_OBJECT

public:
    explicit EntryForm(  MainWindow *main,
                         QWidget *parent = nullptr );
    ~EntryForm();

    void setEntry( std::shared_ptr<Entry> entry );
    std::shared_ptr<Entry> getEntry( );

    int exec( ) override;

private slots:
    void on_del_clicked();
    void on_save_clicked();
    void on_icon_clicked( );

private:
    Ui::EntryForm *ui;
    IconChooser *icon_chooser;

    std::shared_ptr<Entry> m_entry;

    friend class IconChooser;
    friend class IconContainer;
};

#endif // ENTRYFORM_H
