
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

    QString result;
    if (content == "NewConnectionRequest" && isBasePageNow)
    {
        QMessageBox askbox(QMessageBox::Question, "请求连接", "是否接受来自未知客户端的连接？");
        askbox.setStandardButtons(QMessageBox::Ok | QMessageBox::Cancel);
        askbox.setButtonText(QMessageBox::Ok, QString("接 受"));
        askbox.setButtonText(QMessageBox::Cancel, QString("拒 绝"));

        int ret = askbox.exec();
        switch (ret)
        {
        case QMessageBox::Ok:
        {
            commonHelper->TBOut(ui->TBrwBaseDebug, "[~~~~~~~~~~~~~~~S/B CONNECTED~~~~~~~~~~~~~~~]");
            break;
        }
        case QMessageBox::Cancel:
        {
            commonHelper->TBOut(ui->TBrwBaseDebug, "[Wanning] You - Rejected - The Connection!");

            /*回传服务器拒绝信号*/
            connect(this, SIGNAL(signal_Reject_or_Break_Connection(QString, QString, QString)),
                    &fileTransfer,
                    SLOT(slot_Reject_or_Break_Connection(QString, QString, QString)));
            emit signal_Reject_or_Break_Connection(Sync_HostToConnect, Sync_PortToConnect, "Reject");
            break;
        }
        }
    }
}

/*接受来自FileTransfer的通用信息*/
void MainWindow::slot_CommonINFO_FromFileTransfer(QString content)
{
    QMessageBox::StandardButton result;

    commonHelper->TBOut(ui->TBrwSyncDebug, "slot_INFO_LOCAL" + content);

    // /*采用禁用按钮的方式，避免已连接的情况, 再重复点击请求连接(实际上会自动阻塞，不能再连接)*/
    if (content == "[Sync/Base] Connected")
    {
        commonHelper->TBOut(ui->TBrwBaseDebug, "[FromSync] 询问是否接受连接？");
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

        QMessageBox::warning(this, "Warning", "FBase-Server Rejected the Connection!");
        commonHelper->TBOut(ui->TBrwBaseDebug, content);
        ui->BtnConnectToFBase->setEnabled(true);
        ui->BtnStartListen->setEnabled(true);

        ui->PBarSyncConfig->setValue(20);
        isSyncBaseConnected = false;
    }
    if (content == "[FileTransfer] Break message received") // Server发起中断
    {
        QMessageBox::warning(this, "Warning", "Connection Broke!");
        commonHelper->TBOut(ui->TBrwBaseDebug, content);
        ui->BtnConnectToFBase->setEnabled(true);
        ui->BtnStartListen->setEnabled(true);
        ui->PBarSyncConfig->setValue(20);
        isSyncBaseConnected = false;
    }
}
