#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow( int argc, char* argv[], QClipboard *clipboard, QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , args( { argc, argv } )
    , type( FileType::NoFile )
    , m_clipboard( clipboard )
    , m_entry_form( new EntryForm( this ) )
    , m_group_form( new GroupForm( this ) )
{
    ui->setupUi(this);

    auto actions = ui->toolBar->actions( );
    actions[ 0 ]->setIcon( QIcon( QString::fromStdString( args.getProgramPath( )
                                                          + "resources/new_file.jpg" ) ) );
    actions[ 1 ]->setIcon( QIcon( QString::fromStdString( args.getProgramPath( )
                                                          + "resources/open_file.jpg" ) ) );
    actions[ 2 ]->setIcon( QIcon( QString::fromStdString( args.getProgramPath( )
                                                          + "resources/icons/0.jpg" ) ) );
    actions[ 3 ]->setIcon( QIcon( QString::fromStdString( args.getProgramPath( )
                                                          + "resources/icons/48.jpg" ) ) );

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
}

MainWindow::~MainWindow()
{
    delete ui;
    delete m_entry_form;
    delete m_group_form;
}

void MainWindow::fillTreeViev( UTreeWidgetItem *parent,
                               const std::vector<std::shared_ptr<Group>>* groups )
{
    if ( parent == nullptr )
    {
        ui->treeWidget->clear( );
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
    ui->treeWidget->expandAll( );
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

void MainWindow::on_treeWidget_itemDoubleClicked(QTreeWidgetItem *item, int column)
{
    auto group = static_cast<UTreeWidgetItem*>( item )->getGroup( );
    m_group_form->setGroup( group );
    m_group_form->exec( );
    item->setText( 0, QString::fromStdString( group->name( ) ) );
    item->setIcon( 0,  QIcon( QString::fromStdString( args.getProgramPath( )
                                                      + "resources/icons/"
                                                      + std::to_string( group->icon( ) )
                                                      + ".jpg" ) ) );
    fillTreeViev( );
}

void MainWindow::on_actionAdd_Entry_triggered()
{
    if ( ui->treeWidget->currentItem( ) == nullptr )
    {
        return;
    }

    auto item = static_cast<UTreeWidgetItem *>( ui->treeWidget->currentItem( ) );

    std::vector<std::shared_ptr<Entry>>& entries =
            const_cast<std::vector<std::shared_ptr<Entry>>&>( item->getGroup( )->Entries( ) );

    entries.push_back( std::make_shared<Entry>( Entry( ) ) );
    on_treeWidget_itemClicked( item, 0 );

}

void MainWindow::on_actionAdd_Group_triggered()
{
    if ( ui->treeWidget->currentItem( ) == nullptr )
    {
        return;
    }

    auto item = static_cast<UTreeWidgetItem *>( ui->treeWidget->currentItem( ) );

    std::vector<std::shared_ptr<Group>>& groups =
            const_cast<std::vector<std::shared_ptr<Group>>&>( item->getGroup( )->Groups( ) );

    groups.push_back( std::make_shared<Group>( Group( ) ) );
    fillTreeViev( );
}

void MainWindow::on_actionNew_File_triggered()
{
    std::string file = QFileDialog::getSaveFileName( this, "Open", "~/", "*.kdbx" ).toStdString( );

    if ( file == "" )
    {
        return;
    }

    if ( file.rfind( ".kdbx" ) == std::string::npos )
    {
        file = file + ".kdbx";
    }

    std::string key = QInputDialog::getText( this, "Set Key", "Key:" ).toStdString( );
    char* argv[] = { const_cast<char*>( args.getProgram( ).c_str( ) ),
                     const_cast<char*>( file.c_str( ) ),
                     const_cast<char*>( key.c_str( ) )
                   } ;
    args = ArgsParser( 3, argv );
    KdbxFile white;
    dt = white.Import( args.getProgramPath( ) + "resources/white.kdbx", { "white" } );
    white.Export( file, *dt, key );

    fillTreeViev( );
}

void MainWindow::on_actionOpen_File_triggered()
{
    std::string file = QFileDialog::getOpenFileName( this, "Open", "~/", tr( "*.kdbx *.kdb" ) ).toStdString( );

    if ( file == "" )
    {
        return;
    }

    std::string key = QInputDialog::getText( this, "Set Key", "Key:" ).toStdString( );
    char* argv[] = { const_cast<char*>( args.getProgram( ).c_str( ) ),
                     const_cast<char*>( file.c_str( ) ),
                     const_cast<char*>( key.c_str( ) )
                   } ;
    args = ArgsParser( 3, argv );

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
    try
    {
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
    catch ( std::exception& e )
    {
        QMessageBox message;
        message.setIcon( QMessageBox::Critical );
        message.setText( e.what( ) );
        message.setModal( true );
        message.exec( );
        return;
    }

    fillTreeViev( );
}
