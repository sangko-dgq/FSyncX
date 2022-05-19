
#ifndef PAGEMANAGER_H
#define PAGEMANAGER_H

#include "QHeaders.h"
#include "../mainwindow.h"
#include "../ui_mainwindow.h"

class PageManager : public QObject
{
    Q_OBJECT

public:
    explicit PageManager(QObject *parent = nullptr);
    void LINK_MW(Ui::MainWindow *mw);

    void setCurrentpPage(QWidget *Page);

private:
};

#endif