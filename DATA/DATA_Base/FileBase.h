/*** 
 * @Author: sangko-dgqq 2201225826@qq.com
 * @Date: 2022-05-14 01:12:47
 * @LastEditors: sangko-dgqq 2201225826@qq.com
 * @LastEditTime: 2022-05-17 01:53:05
 * @FilePath: \FSyncX\APP_Base\FileBase.h
 * @Description:
 * @
 * @Copyright (c) 2022 by sangko-dgqq 2201225826@qq.com, All Rights Reserved. 
 */
/*
 * @FilePath: \FileBase\APP\FileBase.h
 * @Description:
 * @Author: MrDeng
 * @LastEditors: MrDeng
 */
#ifndef FILEBASE_H
#define FILEBASE_H

#include <QObject>
#include <QTcpSocket>
#include <QTcpServer>
#include <QList>

#include <QDataStream>

enum MsgTypeBase
{
    BaseMsgTypeInvalid = 0,
    BaseMsgTypeFile,
    BaseMsgTypeDel,
    BaseMsgTypeRename
};

class FileBase : public QObject
{
    Q_OBJECT
public:
    explicit FileBase(QObject *parent = nullptr);

signals:
    void signal_File(const QString &fileName, const QByteArray &data);
    void signal_Del(const QString &fileName);
    void signal_Rename(const QString &fileOld, const QString &fileNew);

    void signal_CommonINFO_FromFileBase(QString content);

public slots:
    void slot_onNewConnection();

    void slot_onReadyRead();
    void slot_onConnected();
    void slot_onDisconnected();
    void slot_onError(QAbstractSocket::SocketError socketError);

    void  slot_ONOFF_ServerListen(QString Host, QString port, QString ONOFF);

private:
    QTcpServer server;
    QList<QTcpSocket *> clients;

    int imageIndex;
    quint32 sizePackLast;
};

#endif // FILEBASE_H
