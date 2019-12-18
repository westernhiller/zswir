#include "remotech/imagebuttonex.h"
#include <QPainter>
#include <stdio.h>

namespace remotech {

ImageButtonEx::ImageButtonEx(QWidget *parent)
    :QLabel(parent)
    , m_bHighlighted(false)
    , m_bDehighlightOnRelease(true)
    , m_pTimer(NULL)
{
    m_pTimer = new QTimer(this);
    connect(m_pTimer, SIGNAL(timeout()), SLOT(onTimer()));
}

void ImageButtonEx::setImages(QString image1, QString image2)
{
    m_img = QPixmap(image1);
    if(!image2.isNull())
        m_imgHighlighted = QPixmap(image2);
}

void ImageButtonEx::mouseReleaseEvent(QMouseEvent *event)
{
    if(m_bDehighlightOnRelease)
        m_bHighlighted = false;

    m_pTimer->stop();
    update();
}

void ImageButtonEx::mousePressEvent(QMouseEvent *event)
{
    m_pTimer->start(500);

    if(!m_imgHighlighted.isNull())
    {
        m_bHighlighted = !m_bHighlighted;
        update();
    }
    emit clicked();
}

void ImageButtonEx::onTimer()
{
    emit clicked();
}

void ImageButtonEx::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);

    if(m_imgHighlighted.isNull())
    {
        painter.drawPixmap(rect(), m_img);
    }
    else
    {
        painter.drawPixmap(rect(), m_bHighlighted? m_imgHighlighted : m_img);
    }
}

void ImageButtonEx::highLight()
{
    m_bHighlighted = true;
    update();
}

void ImageButtonEx::dehighLight()
{
    m_bHighlighted = false;
    update();
}

}


