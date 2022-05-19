#include "MainWindow.h"

#include <QApplication>
#include "CONFIG/ConfigManager.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();


    // ConfigManager::writeIni("FSyncX_CONFIG.txt", "SETTING", "THEME", "MacOS", false);
 
    // QString keyword;
    // keyword = ConfigManager::readIni(QString("FSyncX_CONFIG.txt"), QString("SETTING"), QString("THEME"), keyword); //读配置文档
    // qDebug() << keyword ;


    return a.exec();
}
