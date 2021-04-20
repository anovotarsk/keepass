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

    ui->tableWidget->setColumnCount( 5 );
    ui->tableWidget->setRowCount( 5 );
    fillTreeViev( );
}

MainWindow::~MainWindow()
{
    delete ui;
}

void  MainWindow::fillTreeViev( )
{
    QTreeWidgetItem *top = new QTreeWidgetItem( ui->treeWidget );

    ui->treeWidget->addTopLevelItem( top );
    top->setText( 0,  QString::fromStdString( dt->root( )->name( ) ) );

    auto& groops =  dt->root( )->Groups( );

    for ( std::size_t i = 0; i < groops.size( ); i++ )
    {
        QTreeWidgetItem *item = new QTreeWidgetItem( top );
        item->setText( 0, QString::fromStdString( groops[ i ]->name( ) ) );
    }
}


void MainWindow::on_treeWidget_itemClicked(QTreeWidgetItem *item, int column)
{
    ui->tableWidget->clear();
    std::list< std::string > levels;

    auto it = item;
    levels.push_front( item->text( column ).toStdString( ) );
    while ( it->parent( ) != nullptr )
    {
        it = it->parent( );
        levels.push_front( it->text( column ).toStdString( ) );
    }

    if ( levels.size( ) == 1 )
    {
        for ( size_t i = 0; i <  dt->root( )->Entries().size( ); i++ )
        {
            QTableWidgetItem *title = new QTableWidgetItem( );
            title->setText( QString::fromStdString( dt->root( )->Entries()[i]->title( ) ) );
            QTableWidgetItem *userName = new QTableWidgetItem( );
            userName->setText( QString::fromStdString( dt->root( )->Entries()[i]->username( ) ) );
            QTableWidgetItem *password = new QTableWidgetItem( );
            password->setText( QString::fromStdString( dt->root( )->Entries()[i]->password( ) ) );
            QTableWidgetItem *url = new QTableWidgetItem( );
            url->setText( QString::fromStdString( dt->root( )->Entries()[i]->url( ) ) );
            QTableWidgetItem *notes = new QTableWidgetItem( );
            notes->setText( QString::fromStdString( dt->root( )->Entries()[i]->notes( ) ) );

            ui->tableWidget->setItem( i, 0, title );
            ui->tableWidget->setItem( i, 1, userName );
            ui->tableWidget->setItem( i, 2, password );
            ui->tableWidget->setItem( i, 3, url );
            ui->tableWidget->setItem( i, 4, notes );
        }
    }
}
