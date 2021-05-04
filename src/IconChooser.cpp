#include "IconChooser.h"
#include "ui_IconChooser.h"

IconContainer::IconContainer(  IconChooser *parent,
                               std::string path )
    : path_to_icons( path )
    , m_parent( parent )
{
}

void IconContainer::paintEvent(QPaintEvent *event)
{
    QPainter painter( this );
    //auto size = this->size( );

    for ( int i = 0; i < 7; i++ )
    {
        for ( int j = 0; j < 10; j++ )
        {
            if ( uint32_t( i  * 10 + j ) == m_parent->m_form->m_icon )
            {
                QColor c( 0, 160, 255, 80 );
                painter.fillRect( 30 * j, 30 * i, 23, 23, c );
            }
            QImage img ( QString::fromStdString( path_to_icons + std::to_string( i  * 10 + j ) + ".jpg" ));
            painter.drawImage( 30 * j + 3, 30 * i + 3, img );
        }
    }
}

void IconContainer::mousePressEvent(QMouseEvent *event)
{
    if ( event->button( ) != Qt::LeftButton )
    {
        return;
    }

    if ( event->x( ) > 3 && event->x( ) < 303 && event->y( ) > 3 && event->y( ) < 213 )
    {
        int x = event->x( ) - 3;
        int y = event->y( ) - 3;

        m_parent->m_form->m_icon = (x / 30)  + 10 * (y / 30);
        this->update( );
    }
}


// IconChooser

IconChooser::IconChooser( EntryForm *main,
                          QWidget *parent ) :
    QDialog(parent),
    ui(new Ui::IconChooser),
    m_form( main ),
    m_icon_container( new IconContainer(
                          this,
                          m_form->main_window->args.getProgramPath( )
                          + "resources/icons/" ) )
{
    ui->setupUi(this);
    QHBoxLayout *layout = new QHBoxLayout( this );
    layout->addWidget( m_icon_container );
    this->setLayout( layout );
}

IconChooser::~IconChooser()
{
    delete ui;
}
