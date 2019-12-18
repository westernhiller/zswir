#include "imagebrowser.h"
#include <QMessageBox>
#include <QLayout>
#include <QDebug>
#include <QDir>
#include "mainwindow.h"

ImageBrowser::ImageBrowser(QWidget *parent, int nRows, int nCols)
    : QDialog(parent)
    , m_nRows(nRows)
    , m_nCols(nCols)
    , m_nCurrPage(0)
    , m_nSelected(0)
{    
    setWindowFlags(Qt::FramelessWindowHint);
    m_pSettings = static_cast<MainWindow*>(parent)->getSettings();

    collectFiles();
    m_nTotalImages = m_filelist.size();
    m_nImagePerPage = m_nRows * m_nCols;
    m_nTotalPages = m_nTotalImages / m_nImagePerPage + 1;
    if(m_nTotalImages % m_nImagePerPage == 0)
        m_nTotalPages--;

    int nMargin = 10;
    int w = (1076 - (m_nCols + 1) * nMargin) / m_nCols;
    int h = (800 - (m_nRows + 1) * nMargin) / m_nRows;

    for(int i = 0; i < m_nRows; i++)
    {
        for(int j = 0; j < m_nCols; j++)
        {
            ReplayCanvas* pCanvas = new ReplayCanvas(this, i, j);
            pCanvas->setGeometry((j + 1) * nMargin + j * w, (i + 1) * nMargin + i * h, w, h);
            connect(pCanvas, SIGNAL(clicked(int, int, bool)), this, SLOT(canvasClicked(int, int, bool)));
            m_listCanvas.append(pCanvas);
        }
    }

    QWidget *pToolbar = new QWidget(this);
    pToolbar->setGeometry(1076, 0, 204, 800);

    QVBoxLayout* pVLayout = new QVBoxLayout();
    ImageButton* pbtnReturn = new ImageButton(":/images/return.png", ":/images/returnpressed.png");
    pbtnReturn->setFixedWidth(204);
    pVLayout->addWidget(pbtnReturn);
    ImageButton* pbtnNext = new ImageButton(":/images/nextpage.png", ":/images/nextpagepressed.png");
    pbtnNext->setFixedWidth(204);
    pVLayout->addWidget(pbtnNext);
    ImageButton* pbtnPrev = new ImageButton(":/images/prevpage.png", ":/images/prevpagepressed.png");
    pbtnPrev->setFixedWidth(204);
    pVLayout->addWidget(pbtnPrev);
    ImageButton* pbtnErase = new ImageButton(":/images/erase.png", ":/images/erasepressed.png");
    pbtnErase->setFixedWidth(204);
    pVLayout->addWidget(pbtnErase);
    pToolbar->setLayout(pVLayout);

    connect(pbtnReturn, SIGNAL(clicked()), this, SLOT(goback()));
    connect(pbtnNext, SIGNAL(clicked()), this, SLOT(nextPage()));
    connect(pbtnPrev, SIGNAL(clicked()), this, SLOT(prevPage()));
    connect(pbtnErase, SIGNAL(clicked()), this, SLOT(onErase()));

    QTimer* t = new QTimer(this);
    connect(t, SIGNAL(timeout()), this, SLOT(onTimer()));
    t->start(100);
}

ImageBrowser::~ImageBrowser()
{
}

int ImageBrowser::imagesOnPage(int page)
{
    if(page >= m_nTotalPages)
        return 0;
    if(page < 0)
        return 0;

    if(page == m_nTotalPages-1)
        return m_nTotalImages - m_nImagePerPage * (m_nTotalPages - 1);

    return m_nImagePerPage;
}

void ImageBrowser::onTimer()
{
    int imagesOnCurrPage = imagesOnPage(m_nCurrPage);
    int imageLoaded = m_imglistCurrPage.size();
    if(imageLoaded < imagesOnCurrPage)
    {
        int idx = m_nCurrPage * m_nImagePerPage + m_imglistCurrPage.size();
        QImage imgLoaded = loadImage(m_filelist[idx]);
        if(imageLoaded == m_nSelected)
            m_listCanvas[imageLoaded]->select();
        m_listCanvas[imageLoaded]->displayImage(imgLoaded);
        m_listCanvas[imageLoaded]->show();
        m_imglistCurrPage.append(imgLoaded);
    }
    else {
        int imagesOnPrevPage = imagesOnPage(m_nCurrPage - 1);
        if(m_imglistPrevPage.size() < imagesOnPrevPage)
        {
            int idx = (m_nCurrPage - 1) * m_nImagePerPage + m_imglistPrevPage.size();
            m_imglistPrevPage.append(loadImage(m_filelist[idx]));
        }
        else {
            int imagesOnNextPage = imagesOnPage(m_nCurrPage + 1);
            if(m_imglistNextPage.size() < imagesOnNextPage)
            {
                int idx = (m_nCurrPage + 1) * m_nImagePerPage + m_imglistNextPage.size();
                m_imglistNextPage.append(loadImage(m_filelist[idx]));
            }
        }
    }
}

bool ImageBrowser::isFileVideo(QString filename)
{
    QString ext = filename.right(4);
    if(ext.compare(".avi") == 0)
        return true;

    if(ext.compare(".mp4") == 0)
        return true;

    return false;
}

