
#include "ListenFromDATA.h"

ListenFromDATA::ListenFromDATA(QObject *parent)
    : QObject{parent}
{
}

//*******************************************//@tag 监听来自 客户端/服务端 的通用消息，进行UI处理
/* @fix 接受来自服务端-FileBase的通用信息*/
void MainWindow::slot_CommonINFO_FromFileBase(QString content)
{
    /*监听判断*/
    commonHelper->TBOut(ui->TBrwBaseDebug, "~~~~~~~~~~~" + content + "~~~~~~~~~~~~");

    /*服务端检测到有Client请求连接*/
    if (content == "NewConnectionRequest")
    {
        QMessageBox askbox(QMessageBox::Question, "请求连接", "是否接受来自未知客户端的连接？");
        askbox.setStandardButtons(QMessageBox::Ok | QMessageBox::Cancel);
        askbox.setButtonText(QMessageBox::Ok, QString("接 受"));
        askbox.setButtonText(QMessageBox::Cancel, QString("拒 绝"));

        switch (askbox.exec())
        {
        case QMessageBox::Ok:
        {
            commonHelper->TBOut(ui->TBrwBaseDebug, "[~~~~~~~~~~~~~~~S/B CONNECTED~~~~~~~~~~~~~~~]");
            break;
        }
        case QMessageBox::Cancel:
        {
            commonHelper->TBOut(ui->TBrwBaseDebug, "[Wanning] You - Rejected - The Connection!");

            emit signal_Reject_or_Break_Connection(Sync_HostToConnect, Sync_PortToConnect, "Reject");
            break;
        }
        }
    }

    /*服务端检测到被连接成功*/
    if (content == "[Server] Connected")
    {
        QMessageBox::information(this, "CONNECTED", "服务端检测到被连接成功");

        commonHelper->TBOut(ui->TBrwBaseDebug, content);
        ui->BtnStartListen->setEnabled(false);
        isSyncBaseConnected = true;
    }

    /*服务端检测到连接中断*/
    if (content == "[Server] Disconnected")
    {
        QMessageBox::critical(this, "DISCONNECTED", "服务端检测到连接中断");

        commonHelper->TBOut(ui->TBrwBaseDebug, content);
        ui->BtnStartListen->setEnabled(true);
        ui->PBarBaseConfig->setValue(20);
        isSyncBaseConnected = false;
    }
}

/* @fix 接受来自客户端-FileTransfer的通用信息*/
void MainWindow::slot_CommonINFO_FromFileTransfer(QString content)
{
    QMessageBox::StandardButton result;
    commonHelper->TBOut(ui->TBrwSyncDebug, content);

    // /*采用禁用按钮的方式，避免已连接的情况, 再重复点击请求连接(实际上会自动阻塞，不能再连接)*/
    if (content == "[Client] Connected") //连接成功
    {
        QMessageBox::information(this, "CONNECTED", "客户端检测到连接成功");
        ui->BtnConnectToFBase->setEnabled(false);
        if (isSyncPathValid)
            ui->PBarSyncConfig->setValue(55);
        isSyncBaseConnected = true;
    }
    if (content == "[Client] Disconnected") //连接中断 (主动关闭连接、程序退出、网络断开)
    {
        QMessageBox::critical(this, "DISCONNECTED", "客户端检测到连接中断");

        commonHelper->TBOut(ui->TBrwSyncDebug, content);
        ui->BtnConnectToFBase->setEnabled(true);
        ui->PBarSyncConfig->setValue(20);
        isSyncBaseConnected = false;
    }

    /*ERROR*/
    // Server未开启监听等请求连接错误
    if (content == "[Client] ConnectionRefusedError")
    {
        QMessageBox::critical(this, "ERROR", "Connection Refused Error");
    }
}
