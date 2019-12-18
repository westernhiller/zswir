#ifndef PHOTOTHREAD_H
#define PHOTOTHREAD_H

#include <QThread>
#include <QMutex>

#include "global.h"

class PhotoThread : public QThread
{
    Q_OBJECT

public:
    explicit PhotoThread(QString path, QObject* parent = nullptr);
    ~PhotoThread() override;

signals:
    void photoSaved(QString photoFile);

protected:
    void run();

private:
    QString m_path; /*!<表示图像保存 */
    QVector<QImage> m_imagelist;
    QMutex m_mutex;

    void save(QImage);

public slots:
    void savePhoto(QImage);
};

#endif // PHOTOTHREAD_H
