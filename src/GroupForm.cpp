#include "GroupForm.h"
#include "ui_GroupForm.h"

#include "ui_mainwindow.h"

#include "mainwindow.h"
#include "IconChooser.h"

GroupForm::GroupForm( MainWindow *main,
                      QWidget *parent ) :
    QDialog(parent),
    Form( main ),
    ui(new Ui::GroupForm),
    icon_chooser( new IconChooser( this )  )
{
    ui->setupUi(this);
}

GroupForm::~GroupForm()
{
    delete ui;
    delete icon_chooser;
}

void GroupForm::setGroup( std::shared_ptr<Group> group )
{
    m_group = group;
    m_icon = m_group->icon( );
}

std::shared_ptr<Group> GroupForm::getGroup( )
{
    return m_group;
}

int GroupForm::exec( )
{
    ui->name->setText( QString::fromStdString( m_group->name( ) ) );
    ui->icon->setIcon( QIcon( QString::fromStdString( main_window->args.getProgramPath( )
                                                      + "resources/icons/"
                                                      + std::to_string( m_icon )
                                                      + ".jpg" ) ) );
    if ( m_group->uuid( ) == main_window->dt->root( )->uuid( ) )
    {
        ui->del->setEnabled( false );
    }
    else
    {
        ui->del->setEnabled( true );
    }

    return QDialog::exec( );
}

void GroupForm::on_icon_clicked()
{
    icon_chooser->exec();

    ui->icon->setIcon( QIcon( QString::fromStdString( main_window->args.getProgramPath( )
                                                      + "resources/icons/"
                                                      + std::to_string( m_icon )
                                                      + ".jpg" ) ) );
}

void GroupForm::on_save_clicked()
{
    m_group->set_name( protect<std::string>( ui->name->text( ).toStdString( ), true ) );
    m_group->set_icon( m_icon );
    this->close( );

    keepass::Key key( main_window->args.getKey( ) );
    if ( main_window->type == Kdbx )
    {
        keepass::KdbxFile file;
        file.Export( main_window->args.getFile( ), *( main_window->dt ), key );
    }
    if ( main_window->type == Kdb )
    {
        keepass::KdbFile file;
        file.Export( main_window->args.getFile( ), *( main_window->dt ), key );
    }
}

void GroupForm::on_del_clicked()
{
    UTreeWidgetItem *item = static_cast<UTreeWidgetItem *>( main_window->ui->treeWidget->currentItem( ) );
    item = static_cast<UTreeWidgetItem *>( item->parent( ) );

    std::vector<std::shared_ptr<Group>>& groups =
            const_cast<std::vector<std::shared_ptr<Group>>&>( item->getGroup( )->Groups( ) );

    uint32_t i = 0;
    while ( i < groups.size( ) )
    {
        if ( groups[ i ]->uuid( ) == m_group->uuid( ) )
        {
            break;
        }
        i++;
    }

    for ( uint32_t j = i; j < groups.size( ) - 1; j++ )
    {
        groups[ j ] = groups[ j + 1 ];
    }
    groups.resize( groups.size( ) - 1 );

    keepass::Key key( main_window->args.getKey( ) );
    if ( main_window->type == Kdbx )
    {
        keepass::KdbxFile file;
        file.Export( main_window->args.getFile( ), *( main_window->dt ), key );
    }
    if ( main_window->type == Kdb )
    {
        keepass::KdbFile file;
        file.Export( main_window->args.getFile( ), *( main_window->dt ), key );
    }

    close( );
}
