#ifndef REPLAYCANVAS_H
#define REPLAYCANVAS_H

#include "global.h"
#include <QLabel>

class ReplayCanvas : public QLabel
{
    Q_OBJECT
public:
    explicit ReplayCanvas(QWidget *parent = nullptr, int row = 0, int col = 0, bool selected = false);
    ~ReplayCanvas();

    void displayImage(QImage);
    inline bool isSelcted() { return m_bSelected;}
    void select();
    void deselect();
signals:
    void clicked(int, int, bool);

protected:
    void mousePressEvent(QMouseEvent *ev) override;
    void paintEvent(QPaintEvent *e) override;

private:
    int m_nCol;
    int m_nRow;
    bool m_bSelected;
    QPixmap m_pix;

public slots:

};

#endif // REPLAYCANVAS_H
