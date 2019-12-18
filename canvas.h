#ifndef CANVAS_H
#define CANVAS_H

#include "global.h"
#include <QLabel>

class Canvas : public QLabel
{
    Q_OBJECT
public:
    explicit Canvas(QWidget *parent = nullptr);

signals:
    void clicked();

protected:
    void mousePressEvent(QMouseEvent *ev);

public slots:
    void displayImage(QImage);
};

#endif // CANVAS_H
