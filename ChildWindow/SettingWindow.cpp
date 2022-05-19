#include "SettingWindow.h"
#include "ui_SettingWindow.h"

SettingWindow::SettingWindow(QWidget *parent) : QWidget(parent),
                                                ui(new Ui::SettingWindow)
{
    ui->setupUi(this);

    //从配置中读取当前主题，同步给CBox_SwitchTheme的当前index
    ui->CBox_SwitchTheme->setCurrentText(themeManager->ReadThemeFromConfig());
    
}

SettingWindow::~SettingWindow()
{
    delete ui;
}

Ui::MainWindow *ui_SettingWindow = nullptr;
void SettingWindow::LINK_MW(Ui::MainWindow *mw)
{
    ui_SettingWindow = mw;
}

/*@tag 下拉窗口选择主题*/
void SettingWindow::on_CBox_SwitchTheme_currentTextChanged(const QString &arg1)
{
    if (arg1 == "Default")
    {
        themeManager->SetSaveThemeToConfig("Default");
    }
    if (arg1 == "MacOS")
    {
        themeManager->SetSaveThemeToConfig("MacOS");
    }
    if (arg1 == "Aqua")
    {
        themeManager->SetSaveThemeToConfig("Aqua");
    }
    if (arg1 == "ConsoleStyle")
    {
        themeManager->SetSaveThemeToConfig("ConsoleStyle");
    }
}


/*同步CBox_SwitchTheme Current ThemeName*/
void SettingWindow::Set_CBoxSwitchTheme_CurrentText(const QString themeName)
{
    ui->CBox_SwitchTheme->setCurrentText(themeName);
}
