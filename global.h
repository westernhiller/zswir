#ifndef GLOBAL_H
#define GLOBAL_H

#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")
#endif

#include <QImage>

#include <opencv2/opencv.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/video/video.hpp>
#include "opencv2/imgcodecs/imgcodecs.hpp"
#include "opencv2/videoio/videoio.hpp"

const int SWIRWIDTH = 644;
const int SWIRHEIGHT = 512;
const int FRAME_PMNUM =	16;
const int FRAME_PXCNT = SWIRWIDTH * SWIRHEIGHT;
const int FRAMEBUFSIZE = FRAME_PXCNT * 2 + 64;

typedef enum
{
    WIDGET_INVALID,
    WIDGET_MAIN,
    WIDGET_REPLAY,
    WIDGET_BROWSER,
    WIDGET_SETTINGS,
} WIDGET_ID;

typedef struct
{
    QString path;
    QString pathToday;
    QString ip;
    bool bFPS;
    int port;
} ZSWIRSETTINGS;

void msleep(unsigned int msec);

QImage mat2qimage(const cv::Mat &mat);
cv::Mat qimage2mat(const QImage &qimage);
cv::Mat autoWhiteBalance(const cv::Mat& imgin);

#endif // GLOBAL_H
