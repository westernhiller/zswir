#include "zswirdialog.h"
#include "ui_zswirdialog.h"
#include <QLayout>
#include <QStandardPaths>
#include <QDebug>
#include <QDateTime>

ZSwirDialog::ZSwirDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ZSwirDialog),
    m_pSwirEncoder(nullptr),
    m_bRecording(false),
    m_nHeartBeatSwir(0),
    m_path(".")
{
    setWindowFlags(Qt::FramelessWindowHint);
    ui->setupUi(this);

    QColor clearColor;
    clearColor.setHsv(255, 255, 63);
    m_imgSwir = QImage(tr(":/icons/swir.png"));

    m_pCanvas = new GLCanvas(m_imgSwir, this);
    m_pCanvas->setClearColor(clearColor);

    QHBoxLayout* pLayout = new QHBoxLayout(this);
    pLayout->setMargin(0);
    pLayout->addWidget(m_pCanvas);

    m_pSwirCapturer = new SwirCapturer();
    m_pSwirProcessor = new SwirProcessor();

    connect(m_pSwirCapturer, SIGNAL(parseFrame(QByteArray)), m_pSwirProcessor, SLOT(parseFrame(QByteArray)));
    connect(m_pSwirProcessor, SIGNAL(getFrame(QImage)), this, SLOT(gotSwir(QImage)));

    m_pSwirProcessor->start();
    m_pSwirCapturer->start();

    connect(m_pCanvas, SIGNAL(getImages(QImage, QImage)), this, SLOT(saveImages(QImage, QImage)));
    connect(this, SIGNAL(updateSwir(QImage)), m_pCanvas, SLOT(updateSwir(QImage)));

    QTimer *t = new QTimer(this);
    connect(t, SIGNAL(timeout()), this, SLOT(onTimer()));
    t->start(1000);
}

ZSwirDialog::~ZSwirDialog()
{
    delete ui;

    if(m_pSwirCapturer)
        delete m_pSwirCapturer;
    if(m_pSwirEncoder)
        delete m_pSwirEncoder;
}

void ZSwirDialog::onTimer()
{
    // restart if no response for 15 seconds
    if(m_nHeartBeatSwir++ > 15)
    {
        m_pSwirCapturer->restart();
        qDebug() << "restart swir camera connection";
    }
}

void ZSwirDialog::startRecording()
{
    if(!m_pSwirEncoder)
        m_pSwirEncoder = new VideoEncoder();

    QString swirfile = m_path + tr("/swir_") + QDateTime::currentDateTime().toString("yyyy-MM-dd-hh-mm-ss") + tr(".mp4");
    m_pSwirEncoder->open(swirfile.toStdString().c_str());

    m_bRecording = true;
}

void ZSwirDialog::stopRecording()
{
    m_pSwirEncoder->close();
    m_bRecording = false;
}

void ZSwirDialog::saveImages(QImage imgVisible, QImage imgSwir)
{
    QString visiblefile = m_path + tr("/visible_") + QDateTime::currentDateTime().toString("yyyy-MM-dd-hh-mm-ss") + tr(".jpg");
    imgVisible.save(visiblefile, "JPG", 100);

    QString swirfile = m_path + tr("/swir_") + QDateTime::currentDateTime().toString("yyyy-MM-dd-hh-mm-ss") + tr(".jpg");
    imgSwir.save(swirfile, "JPG", 100);
}

void ZSwirDialog::gotSwir(QImage image)
{
    emit updateSwir(image);
    m_nHeartBeatSwir = 0;
    if(m_bRecording)
        m_pSwirEncoder->addFrame(image.copy());
}
