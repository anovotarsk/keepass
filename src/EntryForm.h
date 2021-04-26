#ifndef ENTRYFORM_H
#define ENTRYFORM_H

#include <QDialog>
#include <QMainWindow>

#include <memory>

#include <entry.hh>

class MainWindow;

using namespace keepass;

namespace Ui {
    class EntryForm;
}

class EntryForm : public QDialog
{
    Q_OBJECT

public:
    explicit EntryForm(  MainWindow *main,
                         QWidget *parent = nullptr );
    ~EntryForm();

    void setEntry( std::shared_ptr<Entry> entry );
    std::shared_ptr<Entry> getEntry( );

    int exec( ) override;

private:
    Ui::EntryForm *ui;
    MainWindow *main_window;

    std::shared_ptr<Entry> m_entry;
};

#endif // ENTRYFORM_H
