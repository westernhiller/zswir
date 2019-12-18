#include "photothread.h"
#include <QDateTime>
#include <QDebug>

PhotoThread::PhotoThread(QString path, QObject* parent)
    : QThread(parent)
    , m_path(path)
{
}

PhotoThread::~PhotoThread()
{
    requestInterruption();
    while(!m_imagelist.empty())
        m_imagelist.pop_front();
    quit();
    wait();
}

void PhotoThread::run()
{
    while (!isInterruptionRequested())
    {
        if(!m_imagelist.empty())
        {
            m_mutex.lock();
            QImage image = m_imagelist.front();
            m_imagelist.pop_front();
            m_mutex.unlock();

            save(image);
        }
        else
            msleep(100);
    }
}

void PhotoThread::save(QImage image)
{
    QDateTime timeNow = QDateTime::currentDateTime();
    QString time = timeNow.toString("yyyy-MM-dd-HH-mm-ss-zzz");
    QString filename = m_path + tr("/") + time + ".jpg";
    image.save(filename);
    qDebug() << "saving image to disk. " << filename;

    emit photoSaved(QString(filename));
}

void PhotoThread::savePhoto(QImage image)
{
    qDebug() << "adding image to save.";
    m_mutex.lock();
    m_imagelist.push_back(image);
    m_mutex.unlock();
}
