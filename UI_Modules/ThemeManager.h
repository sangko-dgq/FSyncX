#ifndef THEMEMANAGER_H
#define THEMEMANAGER_H

#include "QHeaders.h"
#include "../mainwindow.h"
#include "../ui_mainwindow.h"


class CommonHelper;
class ConfigManager;
class SettingWindow;

class ThemeManager : public QObject
{
    Q_OBJECT

public:
    explicit ThemeManager(QObject *parent = nullptr);
    void LINK_MW(Ui::MainWindow *mw);

    QString ReadThemeFromConfig();
    void ApplyThemeFromConfig();
    void SetSaveThemeToConfig(QString themeName);

private:
    CommonHelper *commonHelper;
    ConfigManager *configManager;
};

#endif