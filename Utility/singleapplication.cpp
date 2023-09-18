#include "singleapplication.h"

#include <QDir>
#include <QFileInfo>
#include <QLocalSocket>
#include <QLockFile>
#include <QWidget>
#include <QMessageBox>
#include "windows.h"

#define TIME_OUT   500
#define USE_WIN_API // 使用windows API 可以以原大小进行显示

#ifdef Q_QDOC
SingleApplication::SingleApplication(int &argc, char **argv) : QApplication(argc, argv),
    m_isRunning(false),
    mainForm(nullptr)
{
    serverName = QFileInfo(QApplication::applicationDirPath()).fileName();

    InitLocalConnection();
}
#else
SingleApplication::SingleApplication(int &argc, char **argv, int flags) : QApplication(argc, argv, flags),
    m_isRunning(false),
    mainForm(nullptr)
{
    serverName = QFileInfo(QApplication::applicationFilePath()).fileName(); // 以应用名作为服务器名称

    InitLocalConnection();
}
#endif

SingleApplication::~SingleApplication()
{

}

bool SingleApplication::isRunning()
{
    return m_isRunning;
}

void SingleApplication::doSomethingIfIsRun()
{
    ActivateWindow();
}

void SingleApplication::setMainform(QWidget *_mainform)
{
    mainForm = _mainform;
}

void SingleApplication::NewLocalConnection()
{
    QLocalSocket *localSocket = localserver->nextPendingConnection();
    if(localSocket)
    {
        localSocket->waitForReadyRead(TIME_OUT * 2);
        delete localSocket;

        //其他处理,如:读取启动参数
        ActivateWindow();
    }
}

void SingleApplication::InitLocalConnection()
{
    m_isRunning = false;

    // 尝试连接服务器
    QLocalSocket socket;
    socket.connectToServer(serverName);
    if(socket.waitForConnected(TIME_OUT))
    {
        m_isRunning = true; // 连接成功说明已经有程序在运行

        //其他处理,如:将启动参数发送到服务端
        return;
    }

    //连接不上服务器,就创建一个
    NewLocalServer();
}

void SingleApplication::NewLocalServer()
{
    localserver = new QLocalServer(this);
    connect(localserver, &QLocalServer::newConnection, this, &SingleApplication::NewLocalConnection);
    if(!localserver->listen(serverName))
    {
        // 此时监听失败,可能是程序崩溃时,残留进程服务导致的,移除
        if(localserver->serverError() == QAbstractSocket::AddressInUseError)
        {
            localserver->removeServer(serverName);
            localserver->listen(serverName); //重新监听
        }
    }
    else{
        qWarning() << "服务器创建失败";
    }
}

void SingleApplication::ActivateWindow()
{
    if(mainForm)
    {
#ifdef USE_WIN_API //这个可以显示原窗口的大小（即最小化前的大小）（windowsAPI唤醒窗口）
        HWND hwnd = reinterpret_cast<HWND>(mainForm->winId());

        if(!mainForm->isMinimized()){
            SetForegroundWindow(hwnd);
            ShowWindow(hwnd, SW_RESTORE);
        }
        else{
            ShowWindow(hwnd, SW_RESTORE);
        }
#else
        mainForm->showNormal();
#endif
        mainForm->raise();
        mainForm->activateWindow();
    }
}

#ifdef Q_QDOC
SingleApplicationByLockFile::SingleApplicationByLockFile(int &argc, char **argv) : QApplication(argc, argv)
{
    m_lockFilePath = applicationDirPath();
}
#else
SingleApplicationByLockFile::SingleApplicationByLockFile(int &argc, char **argv, int flags) : QApplication(argc, argv, flags)
{
    m_lockFilePath = applicationDirPath();
}
#endif

void SingleApplicationByLockFile::setLockFilePath(const QString path)
{
    m_lockFilePath = path;
    if(path.isEmpty()){
        m_lockFilePath = applicationDirPath();
    }

    QFileInfo fileinfo(m_lockFilePath);
    QDir dir(fileinfo.absolutePath());
    if(!dir.exists())
    {
        dir.mkpath(fileinfo.absolutePath());
    }

}


bool SingleApplicationByLockFile::isRunning()
{
    QFileInfo fileinfo(m_lockFilePath);
    QLockFile lockfile(fileinfo.absoluteFilePath());
    if(!lockfile.tryLock(2000))
    {
        return true;
    }

    return false;
}

void SingleApplicationByLockFile::doSomethingIfIsRun()
{
    QMessageBox::critical(nullptr, "错误", "当前已有程序实例正在运行！！！");
}
