
#include "PageManager.h"

PageManager::PageManager(QObject *parent)
    : QObject{parent}
{
    
}
Ui::MainWindow *ui_PageManager  = nullptr;
void PageManager::LINK_MW(Ui::MainWindow *mw)
{
    ui_PageManager = mw;
}

// @tag 页面管理
void PageManager::setCurrentpPage(QWidget *Page)
{
    ui_PageManager->APPPage->setCurrentWidget(Page);
}


/*I'm FileSync-Client >>*/
void MainWindow::on_btnFileSync_clicked()
{
    ui->APPPage->setCurrentWidget(ui->SyncPage);
    isHomePageNow = false;
    isSyncPageNow = true;
    isBasePageNow = false;

}
/*I'm FileBase-Server >>*/
void MainWindow::on_btnFileBase_clicked()
{
    ui->APPPage->setCurrentWidget(ui->BasePage);
    isHomePageNow = false;
    isSyncPageNow = false;
    isBasePageNow = true;
}
/*menubar-backhome action*/
void MainWindow::on_actionBackHome_triggered()
{
    if (isHomePageNow)
        return;

    //弹出警告提示窗口
    //回到HomePage将中断当前页面属性的相关连接
    QMessageBox::StandardButton ret = QMessageBox::question(this, "Warning", "BackHomePage will break the Connection, Right?");

    if (ret == QMessageBox::No)
        return;

    /*同意退回到HomePage*/
    if (isSyncPageNow)
    {
        emit signal_Reject_or_Break_Connection(Sync_HostToConnect, Sync_PortToConnect, "Break"); //中断连接
        isONSync = false;                                                                        //关闭同步

        //*页面状态*//
        ui->APPPage->setCurrentWidget(ui->HomePage);
        ui->BtnConnectToFBase->setEnabled(true);
        ui->BtnStartSync->setEnabled(true);
        isHomePageNow = true;
        isSyncPageNow = false;
    }
    if (isBasePageNow)
    {
        emit signal_Reject_or_Break_Connection(Base_HostGot, Base_PortSet, "Break"); //中断
        emit signal_ONOFF_ServerListen(Base_HostGot, Base_PortSet, "OFF");           //向FileBase发送关闭监听信号
        isONListen = false;

        ui->APPPage->setCurrentWidget(ui->HomePage);
        ui->BtnStartListen->setEnabled(true);
        isHomePageNow = true;
        isBasePageNow = false;
    }
}