
#include "CommonHelper.h"

CommonHelper::CommonHelper(QObject *parent)
    : QObject{parent}
{

    
}

// @tag Common Helper
/*设置全局QSS样式*/
void CommonHelper::setStyle(const QString &style)
{
    QFile qss(style);
    qss.open(QFile::ReadOnly);
    qApp->setStyleSheet(qss.readAll());
    qss.close();
}
/*TextBrowser对象换行输出*/
void CommonHelper::TBOut(QTextBrowser *TextBrowser, QString Content)
{
    TextBrowser->insertPlainText(Content);
    // 文本输出结束后自动换行
    TextBrowser->moveCursor(QTextCursor::End);
    TextBrowser->append(QString(""));

    
}

/*获取LineEdit的内容*/
QString CommonHelper::GetLEditContent(QLineEdit *LineEdit)
{
    return LineEdit->text();
}

/*适用于单线程非阻塞延时*/
void CommonHelper::Delay(int msec)
{
    QTime dieTime = QTime::currentTime().addMSecs(msec);
    while (QTime::currentTime() < dieTime)
        QCoreApplication::processEvents(QEventLoop::AllEvents);
}
/*获取本机IPV4 地址，如果有多个，返回第一个有效的IPV4地址*/
QHostAddress CommonHelper::getHostIPV4Address()
{
    foreach (const QHostAddress &hostAddress, QNetworkInterface::allAddresses())
        if (hostAddress != QHostAddress::LocalHost && hostAddress.toIPv4Address())
            return hostAddress;

    return QHostAddress::LocalHost;
}