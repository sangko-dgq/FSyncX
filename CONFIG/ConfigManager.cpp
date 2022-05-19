
#include "ConfigManager.h"

ConfigManager::ConfigManager(QObject *parent)
    : QObject{parent}
{


}

Ui::MainWindow *ui = nullptr;
void ConfigManager::LINK_MW(Ui::MainWindow *mw)
{
    ui = mw;
}

bool ConfigManager::writeIni(QString path, QString section, QString keyword, QString keyvalue)
{
    if (path == QString(""))
    {
        return false;
    }
    else
    {
        //创建配置文件操作对象
        QSettings *config = new QSettings(path, QSettings::IniFormat);

        //将信息写入配置文件
        config->beginGroup(section);
        config->setValue(keyword, keyvalue);
        config->endGroup();

        if (config)
        {
            delete config;
        }

        return true;
    }
}

bool ConfigManager::writeIni(QString path, QString section, QString keyword, QString keyvalue, bool clear_flag)
{
    if (path == QString(""))
    {
        return false;
    }
    else
    {
        //创建配置文件操作对象
        QSettings *config = new QSettings(path, QSettings::IniFormat);
        if (clear_flag == true)
            config->clear();

        //将信息写入配置文件
        config->beginGroup(section);
        config->setValue(keyword, keyvalue);
        config->endGroup();

        if (config)
        {
            delete config;
        }

        return true;
    }
}

QString ConfigManager::readIni(QString path, QString section, QString keyword, QString &keyvalue)
{
    if (path == QString(""))
    {
        qDebug() << "未找到配置文件";
        QString ret = "Default";
        return ret;
    }
    else
    {
        //创建配置文件操作对象
        QSettings *config = new QSettings(path, QSettings::IniFormat);

        keyvalue = config->value(section + "/" + keyword).toString();

        if (config)
        {
            delete config;
        }

        return keyvalue;
    }
}


//example：
//     ConfigManager::writeIni("log.txt", "config1", "key1", "test");
//     ConfigManager::writeIni("log.txt", "config1", "key2", "test2");
//     ConfigManager::writeIni("log.txt", "config2", "key1", "test");
//     ConfigManager::writeIni("log.txt", "config2", "key2", "test2");
//     ConfigManager::writeIni("log.txt", "config2", "key2", "test2");   
       //写入不清除原配置
//     ConfigManager::writeIni("log.txt", "config3", "key", "hello world", false); //如果clear_flag=true，清除原配置
 
//     QString keyword;
//     keyword = ConfigManager::readIni(QString("log.txt"), QString("config3"), QString("key"), keyword); //读配置文档
//     qDebug() << keyword ;