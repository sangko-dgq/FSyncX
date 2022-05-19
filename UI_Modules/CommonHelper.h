

#ifndef COMMONHELPER_H
#define COMMONHELPER_H

#include "QHeaders.h"
#include "../mainwindow.h"
#include "../ui_mainwindow.h"

class CommonHelper : public QObject
{
    Q_OBJECT

public:
explicit CommonHelper(QObject *parent = nullptr);
    


public:
    /*设置全局QSS样式*/
    static void setStyle(const QString &style);
    /*TextBrowser对象换行输出*/
    static void TBOut(QTextBrowser *TextBrowser, QString Content);
    /*获取LineEdit的内容*/
    static QString GetLEditContent(QLineEdit *LineEdit);
    /*使用于单线程非阻塞延时*/
    static void Delay(int msec);
    /** 获取本机IPV4 地址，如果有多个，返回第一个有效的IPV4地址*/
    static QHostAddress getHostIPV4Address();

private:




};



#endif