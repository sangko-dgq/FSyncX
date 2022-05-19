

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "UI_Modules/QHeaders.h"

#include "DATA/DATA_Sync/FileWatcher.h"
#include "DATA/DATA_Sync/FileTransfer.h"
#include "DATA/DATA_Base/FileBase.h"

#include "UI_Modules/CommonHelper.h"
#include "UI_Modules/PageManager.h"
#include "UI_Modules/SyncPage.h" 
#include "UI_Modules/BasePage.h"
#include "UI_Modules/ContextMenu.h"
#include "UI_Modules/ThemeManager.h"

#include "CONFIG/ConfigManager.h"

#include "ChildWindow/SettingWindow.h"


QT_BEGIN_NAMESPACE
namespace Ui
{
    class MainWindow;
}
QT_END_NAMESPACE

/*UI Modules Class前置声明解决，因头文件互相包含且有类引用导致，XX(class) does not name a type问题*/
class CommonHelper;
class PageManager;
class SyncPage;
class BasePage;
class ContextMenu;

class ConfigManager;
class ThemeManager;

class SettingWindow;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    


signals:
    void signal_ConnectToFBase(QString Host, QString port);
    void signal_Reject_or_Break_Connection(QString Host, QString port, QString Type); // Host发起拒绝请求或阻断已连接
    void signal_ONOFF_ServerListen(QString Host, QString port, QString ONOFF);

private slots:
    void on_btnFileSync_clicked();
    void on_btnFileBase_clicked();
    void on_actionBackHome_triggered();
    void on_BtnChoseSyncPath_clicked();
    void on_BtnChoseBasePath_clicked();
    void on_BtnConnectToFBase_clicked();
    void on_BtnStartSync_clicked();
    void on_BtnOpenSyncPath_clicked();
    void on_BtnOpenBasePath_clicked();
    void on_BtnStartListen_clicked();
    void on_BtnGetIP_clicked();

    void on_actionSetting_triggered();

    /*APP_Sync*/
    void slot_DirectoryChanged(const QString &path);
    void slot_FileAdded(const QString &file);                              //增
    void slot_FileRemoved(const QString &file);                            //文件删除
    void slot_FileChanged(const QString &file);                            //目录下有改变
    void slot_FileRenamed(const QString &oldName, const QString &newName); //重命名

    /*接受FileTransfer的相关信息*/
    void slot_CommonINFO_FromFileTransfer(QString content);

    /*APP_Base*/
    void slot_File(const QString &fileName, const QByteArray &data);
    void slot_Del(const QString &fileName);
    void slot_Rename(const QString &fileOld, const QString &fileNew);

    void slot_CommonINFO_FromFileBase(QString content);

    /*右键菜单*/
    void slot_showContextMenu_TBrwDebug(QPoint pos);
    void slotAct_cleanTBrwDebug();

private:
    Ui::MainWindow *ui;

    void SignalSlotConnectInit_MW_DATA();

    /*ChildWindow**/
    SettingWindow *settingWindow;


    /*UI_Modules*/ //@note 在MainWindow引入UI_Modules中的各个模块Class
    CommonHelper *commonHelper;
    PageManager *pageManager;
    SyncPage *syncPage;
    BasePage *basePage;
    ContextMenu *contextMenu;

    ConfigManager *configManager;
    ThemeManager *themeManager;;

    /*DATA*/
    FileWatcher fileWatcher;
    FileTransfer fileTransfer;


    /*右键菜单*/
    void ContextMenuInit();
    QMenu *CotextMenu_TBrwDebug;
    QAction *action_cleanDebug; //清空

    /*SyncPage*/
    QString syncPath;
    QString Sync_HostToConnect, Sync_PortToConnect;

    /*BasePage*/
    FileBase fileBase;
    QString BasePath;
    QString Base_HostGot, Base_PortSet;
    QString BaseIPAddr;

    /*状态记录*/
    bool isHomePageNow;
    bool isSyncPageNow;
    bool isBasePageNow;

    bool isSyncPathValid;
    bool isBasePathValid;
    bool isSyncBaseConnected;

    /*全局开关*/
    bool isONSync;
    bool isONListen;

};

#endif // MAINWINDOW_H
