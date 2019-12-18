#include "canvas.h"
#include <QImage>

Canvas::Canvas(QWidget *parent) :
    QLabel(parent)
{
}

void Canvas::mousePressEvent(QMouseEvent *ev)
{
    emit clicked();
}

void Canvas::displayImage(QImage imgDisplay)
{
    setPixmap(QPixmap::fromImage(imgDisplay.scaled(width(), height(), Qt::KeepAspectRatioByExpanding)));
}

