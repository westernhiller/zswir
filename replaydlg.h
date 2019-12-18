#ifndef REPLAYDIALOG_H
#define REPLAYDIALOG_H

#include <QDialog>
#include <QTimer>
#include "global.h"
#include "canvas.h"

class ReplayDialog : public QDialog
{
    Q_OBJECT
    
public:
    explicit ReplayDialog(QWidget *parent = nullptr);

    ~ReplayDialog();
signals:
    void showWidget(WIDGET_ID);
    void updateImage(QImage);

private:
    cv::VideoCapture* m_pVideo;			/*!<表示视频播放类的变量 */

    Canvas* m_pCanvas;		/*!<表示图像显示类的变量 */

    QTimer* m_pTimer;

    bool isFileVideo(QString filename);
private slots:
    void onTimer();

    void onExit();

    void onPlay(QString);
};


#endif // REPLAYDIALOG_H
