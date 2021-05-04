#include "GroupForm.h"
#include "ui_GroupForm.h"

GroupForm::GroupForm( MainWindow *main,
                      QWidget *parent ) :
    QDialog(parent),
    Form( main ),
    ui(new Ui::GroupForm)
{
    ui->setupUi(this);
}

GroupForm::~GroupForm()
{
    delete ui;
}
