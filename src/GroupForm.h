#ifndef GROUPFORM_H
#define GROUPFORM_H

#include <QDialog>

#include <group.hh>

#include "Form.h"

using namespace keepass;

class IconChooser;
class IconContainer;

namespace Ui {
class GroupForm;
}

class GroupForm : public QDialog, private Form
{
    Q_OBJECT

public:
    explicit GroupForm( MainWindow *main,
                        QWidget *parent = nullptr);
    ~GroupForm();

    void setGroup( std::shared_ptr<Group> group );
    std::shared_ptr<Group> getGroup( );

    int exec() override;

private slots:
    void on_del_clicked();
    void on_save_clicked();
    void on_icon_clicked();

private:
    Ui::GroupForm *ui;
    IconChooser *icon_chooser;
    std::shared_ptr<Group> m_group;

    friend class IconChooser;
    friend class IconContainer;
};

#endif // GROUPFORM_H
