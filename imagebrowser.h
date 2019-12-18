#ifndef IMAGE_BROWSER_H
#define IMAGE_BROWSER_H

#include <QDialog>
#include "global.h"
#include "replaycanvas.h"
#include "imagebutton.h"

class ImageBrowser : public QDialog
{
    Q_OBJECT
    
public:
    explicit ImageBrowser(QWidget *parent = nullptr, int rows = 3, int cols = 3);

    ~ImageBrowser();

signals:
    void showWidget(WIDGET_ID);
    void playImage(QString);
    void erase();
    void eraseButtonClicked();

private:
    ZSWIRSETTINGS* m_pSettings;
    int m_nRows;
    int m_nCols;
    int m_nCurrPage;
    int m_nTotalImages;
    int m_nTotalPages;
    int m_nImagePerPage;
    int m_nSelected;

    QList<ReplayCanvas* > m_listCanvas;

    QList<QImage> m_imglistPrevPage;
    QList<QImage> m_imglistCurrPage;
    QList<QImage> m_imglistNextPage;

    QStringList m_filelist;

    void collectFiles();
    void travelDir(QString path, QStringList& imagelist);
    int imagesOnPage(int page);
    QImage loadImage(QString imgLoad);
    bool isFileVideo(QString filename);

private slots:
    void onTimer();
    void nextPage();
    void prevPage();
    void goback();
    void onErase();
    void canvasClicked(int row, int col, bool bSelected);
};


#endif // IMAGE_BROWSER_H
