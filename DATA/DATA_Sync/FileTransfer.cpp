/*
 * @FilePath: \FileSync\APP\FileTransfer.cpp
 * @Description:
 * @Author: MrDeng
 * @LastEditors: MrDeng
 */
#include "FileTransfer.h"

FileTransfer::FileTransfer(QObject *parent)
    : QObject{parent}
{
    connect(&tcpSocket, SIGNAL(readyRead()), this, SLOT(slot_onReadyRead()));
    connect(&tcpSocket, SIGNAL(connected()), this, SLOT(slot_onConnected()));
    connect(&tcpSocket, SIGNAL(disconnected()), this, SLOT(slot_onDisconnected()));
    connect(&tcpSocket, SIGNAL(error(QAbstractSocket::SocketError)), this, SLOT(slot_onError(QAbstractSocket::SocketError)));

    // tcpSocket.connectToHost("192.168.1.5", 8888);
}

//************************************************************************Meathods

void FileTransfer::sendFile(const QString &fileName)
{
    //读取文件内容
    QByteArray dataFileContent;

    QFile file(fileName);
    if (!file.open(QIODevice::ReadOnly))
    {
        qDebug() << "[sendFile]file open failed";
        return;
    }
    dataFileContent = file.readAll();
    file.close();

    //封装包头
    QByteArray dataSend; //封装的数据包

    QDataStream stream(&dataSend, QIODevice::WriteOnly);
    stream << (quint32)0 << MsgTypeFile << fileName << dataFileContent;
    stream.device()->seek(0);
    stream << dataSend.size();

    tcpSocket.write(dataSend);
}

void FileTransfer::sendDel(const QString &fileName)
{
    //封装包头
    QByteArray dataSend; //封装的数据包

    QDataStream stream(&dataSend, QIODevice::WriteOnly);
    stream << (quint32)0 << MsgTypeDel << fileName;
    stream.device()->seek(0);
    stream << dataSend.size();

    tcpSocket.write(dataSend);
}

void FileTransfer::sendRename(const QString &fileOld, const QString &fileNew)
{
    //封装包头
    QByteArray dataSend; //封装的数据包

    QDataStream stream(&dataSend, QIODevice::WriteOnly);
    stream << (quint32)0 << (int)MsgTypeRename << fileOld << fileNew;
    stream.device()->seek(0);
    stream << dataSend.size();

    tcpSocket.write(dataSend);
}

//************************************************************************SLOTS
void FileTransfer::slot_onReadyRead()
{
}

void FileTransfer::slot_onConnected()
{
    qDebug() << "connected";
    emit signal_CommonINFO_FromFileTransfer("[Sync/Base] Connected");
}
void FileTransfer::slot_onDisconnected()
{
    qDebug() << "disconnected";

    QObject *obj = this->sender();
    QTcpSocket *socket = qobject_cast<QTcpSocket *>(obj);
    if (socket == 0)
        return;
    
    emit signal_CommonINFO_FromFileTransfer("[Sync/Base] Disconnected");

    socket->close();
}
void FileTransfer::slot_onError(QAbstractSocket::SocketError socketError)
{
    emit signal_CommonINFO_FromFileTransfer("[Sync/Base] ERROR");

    qDebug() << "socket error";
}

void FileTransfer::slot_ConnectToFBase(QString Host, QString port)
{
    tcpSocket.connectToHost(Host, port.toInt());

    emit signal_CommonINFO_FromFileTransfer("[Sync/Base] Start To Connect...");



    qDebug() << "connect to host";
}

/*拒绝或中端网络连接 -- Type: Reject / Break*/
void FileTransfer::slot_Reject_or_Break_Connection(QString Host, QString port, QString Type)
{
    /*根据Type回传不同消息（需要不同窗口）*/
    if(Type == "Reject")
    //通知 SyncPage 弹出waring弹窗，恢复发起连接按钮状态
    emit signal_CommonINFO_FromFileTransfer("[FileTransfer] Reject message received");
    else if(Type == "Break")
    emit signal_CommonINFO_FromFileTransfer("[FileTransfer] Break message received");

    //关闭tcpSocket
    tcpSocket.close();

}