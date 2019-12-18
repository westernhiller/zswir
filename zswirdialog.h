#ifndef ZSWIRDIALOG_H
#define ZSWIRDIALOG_H

#include <QDialog>
#include <QTimer>
#include "canvas.h"
#include "swircapturer.h"
#include "swirprocessor.h"
#include "videoencoder.h"
#include "photothread.h"

namespace Ui {
class ZSwirDialog;
}

class ZSwirDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ZSwirDialog(QWidget *parent = nullptr);
    ~ZSwirDialog();

    void startThread();

signals:
    void startCapturing();
    void stopCapturing();
    void updateSwir(QImage);
    void savePhoto(QImage);
    void showWidget(WIDGET_ID);

private:
    Ui::ZSwirDialog *ui;

    bool            m_bFullscreen;
    QWidget*        m_pToolbar;
    Canvas*         m_pCanvas;
    QLabel*         m_pMessage;
    SwirCapturer*   m_pSwirCapturer;
    SwirProcessor*  m_pSwirProcessor;
    VideoEncoder*   m_pSwirEncoder;
    PhotoThread*    m_pPhotoSaver;
    bool            m_bRecording;
    bool            m_bSaving;
    QTimer *        m_pTimer;
    ZSWIRSETTINGS*  m_pSettings;
    int             m_nFrame;

    void startRecording();
    void stopRecording();
private slots:
    void startThreads();
    void gotSwir(QImage);
    void onTimer();
    void clickOnCanvas();
    void onPhoto();
    void onVideo();
    void onSettings();
    void onReplay();

public slots:
    void showFPS(bool);
};

#endif // ZSWIRDIALOG_H
