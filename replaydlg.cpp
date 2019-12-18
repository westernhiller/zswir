#include "replaydlg.h"
#include <QMessageBox>
#include <QLayout>
#include <QDebug>

using namespace std;
using namespace cv;

ReplayDialog::ReplayDialog(QWidget *parent)
    : QDialog(parent)
    , m_pVideo(nullptr)
{    
    setWindowFlags(Qt::FramelessWindowHint);
    setCursor(Qt::BlankCursor);

    QVBoxLayout* pLayout = new QVBoxLayout(this);
    m_pCanvas = new Canvas(this);
    m_pCanvas->setGeometry(0, 0, 1280, 800);
    pLayout->addWidget(m_pCanvas);
    setLayout(pLayout);

    connect(this, SIGNAL(updateImage(QImage)), m_pCanvas, SLOT(displayImage(QImage)));
    connect(m_pCanvas, SIGNAL(clicked()), this, SLOT(onExit()));

    m_pTimer = new QTimer(this);
    connect(m_pTimer, SIGNAL(timeout()), this, SLOT(onTimer()));
}

ReplayDialog::~ReplayDialog()
{
    if(m_pVideo)
        delete m_pVideo;
    if(m_pCanvas)
        delete m_pCanvas;
}

bool ReplayDialog::isFileVideo(QString filename)
{
    QString ext = filename.right(4);
    if(ext.compare(".avi") == 0)
        return true;

    if(ext.compare(".mp4") == 0)
        return true;

    return false;
}

void ReplayDialog::onPlay(QString strFile)
{
    if(isFileVideo(strFile))
    {
        m_pVideo = new cv::VideoCapture(strFile.toLatin1().data());
        if(m_pVideo && m_pVideo->isOpened())
            m_pTimer->start(30);
    }
    else {
        emit updateImage(QImage(strFile));
    }
}

void ReplayDialog::onTimer()
{
    if(m_pVideo && m_pVideo->isOpened())
    {
        Mat imgReplay;
        if(m_pVideo->read(imgReplay))
        {
            if(imgReplay.data)
            {
                emit updateImage(mat2qimage(imgReplay));
            }
        }
        else
        {
            // fail to read more, reaches the end
            delete m_pVideo;
            m_pVideo = nullptr;
        }
    }
}

void ReplayDialog::onExit()
{
    emit showWidget(WIDGET_BROWSER);
}
