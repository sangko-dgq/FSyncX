
#include "ContextMenu.h"

ContextMenu::ContextMenu(QObject *parent)
    : QObject{parent}
{
}

//***************************** //@tag 右键菜单
/*右键菜单-基本元素构造*/
void MainWindow::ContextMenuInit()
{
    //重写Debug窗口自带默认的右键菜单
    ui->TBrwSyncDebug->setContextMenuPolicy(Qt::CustomContextMenu);
    ui->TBrwBaseDebug->setContextMenuPolicy(Qt::CustomContextMenu);

    // TBrwDebug
    CotextMenu_TBrwDebug = new QMenu;                  // object
    action_cleanDebug = new QAction("Clean up", this); // Action
    CotextMenu_TBrwDebug->addAction(action_cleanDebug);

    // QAction Signal/Slot
    connect(action_cleanDebug, SIGNAL(triggered()), this, SLOT(slotAct_cleanTBrwDebug()));

    //@todo customContextMenuRequested / SLOT_Show
    connect(ui->TBrwSyncDebug, SIGNAL(customContextMenuRequested(QPoint)), this, SLOT(slot_showContextMenu_TBrwDebug(QPoint)));
    connect(ui->TBrwBaseDebug, SIGNAL(customContextMenuRequested(QPoint)), this, SLOT(slot_showContextMenu_TBrwDebug(QPoint)));
}

/*slot_弹出右键菜单 */
void MainWindow::slot_showContextMenu_TBrwDebug(QPoint pos)
{
    CotextMenu_TBrwDebug->exec(QCursor::pos()); //在光标位置弹出TBrwDebug右键菜单
}

/*slot_触发右键菜单Action*/
void MainWindow::slotAct_cleanTBrwDebug()
{
    if (isSyncPageNow)
        ui->TBrwSyncDebug->clear();
    else if (isBasePageNow)
        ui->TBrwBaseDebug->clear();
}