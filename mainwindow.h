#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QKeyEvent>
#include "zswirdialog.h"
#include "replaydlg.h"
#include "imagebrowser.h"
#include "settingdialog.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    ZSWIRSETTINGS* getSettings() { return &m_settings;}

signals:
    void startCapturing();
    void browse(QString);

protected:
    void keyPressEvent(QKeyEvent* event) override;

private:
    Ui::MainWindow *ui;

    ZSwirDialog* m_pZSwirDlg;
    SettingDialog* m_pSettingsDlg;
    ReplayDialog* m_pReplayDlg;
    ImageBrowser* m_pImageBrowser;
    ZSWIRSETTINGS m_settings;

    void loadConfig();

public slots:
    void chooseWidget(WIDGET_ID nIndex);
};

#endif // MAINWINDOW_H
