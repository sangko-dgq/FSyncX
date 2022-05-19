
#include "BasePage.h"

BasePage::BasePage(QObject *parent)
    : QObject{parent}
{


}


//*************************************************** //@tag UI - APP_Base
/*按钮点击-选择Base同步路径*/
void MainWindow::on_BtnChoseBasePath_clicked()
{
    //文件夹路径
    BasePath = QFileDialog::getExistingDirectory(
        this, "choose BasePath Directory",
        "/");

    if (BasePath.isEmpty())
    {
        isBasePathValid = false;
        return;
    }

    isBasePathValid = true;
    commonHelper->TBOut(ui->TBrwBaseDebug, "[BasePath]" + BasePath);
    ui->TBrwBasePath->clear();
    commonHelper->TBOut(ui->TBrwBasePath, BasePath + "/");

    if (isBasePathValid)
    {
        ui->PBarBaseConfig->setValue(1);
        commonHelper->Delay(100);
        ui->PBarBaseConfig->setValue(10);
        commonHelper->Delay(80);
        ui->PBarBaseConfig->setValue(20);
    }
    /*补充 - 因为允许先建立连接，再选择路径*/
    //置位连接状态
    if (isSyncBaseConnected && isBasePathValid)
    {
        ui->PBarBaseConfig->setValue(30);
        commonHelper->Delay(100);
        ui->PBarBaseConfig->setValue(40);
        commonHelper->Delay(80);
        ui->PBarBaseConfig->setValue(55);
    }
}

/*按钮点击-打开Base端同步文件夹*/
void MainWindow::on_BtnOpenBasePath_clicked()
{
    if (!QDesktopServices::openUrl(QUrl::fromLocalFile(BasePath)))
    {
        commonHelper->TBOut(ui->TBrwBaseDebug, "[ERROR] Please Check BasePath!...");
        return;
    }

    commonHelper->TBOut(ui->TBrwBaseDebug, "[OpenSyncPath] Open BasePath :");
    commonHelper->TBOut(ui->TBrwBaseDebug, BasePath);
}

/*按钮切换-切换监听状态*/
void MainWindow::on_BtnStartListen_clicked()
{
    if (!isBasePathValid) //路径无效
    {
        commonHelper->TBOut(ui->TBrwBaseDebug, "[ONListen] [ERROR] SyncPath is not built..");
        return;
    }
    commonHelper->TBOut(ui->TBrwBaseDebug, "[ONListen] Congratulate! Listening...");
    //打开全局 允许监听开关
    isONListen = true;

    /*向FileBase发送请求 监听*/
    emit signal_ONOFF_ServerListen(Base_HostGot, Base_PortSet, "ON");

    //禁用打开监听按钮
    ui->BtnStartListen->setEnabled(false);
    ui->PBarBaseConfig->setValue(30);
    commonHelper->Delay(200);
    ui->PBarBaseConfig->setValue(40);
    commonHelper->Delay(200);
    ui->PBarBaseConfig->setValue(60);
    commonHelper->Delay(200);
    ui->PBarBaseConfig->setValue(80);
    commonHelper->Delay(200);
    ui->PBarBaseConfig->setValue(100);

}

/*按钮点击-刷新获取IP*/
void MainWindow::on_BtnGetIP_clicked()
{
    //    if(!isBasePathValid || !isSyncBaseConnected) //路径无效或未连接
    //    {
    //        commonHelper->TBOut(ui->TBrwBaseDebug, "[ONListen] [ERROR] SyncPath/Connection is not built..");
    //        return;
    //    }

    commonHelper->TBOut(ui->TBrwBaseDebug, "Refresh IP...");

    /*更新BaseIPAddr*/
    BaseIPAddr = commonHelper->getHostIPV4Address().toString();

    /*填入TrwServerHos里面*/
    ui->TBrwServerHost->clear();
    commonHelper->TBOut(ui->TBrwServerHost, BaseIPAddr);

    if (isBasePathValid)
        ui->PBarBaseConfig->setValue(50);

    /*Debug*/
    commonHelper->TBOut(ui->TBrwBaseDebug, "[GOT IP]"  +  BaseIPAddr);
}


//***************************************************//@tag 接受同步数据 - APP_Base
void MainWindow::slot_File(const QString &fileName, const QByteArray &data)
{
    qDebug() << "File:" << fileName;

    commonHelper->TBOut(ui->TBrwBaseDebug, "[FSync Success - FileAdded]" + fileName);

    /// fileName是客户端文件的路径-根据传过来的fileName(路径),取出文件名（纯）
    QFileInfo fileInfo(fileName);
    QString fileNamePure = fileInfo.fileName();

    // fileNameLocal是服务端文件的路径-则本地该文件的路径就是fileBasePath + "/" + fileNamePure
    QString fileNameLocal = BasePath + "/" + fileNamePure;

    //打开该文件路径，写入传过来的同步数据
    QFile file(fileNameLocal);
    if (!file.open(QIODevice::WriteOnly))
    {
        qDebug() << "open file failed";
        return;
    }

    //将文件内容写入进去
    file.write(data);
    file.close();
}

void MainWindow::slot_Del(const QString &fileName)
{
    qDebug() << "Del:" << fileName;

    commonHelper->TBOut(ui->TBrwBaseDebug, "[FSync Success - FileRemoved]" + fileName);

    /// fileName是客户端文件的路径-根据传过来的fileName(路径),取出文件名（纯）
    QFileInfo fileInfo(fileName);
    QString fileNamePure = fileInfo.fileName();

    // fileNameLocal是服务端文件的路径-则本地该文件的路径就是fileBasePath + "/" + fileNamePure
    QString fileNameLocal = BasePath + "/" + fileNamePure;

    QFile::remove(fileNameLocal);
}

void MainWindow::slot_Rename(const QString &fileOld, const QString &fileNew)
{
    qDebug() << "Rename:" << fileOld << fileNew;

    commonHelper->TBOut(ui->TBrwBaseDebug, "[FSync Success - FileRename]");
    commonHelper->TBOut(ui->TBrwBaseDebug, fileOld);
    commonHelper->TBOut(ui->TBrwBaseDebug, "=>");
    commonHelper->TBOut(ui->TBrwBaseDebug, fileNew);

    /// fileName是客户端文件的路径-根据传过来的fileName(路径),取出文件名（纯）
    QFileInfo fileInfoOld(fileOld), fileInfoNew(fileNew);
    ;
    QString fileNamePureOld = fileInfoOld.fileName();
    QString fileNamePureNew = fileInfoNew.fileName();

    // fileNameLocal是服务端文件的路径-则本地该文件的路径就是fileBasePath + "/" + fileNamePure
    QString fileNameLocalOld = BasePath + "/" + fileNamePureOld;
    QString fileNameLocalNew = BasePath + "/" + fileNamePureNew;

    if (QFile::rename(fileNameLocalOld, fileNameLocalNew))
    {
        commonHelper->TBOut(ui->TBrwBaseDebug, "Sync Rename SUCCESS!");
    }
    else
    {
        commonHelper->TBOut(ui->TBrwBaseDebug, "Sync Rename ERROR!");
    }
}
