/*
 * @FilePath: \FileSync\APP\FileWatcher.h
 * @Description:
 * @Author: MrDeng
 * @LastEditors: MrDeng
 */
#ifndef FILEWATCHER_H
#define FILEWATCHER_H

#include <QObject>
#include <QFileSystemWatcher>
#include <QDir>

class FileWatcher : public QObject
{
    Q_OBJECT
public:
    explicit FileWatcher(QObject *parent = nullptr);

    void setWatchPath(const QString &path);

signals:
    void singal_DirectoryChanged(const QString &path);

    void singal_FileAdded(const QString &file); //增
    void singal_FileRemoved(const QString &file); //文件删除
    void singal_FileChanged(const QString &path); //目录下有改变
    void singal_FileRenamed(const QString &oldName, const QString &newName); //重命名
    
    // 私有表示，只能这个类能使用
private slots:
    void onDirectoryChanged(const QString &path);
    void onFileChanged(const QString &path);

private:   
    /*获取当前目录下所有文件列表*/
    QStringList getDirFileList(void);


private:
    QFileSystemWatcher watcher;
    QString pathWatched;
    QStringList filesOld; //默认被监听的文件列表
    QStringList filesNow; //动态最新




};

#endif // FILEWATCHER_H
