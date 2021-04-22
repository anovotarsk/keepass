#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow( int argc, char* argv[], QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , args( { argc, argv } )
    , type( FileType::NoFile )
{
    ui->setupUi(this);

    if ( args.getStatus( ) != ArgsStatus::NoArgs )
    {
        auto file = args.getFile( );
        std::size_t ext_delim = file.rfind( '.' );

        if ( ext_delim != std::string::npos )
        {
            if ( file.substr(ext_delim, file.size( ) - ext_delim ) == ".kdb" )
                type = Kdb;
            else
            {
                if ( file.substr(ext_delim, file.size( ) - ext_delim ) == ".kdbx" )
                {
                    type = Kdbx;
                }
                else
                {
                    type = ErrorType;
                }
            }

        }

        if ( type == Kdbx )
        {
            KdbxFile file;
            dt = file.Import( args.getFile( ), args.getKey( ) );
        }
        if ( type == Kdb )
        {
            KdbFile file;
            dt = file.Import( args.getFile( ), args.getKey( ) );
        }
    }

    ui->passList->setColumnCount( 5 );
    ui->passList->setStyleSheet("*::item{"
                        "   border: 1px solid silver;"
                        "}"
                        "*::item:selected{"
                        "    background: palette(Highlight);"
                        "}");
    ui->passList->setHeaderLabels( { "Title", "Usar Name", "Password", "URL", "Notes" } );
    ui->passList->setRootIsDecorated( false );

    ui->splitter->setSizes( { 250, 600 } );

    ui->treeWidget->clear( );
    fillTreeViev( );
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::fillTreeViev( UTreeWidgetItem *parent, const std::vector<std::shared_ptr<Group>>* groups )
{
    if ( parent == nullptr )
    {
        parent = new UTreeWidgetItem( ui->treeWidget );

        ui->treeWidget->addTopLevelItem( parent );
        parent->setText( 0,  QString::fromStdString( dt->root( )->name( ) ) );
        parent->setIcon( 0,  QIcon( QString::fromStdString( args.getProgramPath( )
                                                         + "resources/icons/"
                                                         + std::to_string( dt->root( )->icon( ) )
                                                         + ".jpg" ) ) );
        parent->setUuid( dt->root( )->uuid( ) );

        fillTreeViev( parent );
    }
    else
    {
        if (groups == nullptr)
        {
            groups =  &dt->root( )->Groups( );
        }
        for ( std::size_t i = 0; i < groups->size( ); i++ )
        {
            UTreeWidgetItem *item = new UTreeWidgetItem( parent );
            item->setText( 0, QString::fromStdString( (*groups)[ i ]->name( ) ) );
            item->setIcon( 0,  QIcon( QString::fromStdString( args.getProgramPath( )
                                                              + "resources/icons/"
                                                              + std::to_string( (*groups)[ i ]->icon( ) )
                                                              + ".jpg" ) ) );
            item->setUuid( (*groups)[ i ]->uuid( ) );

            fillTreeViev( item, &(*groups)[ i ]->Groups( ) );
        }
    }
}


void MainWindow::on_treeWidget_itemClicked(QTreeWidgetItem *item, int column)
{
    ui->passList->clear( );

    std::vector<std::shared_ptr<Entry>> entries;

    if ( item->parent( ) == nullptr )
    {
        entries = dt->root( )->Entries( );
    }
    else
    {
        entries = get_entries_by_uuid( static_cast<UTreeWidgetItem* >( item )->getUuid( ) );
    }

    for ( auto& entry : entries )
    {
        UTreeWidgetItem *item = new UTreeWidgetItem( ui->passList );
        item->setText( 0, QString::fromStdString( entry->title( ) ) );
        item->setText( 1, QString::fromStdString( entry->username( ) ) );
        item->setText( 2, QString::fromStdString( entry->password( ) ) );
        item->setText( 3, QString::fromStdString( entry->url( ) ) );
        item->setText( 4, QString::fromStdString( entry->notes( ) ) );
        item->setIcon( 0,  QIcon( QString::fromStdString( args.getProgramPath( )
                                                          + "resources/icons/"
                                                          + std::to_string( entry->icon( ) )
                                                          + ".jpg" ) ) );
        item->setUuid( entry->uuid( ) );
    }
}

const std::vector<std::shared_ptr<Entry>>
MainWindow::get_entries_by_uuid( std::array<uint8_t, 16>& uuid,
                     const std::vector<std::shared_ptr<Group>>& Groups )
{
    for ( size_t i = 0; i < Groups.size( ); i++ )
    {
        if ( uuid == Groups[ i ]->uuid( ) )
        {
            return Groups[ i ]->Entries( );
        }
        else
        {
            auto& entries = get_entries_by_uuid( uuid, Groups[ i ]->Groups( ) );
            if ( entries.size( ) != 0 )
            {
                return entries;
            }
        }
    }

    return std::vector<std::shared_ptr<Entry>> ();
}

const std::vector<std::shared_ptr<Entry>>
MainWindow::get_entries_by_uuid( std::array<uint8_t, 16>& uuid )
{
    if ( uuid == dt->root( )->uuid( ) )
    {
        return dt->root( )->Entries( );
    }

    return get_entries_by_uuid( uuid, dt->root( )->Groups( ) );
}
