
#include "ListenFromDATA.h"

ListenFromDATA::ListenFromDATA(QObject *parent)
    : QObject{parent}
{


}

//*******************************************//@tag 监听来自APP_Base/Sync的通用消息
/*接受来自FileBase的通用信息*/
void MainWindow::slot_CommonINFO_FromFileBase(QString content)
{
    QString ret;
    if (content == "ServerListenOK")
        ret = "OK";
    else
        ret = "False";
    commonHelper->TBOut(ui->TBrwBaseDebug, "[ServerListen] Listen :" + ret);
}

/*接受来自FileTransfer的通用信息*/
void MainWindow::slot_CommonINFO_FromFileTransfer(QString content)
{
    QMessageBox::StandardButton result;

    commonHelper->TBOut(ui->TBrwSyncDebug, content);

    /*采用禁用按钮的方式，避免已连接的情况, 再重复点击请求连接(实际上会自动阻塞，不能再连接)*/
    if (content == "[Sync/Base] Connected")
    {
        if (isBasePageNow) //限制弹窗只在对应的页面弹出
        {
            result = QMessageBox::question(ui->BasePage, "CONNECT", "[From Fsync-Client]Accept Requested Connection?");
        }

        if (result == QMessageBox::No)
        {
            commonHelper->TBOut(ui->TBrwBaseDebug, "[Wanning] You - Rejected - The Connection!");

            /*回传服务器拒绝信号*/
            connect(this, SIGNAL(signal_Reject_or_Break_Connection(QString, QString, QString)),
                    &fileTransfer,
                    SLOT(slot_Reject_or_Break_Connection(QString, QString, QString)));
            emit signal_Reject_or_Break_Connection(Sync_HostToConnect, Sync_PortToConnect, "Reject");

            return;
        }

        commonHelper->TBOut(ui->TBrwBaseDebug, content);
        ui->BtnConnectToFBase->setEnabled(false);

        if (isSyncPathValid)
            ui->PBarSyncConfig->setValue(55);

        //置位连接状态
        isSyncBaseConnected = true;
    }
    if (content == "[Sync/Base] Disconnected")
    {
        commonHelper->TBOut(ui->TBrwBaseDebug, content);
        ui->BtnConnectToFBase->setEnabled(true);
        ui->PBarSyncConfig->setValue(20);

        //置位连接状态
        isSyncBaseConnected = false;
    }

    /**********UI相关回传控制************/
    if (content == "[FileTransfer] Reject message received") // Server发起拒绝
    {
        if (isSyncPageNow)
        {
            QMessageBox::warning(ui->SyncPage, "Warning", "FBase-Server Rejected the Connection!");
        }
        commonHelper->TBOut(ui->TBrwBaseDebug, content);
        ui->BtnConnectToFBase->setEnabled(true);
        ui->PBarSyncConfig->setValue(20);
        isSyncBaseConnected = false;
    }
    if (content == "[FileTransfer] Break message received") // Server发起中断
    {

        QMessageBox::warning(this, "Warning", "Connection Broke!");
    }
}
