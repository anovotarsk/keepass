#ifndef GROUPFORM_H
#define GROUPFORM_H

#include <QDialog>

#include <group.hh>

#include "IconChooser.h"
#include "Form.h"

using namespace keepass;

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

private:
    Ui::GroupForm *ui;
    IconChooser *icon_chooser;
    std::shared_ptr<Group> m_group;

    friend class IconChooser;
    friend class IconContainer;
};

#endif // GROUPFORM_H
