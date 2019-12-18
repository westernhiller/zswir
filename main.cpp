#include "mainwindow.h"
#include <QApplication>
#include <QDebug>

#ifdef Q_OS_LINUX
#include <unistd.h>
#include <errno.h>
#include <sys/wait.h>

int startApplication(int argc, char* argv[], pid_t& pid)
{
    pid = fork();

    if(pid < 0)
    {
        qDebug() << "fork error. errno:" << errno << " error: " << strerror(errno) << "\n";
        return -1;
    }
    if(pid > 0)
        return 0;

    QApplication a(argc, argv);
    MainWindow w;
//    ZSwirDialog w;
    w.show();
//    w.showFullScreen();

    return a.exec();
}

int main(int argc, char *argv[])
{
    pid_t pid;

    startApplication(argc, argv, pid);

    while(1)
    {
        sleep(10);
        if(waitpid(pid, nullptr, WNOHANG) != 0)
        {
            qDebug() << "restart application...\n";
            startApplication(argc, argv, pid);
        }
    }

    return 0;
}

#elif defined (Q_OS_WIN32)

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}


#endif
