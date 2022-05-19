/*
 * @FilePath: \FileSync\APP\FileWatcher.cpp
 * @Description: 文件监控
 * @Author: MrDeng
 * @LastEditors: MrDeng
 */

#include "FileWatcher.h"
#include <QDebug>

FileWatcher::FileWatcher(QObject *parent)
    : QObject{parent}
{
    /*Singal - Slots*/
    connect(&watcher,
            SIGNAL(directoryChanged(QString)),
            this,
            SLOT(onDirectoryChanged(QString)));
    connect(&watcher,
            SIGNAL(fileChanged(QString)),
            this,
            SLOT(onFileChanged(QString)));
}

void FileWatcher::setWatchPath(const QString &path)
{
    pathWatched = path;
    QStringList files = this->getDirFileList();

    watcher.addPath(path);   //监控根目录
    watcher.addPaths(files); //添加遍历出的所有文件路径，来监控目录下的所有文件的行为

    //默认监听的文件列表
    filesOld = watcher.files();
}

//************************************************************************SLOTS
/*目录改变*/
void FileWatcher::onDirectoryChanged(const QString &path)
{
    emit singal_DirectoryChanged(path);
    // qDebug() << "[Dir Changed]" << path;

    filesNow = this->getDirFileList();
    // qDebug() << "[filesOld]" << filesOld.count();
    // qDebug() << "[filesNow]" << filesNow.count();

    if (filesNow.count() > filesOld.count()) //说明新建了新文件
    {
        /*获取新建的文件名*/
        //遍历上一次的文件列表,从现在的文件列表中移除。filesNow剩下的那个就是我们新建的文件
        foreach (QString filesOldChild, filesOld)
        {
            filesNow.removeAll(filesOldChild);
        }
        //将新建的文件加入到监控里，并且更新默认监听列表fileOld
        watcher.addPaths(filesNow); //监控
        filesOld = watcher.files(); //更新

        emit singal_FileAdded(filesNow.first());
        qDebug() << "[FileAdded]" << filesNow.join(""); // QStringList -> QString
    }
}

/*文件被改变*/
void FileWatcher::onFileChanged(const QString &path)
{
    //监听列表里面还包含path,传进来的文件，说明文件还在，只是发生了改变
    //当前所有被监听的文件
    QStringList filesWatched = watcher.files();

    if (filesWatched.contains(path))
    {
        emit singal_FileChanged(path);
        qDebug() << "[File Changed]" << path;
    }
    else //文件路径不存在了
    {
        filesNow = this->getDirFileList();
        //数量没有发生改变，为重命名操作
        if (filesOld.count() == filesNow.count())
        {

            foreach (QString fileOldChild, filesOld)
            {
                filesNow.removeAll(fileOldChild);
            }
            emit singal_FileRenamed(path, filesNow.first());
            qDebug() << "[File FileRenamed]"
                     << "[old]" << path
                     << "new" << filesNow;

            watcher.addPaths(filesNow);
        }
        else //数量发生变化，为删除操作
        {
            emit singal_FileRemoved(path);
            qDebug() << "[File Removed]" << path;
        }
    }
    //更新filesOld
    filesOld = watcher.files();
}

//************************************************************************Meathods
/*遍历当前目录,返回所有文件列表*/
QStringList FileWatcher::getDirFileList()
{
    QDir dir(pathWatched); //根据路径得到目录
    QFileInfoList infoList = dir.entryInfoList(QDir::Files);

    QStringList ret;

    foreach (QFileInfo info, infoList)
    {
        ret.append(info.absoluteFilePath());
    }

    return ret;
}
