/***
 * @Author: sangko-dgq 2201225826@qq.com
 * @Date: 2022-05-14 01:12:47
 * @LastEditors: sangko-dgq 2201225826@qq.com
 * @LastEditTime: 2022-05-16 22:31:35
 * @FilePath: \FSyncX\APP_Base\FileBase.cpp
 * @Description:
 * @
 * @Copyright (c) 2022 by sangko-dgq 2201225826@qq.com, All Rights Reserved.
 */
#include "FileBase.h"
#include <QDebug>

FileBase::FileBase(QObject *parent)
    : QObject{parent}
{
    connect(&server, SIGNAL(newConnection()), this, SLOT(slot_onNewConnection()));

    // bool ok = server.listen(QHostAddress::AnyIPv4, 8888);
    // qDebug() << "listen:" << ok;
    // emit signal_ServerListen(ok);

    imageIndex = 0;
    sizePackLast = 0;
}

//***************************************************SLOTS

/*当服务器发现有人要来连接时，就会发出newconnection的信号*/
void FileBase::slot_onNewConnection()
{
    //使用这个socket客户端进行通信
    QTcpSocket *socket = server.nextPendingConnection();
    clients.append(socket);//先同意追加到clients

    emit signal_CommonINFO_FromFileBase("NewConnectionRequest");

    //连接信号和槽
    connect(socket, SIGNAL(readyRead()), this, SLOT(slot_onReadyRead()));
    connect(socket, SIGNAL(connected()), this, SLOT(slot_onConnected()));
    connect(socket, SIGNAL(disconnected()), this, SLOT(slot_onDisconnected()));
    connect(socket, SIGNAL(error(QAbstractSocket::SocketError)), this, SLOT(slot_onError(QAbstractSocket::SocketError)));



}

void FileBase::slot_onReadyRead()
{
    QObject *obj = this->sender();
    QTcpSocket *socket = qobject_cast<QTcpSocket *>(obj);

    //当前缓冲区里面数据的大小，收到的数据大小
    qint64 sizeNow = 0;
    do
    {
        sizeNow = socket->bytesAvailable();
        QDataStream stream(socket);

        if (sizePackLast == 0)
        {
            if (sizeNow < sizeof(quint32))
                return;
            stream >> sizePackLast; //已经在值了
        }

        //包不完整返回,等待包完整
        if (sizeNow < sizePackLast - 4)
            return;

        int msgType = BaseMsgTypeInvalid;
        stream >> msgType;

        //设置为0
        sizePackLast = 0;
        //判断剩下的字节数，是否会有粘包的情况
        sizeNow = socket->bytesAvailable();

        switch (msgType)
        {
        case BaseMsgTypeFile:
        {
            QString fileName;
            QByteArray dataFileContent;
            stream >> fileName >> dataFileContent;

            qDebug() << "File" << fileName << dataFileContent;

            emit signal_File(fileName, dataFileContent);
            break;
        }

        case BaseMsgTypeDel:
        {
            QString fileDel;
            stream >> fileDel;

            qDebug() << "FileDel" << fileDel;

            emit signal_Del(fileDel);
            break;
        }

        case BaseMsgTypeRename:
        {
            QString fileOld;
            QString fileNew;
            stream >> fileOld >> fileNew;

            qDebug() << "FileRename" << fileOld << "->" << fileNew;

            emit signal_Rename(fileOld, fileNew);
            break;
        }
        default:
        {
            break;
        }
        }
    } while (sizeNow > 0);
}

void FileBase::slot_onConnected()
{
    qDebug() << "connected";
}

void FileBase::slot_onDisconnected()
{
    QObject *obj = this->sender();
    QTcpSocket *socket = qobject_cast<QTcpSocket *>(obj);

    clients.removeAll(socket);
    socket->deleteLater();

    qDebug() << "disconnected";
}

void FileBase::slot_onError(QAbstractSocket::SocketError socketError)
{

    qDebug() << "error" << socketError;
}

//**************************************** // @tag FileBase ON/OFF Server Listen
void FileBase::slot_ONOFF_ServerListen(QString Host, QString port, QString ONOFF)
{
    bool isServerListenOK;
    if (ONOFF == "ON")
    {
        isServerListenOK = server.listen(QHostAddress::AnyIPv4, port.toInt());
        qDebug() << "ON Server listen";
    }
    else if(ONOFF == "OFF")
    {
        //server.close(); //关闭Server监听
        server.disconnect();
        
        qDebug() << "OFF Server listen";
    }
    
    emit signal_CommonINFO_FromFileBase("ServerListenOK");

}