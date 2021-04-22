#include "UTreeWidgetItem.h"

UTreeWidgetItem::UTreeWidgetItem( QTreeWidget *parent )
    : QTreeWidgetItem( parent )
{
}

UTreeWidgetItem::UTreeWidgetItem( QTreeWidgetItem *parent )
    : QTreeWidgetItem( parent )
{
}

void UTreeWidgetItem::setUuid( const std::array<uint8_t, 16>& uuid )
{
    m_uuid = uuid;
}

std::array<uint8_t, 16>& UTreeWidgetItem::getUuid( )
{
    return m_uuid;
}
