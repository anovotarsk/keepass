#pragma once

#include <QTreeWidgetItem>

#include <array>

class UTreeWidgetItem : public QTreeWidgetItem
{
public:
    UTreeWidgetItem( QTreeWidget *parent );
    UTreeWidgetItem( QTreeWidgetItem *parent );

    void setUuid( const std::array<uint8_t, 16>& uuid );
    std::array<uint8_t, 16>& getUuid( );

private:
    std::array<uint8_t, 16> m_uuid;
};
