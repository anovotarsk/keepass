#include "EntryForm.h"
#include "ui_EntryForm.h"
#include "ui_mainwindow.h"

#include <iostream>

#include "mainwindow.h"
#include "IconChooser.h"

EntryForm::EntryForm( MainWindow *main,
                      QWidget *parent) :
    QDialog(parent),
    Form( main ),
    ui(new Ui::EntryForm),
    icon_chooser( new IconChooser( this ) )
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
    m_icon = m_entry->icon( );
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
                                                      + std::to_string( m_icon )
                                                      + ".jpg" ) ) );
    return QDialog::exec( );
}

void EntryForm::on_icon_clicked( )
{
    icon_chooser->exec();

    ui->icon->setIcon( QIcon( QString::fromStdString( main_window->args.getProgramPath( )
                                                      + "resources/icons/"
                                                      + std::to_string( m_icon )
                                                      + ".jpg" ) ) );
}

void EntryForm::on_save_clicked( )
{
    m_entry->set_title( protect<std::string>( ui->title->text( ).toStdString( ), true ) );
    m_entry->set_username( protect<std::string>( ui->user_name->text( ).toStdString( ), true ) );
    m_entry->set_password( protect<std::string>( ui->password->text( ).toStdString( ), true ) );
    m_entry->set_url( protect<std::string>( ui->url->text( ).toStdString( ), true ) );
    m_entry->set_notes( protect<std::string>( ui->notes->toPlainText( ).toStdString( ), true ) );
    m_entry->set_icon( m_icon );
    this->close( );

    keepass::Key key( main_window->args.getKey( ) );
    keepass::KdbxFile file;
    file.Export( main_window->args.getFile( ), *( main_window->dt ), key );
}

void EntryForm::on_del_clicked( )
{
    UTreeWidgetItem *item = static_cast<UTreeWidgetItem *>( main_window->ui->treeWidget->currentItem( ) );

    auto entries = item->getGroup( )->Entries( );

    uint32_t i = 0;
    while ( i < entries.size( ) )
    {
        if ( entries[ i ]->uuid( ) == m_entry->uuid( ) )
        {
            break;
        }
        i++;
    }

    for ( uint32_t j = i; j < entries.size( ) - 1; j++ )
    {
        entries[ j ] = entries[ j + 1 ];
    }
    entries.resize( entries.size( ) - 1 );

    keepass::Key key( main_window->args.getKey( ) );
    keepass::KdbxFile file;
    file.Export( main_window->args.getFile( ), *( main_window->dt ), key );
    main_window->on_treeWidget_itemClicked( item, 0 );
    close( );
    destroy( );
}
