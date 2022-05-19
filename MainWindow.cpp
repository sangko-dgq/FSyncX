
#include "MainWindow.h"
#include "./ui_MainWindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow)
{
        ui->setupUi(this);
        
        configManager->LINK_MW(ui);
        themeManager->LINK_MW(ui);
        pageManager->LINK_MW(ui);
        settingWindow -> LINK_MW(ui);

        SignalSlotConnectInit_MW_DATA();
        ContextMenuInit();

        //默认处于HomePage
        isHomePageNow = true;
        isSyncPageNow = false;
        isBasePageNow = false;

        isSyncPathValid = false;
        isSyncBaseConnected = false;
        isBasePathValid = false;
        isONSync = false;
        isONListen = false;

        Base_HostGot = commonHelper->getHostIPV4Address().toString();
        Base_PortSet = ui->LEditServerPort->text();

        pageManager->setCurrentpPage(ui->HomePage);
        themeManager->ApplyThemeFromConfig();


        // QString themeKeyword;
        // themeKeyword = configManager->readIni(QString("FSyncX_CONFIG.txt"), QString("SETTING"), QString("THEME"), themeKeyword); //读配置文档
        // qDebug() << themeKeyword;
        // commonHelper->setStyle("://" + themeKeyword + ".qss");
}

MainWindow::~MainWindow()
{
        delete ui;
}

/*MainWindow 与 DATA_XX 的信号与槽的连接建立*/
void MainWindow::SignalSlotConnectInit_MW_DATA()
{
        // FileWatcher => MainWindow
        connect(&fileWatcher,
                SIGNAL(singal_DirectoryChanged(const QString)),
                this,
                SLOT(slot_DirectoryChanged(const QString)));
        connect(&fileWatcher,
                SIGNAL(singal_FileChanged(const QString)),
                this,
                SLOT(slot_FileChanged(const QString)));
        connect(&fileWatcher,
                SIGNAL(singal_FileAdded(const QString)),
                this,
                SLOT(slot_FileAdded(const QString)));
        connect(&fileWatcher,
                SIGNAL(singal_FileRemoved(const QString)),
                this,
                SLOT(slot_FileRemoved(const QString)));
        connect(&fileWatcher,
                SIGNAL(singal_FileRenamed(const QString, const QString)),
                this,
                SLOT(slot_FileRenamed(const QString, const QString)));

        // FileTransfer => MainWindow
        connect(this,
                SIGNAL(signal_ConnectToFBase(QString, QString)),
                &fileTransfer,
                SLOT(slot_ConnectToFBase(QString, QString)));

        connect(&fileTransfer,
                SIGNAL(signal_CommonINFO_FromFileTransfer(QString)),
                this,
                SLOT(slot_CommonINFO_FromFileTransfer(QString)));

        // FileBase => MainWindow
        connect(&fileBase, SIGNAL(signal_File(QString, QByteArray)), this, SLOT(slot_File(QString, QByteArray)));
        connect(&fileBase, SIGNAL(signal_Del(QString)), this, SLOT(slot_Del(QString)));
        connect(&fileBase, SIGNAL(signal_Rename(QString, QString)), this, SLOT(slot_Rename(QString, QString)));
        connect(&fileBase, SIGNAL(signal_CommonINFO_FromFileBase(QString)), this, SLOT(slot_CommonINFO_FromFileBase(QString)));

        // MainWindow => FileBase
        connect(this, SIGNAL(signal_ONOFF_ServerListen(QString, QString, QString)), &fileBase, SLOT(slot_ONOFF_ServerListen(QString, QString, QString)));
}

void MainWindow::on_actionSetting_triggered()
{
        SettingWindow *settingWindow = new SettingWindow;
        settingWindow->show();
}
