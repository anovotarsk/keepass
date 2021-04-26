#include "EntryForm.h"
#include "ui_EntryForm.h"

#include <iostream>

#include "mainwindow.h"

EntryForm::EntryForm( MainWindow *main,
                      QWidget *parent) :
    QDialog(parent),
    ui(new Ui::EntryForm),
    main_window( main )
{
    ui->setupUi(this);
}

EntryForm::~EntryForm()
{
    delete ui;
}

void EntryForm::setEntry( std::shared_ptr<Entry> entry )
{
    m_entry = entry;
}

std::shared_ptr<Entry> EntryForm::getEntry( )
{
    return m_entry;
}

int EntryForm::exec( )
{
    ui->title->setText( QString::fromStdString( m_entry->title( ) ) );
    ui->user_name->setText( QString::fromStdString( m_entry->username( ) ) );
    ui->password->setText( QString::fromStdString( m_entry->password( ) ) );
    ui->url->setText( QString::fromStdString( m_entry->url( ) ) );
    ui->notes->setText( QString::fromStdString( m_entry->notes( ) ) );
    ui->icon->setIcon( QIcon( QString::fromStdString( main_window->args.getProgramPath( )
                                                      + "resources/icons/"
                                                      + std::to_string( m_entry->icon( ) )
                                                      + ".jpg" ) ) );

    return QDialog::exec( );
}
