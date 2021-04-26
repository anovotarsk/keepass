#pragma once

#include <QTreeWidgetItem>

#include <array>
#include <memory>

#include <group.hh>

using namespace keepass;

class UTreeWidgetItem : public QTreeWidgetItem
{
public:
    UTreeWidgetItem( QTreeWidget *parent );
    UTreeWidgetItem( QTreeWidgetItem *parent );

    void setEntry( std::shared_ptr<Entry> entry );
    std::shared_ptr<Entry> getEntry( );

    void setGroup( std::shared_ptr<Group> group );
    std::shared_ptr<Group> getGroup( );

private:
    std::shared_ptr<Group> m_group;
    std::shared_ptr<Entry> m_entry;
};
