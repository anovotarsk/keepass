#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow( int argc, char* argv[], QClipboard *clipboard, QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , args( { argc, argv } )
    , type( FileType::NoFile )
    , m_clipboard( clipboard )
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

    m_entry_form = new EntryForm( this );
}

MainWindow::~MainWindow()
{
    delete ui;
    delete m_entry_form;
}

void MainWindow::fillTreeViev( UTreeWidgetItem *parent,
                               const std::vector<std::shared_ptr<Group>>* groups )
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
        parent->setGroup( dt->root( ) );

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
            item->setGroup( (*groups)[ i ] );

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
        entries = static_cast<UTreeWidgetItem* >( item )->getGroup( )->Entries( );
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
        item->setEntry( entry );
    }
}

void MainWindow::on_passList_itemDoubleClicked(QTreeWidgetItem *item, int column)
{
    if ( column == 0 )
    {
        auto entry = static_cast<UTreeWidgetItem*>( item )->getEntry( );
        m_entry_form->setEntry( entry );
        m_entry_form->exec( );
        item->setText( 0, QString::fromStdString( entry->title( ) ) );
        item->setText( 1, QString::fromStdString( entry->username( ) ) );
        item->setText( 2, QString::fromStdString( entry->password( ) ) );
        item->setText( 3, QString::fromStdString( entry->url( ) ) );
        item->setText( 4, QString::fromStdString( entry->notes( ) ) );
        item->setIcon( 0,  QIcon( QString::fromStdString( args.getProgramPath( )
                                                          + "resources/icons/"
                                                          + std::to_string( entry->icon( ) )
                                                          + ".jpg" ) ) );
        ui->treeWidget->itemClicked( ui->treeWidget->currentItem( ), 0 );
    }
    else
    {
        m_clipboard->setText( item->text( column ) );
    }
}
