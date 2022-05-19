
#include "SyncPage.h"

SyncPage::SyncPage(QObject *parent)
    : QObject{parent}
{

    

}

//******************************************************* //@tag UI - APP_Sync
/*按钮点击-选择Sync同步路径*/
void MainWindow::on_BtnChoseSyncPath_clicked()
{
    //文件夹路径
    syncPath = QFileDialog::getExistingDirectory(
        this, "choose SyncPath Directory",
        "/");

    if (syncPath.isEmpty())
    {
        isSyncPathValid = false;
        return;
    }

    isSyncPathValid = true;

    commonHelper->TBOut(ui->TBrwSyncDebug, "[SyncPath]" + syncPath);

    ui->TBrwSyncPath->clear();
    commonHelper->TBOut(ui->TBrwSyncPath, syncPath + "/");

    /*SetWatchPath-SyncPath*/
    fileWatcher.setWatchPath(syncPath);

    if (isSyncPathValid)
    {
        ui->PBarSyncConfig->setValue(1);
        commonHelper->Delay(100);
        ui->PBarSyncConfig->setValue(10);
        commonHelper->Delay(80);
        ui->PBarSyncConfig->setValue(20);
    }
    /*补充 - 因为允许先建立连接，再选择路径*/
    //置位连接状态
    if (isSyncBaseConnected && isSyncPathValid)
    {
        ui->PBarSyncConfig->setValue(30);
        commonHelper->Delay(100);
        ui->PBarSyncConfig->setValue(40);
        commonHelper->Delay(80);
        ui->PBarSyncConfig->setValue(55);
    }
}
/*按钮点击-请求连接FBase*/
void MainWindow::on_BtnConnectToFBase_clicked()
{
    Sync_HostToConnect = commonHelper->GetLEditContent(ui->LEditIP);
    Sync_PortToConnect = commonHelper->GetLEditContent(ui->LEditPort);

    commonHelper->TBOut(ui->TBrwSyncDebug,
                        "[SYS] Connect to ");
    commonHelper->TBOut(ui->TBrwSyncDebug,
                        "HOST: " + Sync_HostToConnect);
    commonHelper->TBOut(ui->TBrwSyncDebug,
                        "PORT: " + Sync_PortToConnect);
    //发送到FileTransfer.cpp
    emit signal_ConnectToFBase(Sync_HostToConnect, Sync_PortToConnect);
}

/*按钮点击-开启同步*/
void MainWindow::on_BtnStartSync_clicked()
{
    if (!isSyncPathValid || !isSyncBaseConnected)
    {
        commonHelper->TBOut(ui->TBrwSyncDebug, "[ONSync] [ERROR] SyncPath/Connection is not built...");
        return;
    }

    commonHelper->TBOut(ui->TBrwSyncDebug, "[ONSync] Congratulate! Syncing...");
    //打开全局 允许同步开关
    isONSync = true;
    //禁用打开同步按钮
    ui->BtnStartSync->setEnabled(false);
    ui->PBarSyncConfig->setValue(100);
}

/*按钮点击-打开FSync端同步文件夹*/
void MainWindow::on_BtnOpenSyncPath_clicked()
{
    if (!isSyncPathValid || !QDesktopServices::openUrl(QUrl::fromLocalFile(syncPath)))
    {
        commonHelper->TBOut(ui->TBrwSyncDebug, "[ERROR] Please Check syncPath!...");
        return;
    }

    commonHelper->TBOut(ui->TBrwSyncDebug, "[OpenSyncPath] Open SyncPath :");
    commonHelper->TBOut(ui->TBrwSyncDebug, syncPath);
}


//******************************************************* //@tag 发送同步数据 - APP_Sync
void MainWindow::slot_DirectoryChanged(const QString &path)
{
    if (!isONSync)
        return;
    // commonHelper->TBOut(ui->TBrwSyncDebug, "[DirChanged]" + path);
}

void MainWindow::slot_FileChanged(const QString &file)
{
    if (!isONSync)
        return;
    commonHelper->TBOut(ui->TBrwSyncDebug, "[FileChanged]" + file);
    fileTransfer.sendFile(file);
}

void MainWindow::slot_FileAdded(const QString &file)
{
    if (!isONSync)
        return;
    commonHelper->TBOut(ui->TBrwSyncDebug, "[FileAdded]" + file);
    fileTransfer.sendFile(file);
}
void MainWindow::slot_FileRemoved(const QString &file)
{
    if (!isONSync)
        return;
    commonHelper->TBOut(ui->TBrwSyncDebug, "[FileRemoved]" + file);
    fileTransfer.sendDel(file);
}

void MainWindow::slot_FileRenamed(const QString &oldName, const QString &newName)
{
    if (!isONSync)
        return;
    commonHelper->TBOut(ui->TBrwSyncDebug, "[FileRename]");
    commonHelper->TBOut(ui->TBrwSyncDebug, oldName);
    commonHelper->TBOut(ui->TBrwSyncDebug, "=>");
    commonHelper->TBOut(ui->TBrwSyncDebug, newName);
    fileTransfer.sendRename(oldName, newName);
}
