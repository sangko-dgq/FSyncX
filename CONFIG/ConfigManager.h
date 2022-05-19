
#ifndef CONFIGMANAGER_H
#define CONFIGMANAGER_H


#include "../UI_Modules/QHeaders.h"
#include "../mainwindow.h"
#include "../ui_mainwindow.h"

#include <QSettings>

class ConfigManager : public QObject
{
    Q_OBJECT

public:
    explicit ConfigManager(QObject *parent = nullptr);
    void LINK_MW(Ui::MainWindow *mw);
    

private:
    
    


public:
    
    bool static writeIni(QString path, QString section,QString keyword, QString keyvalue,bool clear_flag);
    bool static writeIni(QString path, QString section,QString keyword, QString keyvalue);
    QString static readIni(QString path, QString section,QString keyword, QString &keyvalue);


    
};




#endif
