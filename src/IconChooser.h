#ifndef ICONCHOOSER_H
#define ICONCHOOSER_H

#include <QDialog>
#include <QPaintEvent>
#include <QPainter>
#include <QHBoxLayout>

#include "EntryForm.h"
#include "mainwindow.h"

class IconContainer : public QWidget
{
    Q_OBJECT

public:
    IconContainer( IconChooser *parent,
                   std::string path );

    void paintEvent(QPaintEvent *event) override;
    void mousePressEvent(QMouseEvent *event) override;

private:
    std::string path_to_icons;
    IconChooser *m_parent;
};

namespace Ui {
class IconChooser;
}

class IconChooser : public QDialog
{
    Q_OBJECT

public:
    explicit IconChooser( EntryForm *main,
                          QWidget *parent = nullptr );
    ~IconChooser( );

private:
    Ui::IconChooser *ui;
    Form *m_form;
    IconContainer *m_icon_container;

    friend class IconContainer;
};

#endif // ICONCHOOSER_H
