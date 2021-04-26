#include "UTreeWidgetItem.h"

UTreeWidgetItem::UTreeWidgetItem( QTreeWidget *parent )
    : QTreeWidgetItem( parent )
{
}

UTreeWidgetItem::UTreeWidgetItem( QTreeWidgetItem *parent )
    : QTreeWidgetItem( parent )
{
}

void UTreeWidgetItem::setEntry( std::shared_ptr<Entry> entry )
{
    m_entry = entry;
}

std::shared_ptr<Entry> UTreeWidgetItem::getEntry( )
{
    return m_entry;
}

void UTreeWidgetItem::setGroup( std::shared_ptr<Group> group )
{
    m_group = group;
}

std::shared_ptr<Group> UTreeWidgetItem::getGroup( )
{
    return m_group;
}
