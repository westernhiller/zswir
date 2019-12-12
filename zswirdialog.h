#ifndef ZSWIRDIALOG_H
#define ZSWIRDIALOG_H

#include <QDialog>
#include "glcanvas.h"
#include "swircapturer.h"
#include "swirprocessor.h"
#include "videoencoder.h"

namespace Ui {
class ZSwirDialog;
}

class ZSwirDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ZSwirDialog(QWidget *parent = nullptr);
    ~ZSwirDialog();

signals:
    void updateSwir(QImage image);
    void saveSwirVideoFrame(QImage image);

private:
    Ui::ZSwirDialog *ui;
    QImage          m_imgSwir;
    GLCanvas*       m_pCanvas;
    SwirCapturer*   m_pSwirCapturer;
    SwirProcessor*  m_pSwirProcessor;
    VideoEncoder*   m_pSwirEncoder;
    bool            m_bRecording;
    int             m_nHeartBeatSwir;
    QString         m_path;

private slots:
    void gotSwir(QImage);
    void saveImages(QImage, QImage);
    void onTimer();
    void startRecording();
    void stopRecording();
};

#endif // ZSWIRDIALOG_H