QImage ImageBrowser::loadImage(QString imgLoad)
{
//    qDebug() << "loadImage " << imgLoad;
    if(isFileVideo(imgLoad))
    {
        cv::Mat image;
        qDebug() << "video " << imgLoad;
        cv::VideoCapture vc(imgLoad.toLatin1().data());
        if(vc.isOpened())
            vc >> image;

        if(!image.data)
            image = cv::Mat::zeros(512, 640, CV_8UC3);

        cv::Point pts[4] = {cv::Point(240, 160), cv::Point(240, 352), cv::Point(400, 256), cv::Point(240, 160)};
        cv::fillConvexPoly(image, pts, 4, cv::Scalar(0, 255, 0));

        return mat2qimage(image);
    }
    else
    {
        return QImage(imgLoad);
    }
}

void ImageBrowser::canvasClicked(int row, int col, bool bSelected)
{
    int idx = row * m_nCols + col;
    if(bSelected)
    {
        emit playImage(m_filelist[m_nCurrPage * m_nImagePerPage + idx]);
        emit showWidget(WIDGET_REPLAY);
    }
    else if(m_listCanvas[m_nSelected]->isVisible())
    {
        m_listCanvas[m_nSelected]->deselect();
        m_listCanvas[idx]->select();
        m_nSelected = idx;
    }
}

void ImageBrowser::collectFiles()
{
    // 遍历目录
    QDir dir(m_pSettings->path);
    if(!dir.exists())
    {
        return;
    }
    QStringList imageList;
    foreach(QFileInfo mfi ,dir.entryInfoList())
    {
        if(!mfi.isFile())
        {
            if(mfi.fileName()=="." || mfi.fileName() == "..")
                continue;

            travelDir(mfi.absoluteFilePath(), imageList);
        }
    }
    m_filelist.append(imageList);
}

void ImageBrowser::travelDir(QString path, QStringList& imagelist)
{
    QDir dir(path);
    QStringList filters;
    filters<<QString("*.avi")<<QString("*.mp4")<<QString("*.png")<<QString("*.jpg")<<QString("*.bmp");

    QStringList images = dir.entryList(filters, QDir::Files | QDir::NoSymLinks, QDir::Name);
    foreach(QString filename, images)
    {
        imagelist.append(path + "/" + filename);
    }
}

void ImageBrowser::nextPage()
{
    if(m_imglistNextPage.empty())
        return;
    m_imglistPrevPage.swap(m_imglistCurrPage);
    m_imglistCurrPage.swap(m_imglistNextPage);
    QList<QImage> temp;
    m_imglistNextPage.swap(temp);

    m_nCurrPage++;
    int i = 0;
    for(; i < m_imglistCurrPage.size(); i++)
    {
        m_listCanvas[i]->displayImage(m_imglistCurrPage[i]);
        m_listCanvas[i]->show();
    }
    for(; i < m_nImagePerPage; i++)
    {
        m_listCanvas[i]->hide();
    }
    if(m_nSelected >= m_imglistCurrPage.size())
    {
        m_nSelected = 0;
        m_listCanvas[0]->select();
    }
}

void ImageBrowser::prevPage()
{
    if(m_imglistPrevPage.empty())
        return;

    m_imglistCurrPage.swap(m_imglistNextPage);
    m_imglistPrevPage.swap(m_imglistCurrPage);
    QList<QImage> temp;
    m_imglistPrevPage.swap(temp);

    m_nCurrPage--;
    int i = 0;
    for(; i < m_imglistCurrPage.size(); i++)
    {
        m_listCanvas[i]->displayImage(m_imglistCurrPage[i]);
        m_listCanvas[i]->show();
    }
    for(; i < m_nCols * m_nRows; i++)
    {
        m_listCanvas[i]->hide();
    }
}

void ImageBrowser::onErase()
{
    QMessageBox *msg = new QMessageBox(QMessageBox::Information, "短波红外相机",
                             QStringLiteral("确定要删除选中的图像/视频文件吗？"),
                              QMessageBox::Yes | QMessageBox::No, this);
    QFont font;
    font.setBold(true);
    msg->setFont(font);

    if(QMessageBox::Yes == msg->exec())
    {
        m_imglistCurrPage.removeAt(m_nSelected);
        int idx = m_nSelected + m_nCurrPage * m_nImagePerPage;
        QFile file(m_filelist[idx]);
        file.remove();
        m_filelist.removeAt(idx);
        m_nTotalImages--;

        if(m_imglistNextPage.empty())
        {
            if(m_imglistCurrPage.empty())                       // only one deleted?
            {
                m_nTotalPages--;
                prevPage();
                return;
            }
            else if(m_nSelected >= m_imglistCurrPage.size())     // the last one deleted?
            {
                m_listCanvas[m_nSelected]->deselect();
                m_listCanvas[m_nSelected]->hide();
                m_nSelected--;
                m_listCanvas[m_nSelected]->select();
                return;
            }
        }
        else {
            QImage newImage = m_imglistNextPage.front();
            m_imglistNextPage.pop_front();

            if(!newImage.isNull())
                m_imglistCurrPage.append(newImage);
        }

        int i = m_nSelected;
        for(; i < m_imglistCurrPage.size(); i++)
            m_listCanvas[i]->displayImage(m_imglistCurrPage[i]);
        for(; i < m_nImagePerPage; i++)
            m_listCanvas[i]->hide();
    }
}

void ImageBrowser::goback()
{
    emit showWidget(WIDGET_MAIN);
}
