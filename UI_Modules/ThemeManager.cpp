
#include "ThemeManager.h"


ThemeManager::ThemeManager(QObject *parent)
    : QObject{parent}
{
}

/*连接MainWindow*//*连接SettingWindow*/
Ui::MainWindow *ui_ofMainWindow_onThemeManager = nullptr;
// Ui::SettingWindow *ui_ofSettingWindow_onThemeManager = nullptr;
void ThemeManager::LINK_MW(Ui::MainWindow *mw)
{
    ui_ofMainWindow_onThemeManager = mw;
}

/*从配置中读取主题键值*/
QString ThemeManager::ReadThemeFromConfig()
{
    QString themeKeyword;
    themeKeyword = configManager->readIni(QString("FSyncX_CONFIG.ini"), QString("SETTING"), QString("THEME"), themeKeyword); //读配置文档
    return themeKeyword;
}

/*程序启动的时候，读取配置，根据读取的配置加载对应主题，并将该主题名同步到Setting窗口的下拉框当前序号*/
void ThemeManager::ApplyThemeFromConfig()
{
    QString themeKeyword;
    themeKeyword = configManager->readIni(QString("FSyncX_CONFIG.ini"), QString("SETTING"), QString("THEME"), themeKeyword); //读配置文档
    qDebug() << themeKeyword;
    commonHelper->setStyle("://" + themeKeyword + ".qss");
}

/*设置主题，并写入到配置表里面*/
void ThemeManager::SetSaveThemeToConfig(QString themeName)
{
    //写入配置表
    configManager -> writeIni("FSyncX_CONFIG.ini", "SETTING", "THEME", themeName, false);
    //设置主题
    commonHelper->setStyle("://" + themeName + ".qss");
}