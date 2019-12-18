#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QSettings>
#include <QStandardPaths>
#include <QDir>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowFlags(Qt::FramelessWindowHint);
    setCursor(Qt::OpenHandCursor);

    loadConfig();

    m_pZSwirDlg = new ZSwirDialog(this);
    m_pSettingsDlg = new SettingDialog(this);
    m_pReplayDlg = new ReplayDialog(this);
    m_pReplayDlg->setFixedSize(1280, 800);
    m_pImageBrowser = new ImageBrowser(this);

    ui->stackedWidget->addWidget(m_pZSwirDlg);
    ui->stackedWidget->addWidget(m_pSettingsDlg);
    ui->stackedWidget->addWidget(m_pImageBrowser);
    ui->stackedWidget->addWidget(m_pReplayDlg);

    connect(m_pZSwirDlg, SIGNAL(showWidget(WIDGET_ID)), this, SLOT(chooseWidget(WIDGET_ID)));
    connect(m_pSettingsDlg, SIGNAL(showWidget(WIDGET_ID)), this, SLOT(chooseWidget(WIDGET_ID)));
    connect(m_pImageBrowser, SIGNAL(showWidget(WIDGET_ID)), this, SLOT(chooseWidget(WIDGET_ID)));
    connect(m_pReplayDlg, SIGNAL(showWidget(WIDGET_ID)), this, SLOT(chooseWidget(WIDGET_ID)));
    connect(m_pImageBrowser, SIGNAL(playImage(QString)), m_pReplayDlg, SLOT(onPlay(QString)));

    connect(m_pSettingsDlg, SIGNAL(showFPS(bool)), m_pZSwirDlg, SLOT(showFPS(bool)));
    connect(this, SIGNAL(startCapturing()), m_pZSwirDlg, SLOT(startThreads()));

    emit startCapturing();
    ui->stackedWidget->setCurrentWidget(m_pZSwirDlg);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::keyPressEvent(QKeyEvent* event)
{
    int keyValue = event->key();
    if(keyValue & Qt::Key_Escape)
    {
        close();
    }
}

void MainWindow::chooseWidget(WIDGET_ID nIndex)
{
    switch(nIndex)
    {
    case WIDGET_MAIN:
        emit startCapturing();
        ui->stackedWidget->setCurrentWidget(m_pZSwirDlg);
        break;
    case WIDGET_REPLAY:
        ui->stackedWidget->setCurrentWidget(m_pReplayDlg);
        break;
    case WIDGET_SETTINGS:
        ui->stackedWidget->setCurrentWidget(m_pSettingsDlg);
        break;
    case WIDGET_BROWSER:
        emit browse(m_settings.path);
        ui->stackedWidget->setCurrentWidget(m_pImageBrowser);
        break;
    case WIDGET_INVALID:
    default:
        break;
    }
}

void MainWindow::loadConfig()
{
    QString home = QStandardPaths::displayName(QStandardPaths::HomeLocation);
    QSettings settings( home + "/.zswir.ini", QSettings::NativeFormat);
    settings.beginGroup("common");
    m_settings.path = settings.value("path", QStandardPaths::standardLocations(QStandardPaths::PicturesLocation)).toString();
    m_settings.bFPS = settings.value("fps", "true").toBool();
    settings.endGroup();
    settings.beginGroup("swir");
    m_settings.ip = settings.value("ip", "192.168.1.10").toString();
    m_settings.port = settings.value("port", "2001").toInt();

    settings.endGroup();

    time_t timeCurrent = time(nullptr);
    struct tm *timeInfo = localtime(&timeCurrent);

    m_settings.pathToday = m_settings.path + QString("/%1%2%3").arg(timeInfo->tm_year + 1900).arg(timeInfo->tm_mon + 1).arg(timeInfo->tm_mday);
    QDir dir(m_settings.pathToday);
    if (!dir.exists())
      dir.mkdir(m_settings.pathToday);
}

