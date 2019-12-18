#include "settingdialog.h"
#include "ui_settingdialog.h"
#include <QSettings>
#include <QFileDialog>
#include <QStandardPaths>

#include "mainwindow.h"
#include "imagebutton.h"

SettingDialog::SettingDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SettingDialog)
{
    ui->setupUi(this);
    m_pSettings = static_cast<MainWindow*>(parent)->getSettings();

    ui->editPath->setText(m_pSettings->path);
    connect(ui->btnBrowse, SIGNAL(clicked()), this, SLOT(onBrowse()));
    ui->checkFPS->setChecked(true);

    ImageButton* pbtnReturn = new ImageButton(":/images/return.png", ":/images/returnpressed.png", true, this);
    pbtnReturn->setGeometry(1076, 596, 204, 204);

    connect(pbtnReturn, SIGNAL(clicked()), this, SLOT(onReturn()));
}

SettingDialog::~SettingDialog()
{
    delete ui;
}

void SettingDialog::saveConfig()
{
    QString home = QStandardPaths::displayName(QStandardPaths::HomeLocation);
    QSettings settings( home + "/.zswir.ini", QSettings::NativeFormat);
    settings.beginGroup("common");
    settings.setValue("path", m_pSettings->path);
    settings.setValue("fps", m_pSettings->bFPS);
    settings.endGroup();
    settings.beginGroup("swir");
    settings.setValue("ip", m_pSettings->ip);//读
    settings.setValue("port", m_pSettings->port);
    settings.endGroup();
}

void SettingDialog::onBrowse()
{
    QFileDialog *fileDialog = new QFileDialog(this);
    fileDialog->setFileMode(QFileDialog::DirectoryOnly);
    fileDialog->setOption(QFileDialog::ShowDirsOnly, false);
    fileDialog->setWindowTitle(QStringLiteral("短波红外图像保存"));
    fileDialog->setDirectory(m_pSettings->path);
//    fileDialog->setAcceptMode(QFileDialog::AcceptSave);
    fileDialog->setViewMode(QFileDialog::Detail);
    if(fileDialog->exec() == QDialog::Accepted)
    {
        ui->editPath->setText(fileDialog->selectedFiles().first());
    }
}

void SettingDialog::onReturn()
{
    m_pSettings->path = ui->editPath->text();
    bool bFPS = ui->checkFPS->isChecked();
    if(m_pSettings->bFPS != bFPS)
    {
        m_pSettings->bFPS = bFPS;
        emit showFPS(bFPS);
    }
    saveConfig();
    emit showWidget(WIDGET_MAIN);
}
