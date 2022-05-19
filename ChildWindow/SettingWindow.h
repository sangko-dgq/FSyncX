
#ifndef SETTINGWINDOW_H
#define SETTINGWINDOW_H

#include <QWidget>
#include "../UI_Modules/QHeaders.h"
#include "../UI_Modules/ThemeManager.h"

#include "../CONFIG/ConfigManager.h" 

class ThemeManager;
class ConfigManager;

namespace Ui
{
    class SettingWindow;
}

class SettingWindow : public QWidget
{
    Q_OBJECT

public:
    explicit SettingWindow(QWidget *parent = nullptr);
    ~SettingWindow();

    void LINK_MW(Ui::MainWindow *mw);

    void Set_CBoxSwitchTheme_CurrentText(const QString themeName);

private slots:
    void on_CBox_SwitchTheme_currentTextChanged(const QString &arg1);

private:
    Ui::SettingWindow *ui;
    ThemeManager *themeManager;
    ConfigManager *configManager;
    
    void SwitchTheme(const QString);
};

#endif // SETTINGWINDOW_H
