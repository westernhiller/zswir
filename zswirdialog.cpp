#include "zswirdialog.h"
#include "ui_zswirdialog.h"
#include <QLayout>
#include <QStandardPaths>
#include <QDebug>
#include <QDateTime>
#include "imagebutton.h"
#include "mainwindow.h"

ZSwirDialog::ZSwirDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ZSwirDialog),
    m_bFullscreen(false),
    m_pSwirEncoder(nullptr),
    m_bRecording(false),
    m_bSaving(false),
    m_nFrame(0)
{
    setWindowFlags(Qt::FramelessWindowHint);
    ui->setupUi(this);

    m_pSettings = static_cast<MainWindow*>(parent)->getSettings();

    m_pCanvas = new Canvas(this);
    m_pCanvas->setGeometry(0, 0, 1280, 800);

    m_pMessage = new QLabel(this);
    m_pMessage->setGeometry(100, 760, 1000, 40);
    m_pMessage->setStyleSheet("QLabel { background:transparent; font: 24pt; }");
    m_pMessage->setText("FPS:");
    if(!m_pSettings->bFPS)
        m_pMessage->hide();

    m_pToolbar = new QWidget(this);
    m_pToolbar->setGeometry(1076, 0, 204, 800);

    QVBoxLayout* pVLayout = new QVBoxLayout();
    ImageButton* pbtnPhoto = new ImageButton(":/images/photo.png", ":/images/photopressed.png");
    pbtnPhoto->setFixedWidth(204);
    pVLayout->addWidget(pbtnPhoto);
    ImageButton* pbtnVideo = new ImageButton(":/images/record.png", ":/images/stop.png", false);
    pbtnVideo->setFixedWidth(204);
    pVLayout->addWidget(pbtnVideo);
    ImageButton* pbtnSettings = new ImageButton(":/images/settings.png", ":/images/settingspressed.png");
    pbtnSettings->setFixedWidth(204);
    pVLayout->addWidget(pbtnSettings);
    ImageButton* pbtnReplay = new ImageButton(":/images/replay.png", ":/images/replaypressed.png");
    pbtnReplay->setFixedWidth(204);
    pVLayout->addWidget(pbtnReplay);
    m_pToolbar->setLayout(pVLayout);

    m_pSwirCapturer = new SwirCapturer(m_pSettings);
    m_pSwirProcessor = new SwirProcessor();

    connect(m_pSwirCapturer, SIGNAL(parseFrame(QByteArray)), m_pSwirProcessor, SLOT(parseFrame(QByteArray)));
    connect(this, SIGNAL(startCapturing()), m_pSwirCapturer, SLOT(start()));
    connect(this, SIGNAL(stopCapturing()), m_pSwirCapturer, SLOT(stop()));

    connect(m_pSwirProcessor, SIGNAL(getFrame(QImage)), this, SLOT(gotSwir(QImage)));
    m_pSwirProcessor->start();

    m_pPhotoSaver = new PhotoThread(m_pSettings->pathToday, this);
    m_pPhotoSaver->start();

    connect(this, SIGNAL(updateSwir(QImage)), m_pCanvas, SLOT(displayImage(QImage)));
    connect(m_pCanvas, SIGNAL(clicked()), this, SLOT(clickOnCanvas()));
    connect(this, SIGNAL(savePhoto(QImage)), m_pPhotoSaver, SLOT(savePhoto(QImage)));

    connect(pbtnPhoto, SIGNAL(clicked()), this, SLOT(onPhoto()));
    connect(pbtnVideo, SIGNAL(clicked()), this, SLOT(onVideo()));
    connect(pbtnReplay, SIGNAL(clicked()), this, SLOT(onReplay()));
    connect(pbtnSettings, SIGNAL(clicked()), this, SLOT(onSettings()));

    m_pTimer = new QTimer(this);
    connect(m_pTimer, SIGNAL(timeout()), this, SLOT(onTimer()));
}

ZSwirDialog::~ZSwirDialog()
{
    delete ui;

    if(m_pSwirCapturer)
        delete m_pSwirCapturer;
    if(m_pSwirEncoder)
        delete m_pSwirEncoder;
}

void ZSwirDialog::startThreads()
{
//    qDebug() << "ZSwirDialog::startThreads()";
    emit startCapturing();
    m_pTimer->start(1000);
}

void ZSwirDialog::onPhoto()
{
    m_bSaving = true;
}

void ZSwirDialog::onVideo()
{
    m_bRecording = !m_bRecording;
    if(m_bRecording)
        startRecording();
    else
        stopRecording();
}

void ZSwirDialog::onSettings()
{
    m_pTimer->stop();
    emit stopCapturing();
    if(m_bRecording)
    {
        stopRecording();
        m_bRecording = false;
    }
    showWidget(WIDGET_SETTINGS);
}

void ZSwirDialog::onReplay()
{
    m_pTimer->stop();
    emit stopCapturing();
    if(m_bRecording)
    {
        stopRecording();
        m_bRecording = false;
    }
    showWidget(WIDGET_BROWSER);
}

void ZSwirDialog::clickOnCanvas()
{
    m_bFullscreen = !m_bFullscreen;
    if(m_bFullscreen)
        m_pToolbar->hide();
    else
        m_pToolbar->show();
}

void ZSwirDialog::onTimer()
{
    static int pos = 0;
    static int framebuffer[] = {0,0,0,0,0,0,0,0,0,0};

    framebuffer[pos++] = m_nFrame;
    if(pos == 10)
        pos = 0;

    int nSum = 0;

    for(int i = 0; i < 10; i++)
        nSum += framebuffer[i];
    double fFrame = nSum / 10.0;
    m_pMessage->setText(QString("FPS:%1").arg(fFrame));

    m_nFrame = 0;
}

void ZSwirDialog::startRecording()
{
    if(!m_pSwirEncoder)
        m_pSwirEncoder = new VideoEncoder();

    QString swirfile = m_pSettings->pathToday + tr("/swir_") + QDateTime::currentDateTime().toString("yyyy-MM-dd-hh-mm-ss") + tr(".mp4");
    m_pSwirEncoder->open(swirfile.toStdString().c_str());
}

void ZSwirDialog::stopRecording()
{
    m_pSwirEncoder->close();
}

void ZSwirDialog::showFPS(bool bShow)
{
    if(bShow)
        m_pMessage->show();
    else {
        m_pMessage->hide();
    }
}

void ZSwirDialog::gotSwir(QImage image)
{
    emit updateSwir(image.copy());
    m_nFrame++;
    if(m_bSaving)
    {
//        qDebug() << "gotswir and save";
        emit savePhoto(image);
        m_bSaving = false;
    }

    if(m_bRecording)
        m_pSwirEncoder->addFrame(image);
}
