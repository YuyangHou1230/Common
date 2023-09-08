#ifndef SINGLEAPPLICATION_H
#define SINGLEAPPLICATION_H

#include <QApplication>
#include <QObject>
#include <QLocalServer>

class SingleAppImpl
{
public:
    virtual bool isRunning() = 0;
    virtual void doSomethingIfIsRun() = 0;
};

/**
 * @brief The SingleApplication class
 */
class SingleApplication : public QApplication, public SingleAppImpl
{
public:
#ifdef Q_QDOC
    SingleApplication(int &argc, char **argv);
#else
    SingleApplication(int &argc, char **argv, int = ApplicationFlags);
#endif
    ~SingleApplication();

    bool isRunning() override;
    void doSomethingIfIsRun() override;

    void setMainform(QWidget *mainform);



private slots:
    //有新连接时触发
    void NewLocalConnection();

private:
    //初始化本地连接
    void InitLocalConnection();
    //创建服务端
    void NewLocalServer();
    //激活窗口
    void ActivateWindow();


    QLocalServer *localserver;        //是否已有实例在运行
    QString       serverName;           //本地socket Server
    bool          m_isRunning;               //服务名称

    QWidget *mainForm; // 主窗口指针
};

#endif // SINGLEAPPLICATION_H
