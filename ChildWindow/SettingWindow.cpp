#include "SettingWindow.h"
#include "ui_SettingWindow.h"

SettingWindow::SettingWindow(QWidget *parent) : QWidget(parent),
                                                ui(new Ui::SettingWindow)
{
    ui->setupUi(this);
    
    //主窗口关闭，同时关闭打开的子窗体
    this->setAttribute(Qt::WA_QuitOnClose, false);
    //子窗体打开后不可操作父窗体，实现阻塞除当前窗体外的其他所有窗体
    this->setWindowModality(Qt::ApplicationModal);

    //从配置中读取当前主题，同步给CBox_SwitchTheme的当前index
    ui->CBox_SwitchTheme->setCurrentText(themeManager->ReadThemeFromConfig());
    
    ui->AppVersion->setText(APPVERSION);
    setWindowIcon(QIcon(APPICON));
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

/*@tag 下拉框选择主题*/
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

/*从配置同步主题下拉框 Current ThemeName*/
void SettingWindow::Set_CBoxSwitchTheme_CurrentText(const QString themeName)
{
    ui->CBox_SwitchTheme->setCurrentText(themeName);
}

/*按钮点击，打开本地配置文件*/
void SettingWindow::on_BtnOpenConfigFile_clicked()
{
    configManager->openINI("./FSyncX_CONFIG.ini");
}

/*按钮点击，检查更新*/
void SettingWindow::on_BtnCheckUpdate_clicked()
{
    QDesktopServices::openUrl(QUrl(RELEASES_SITE));
}
