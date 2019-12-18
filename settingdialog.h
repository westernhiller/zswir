#ifndef SETTINGDIALOG_H
#define SETTINGDIALOG_H

#include <QDialog>
#include <QLineEdit>
#include "global.h"

namespace Ui {
class SettingDialog;
}

class SettingDialog : public QDialog
{
    Q_OBJECT

public:
    explicit SettingDialog(QWidget *parent = nullptr);
    ~SettingDialog();

signals:
    void showWidget(WIDGET_ID);
    void showFPS(bool);

private:
    Ui::SettingDialog *ui;

    ZSWIRSETTINGS* m_pSettings;

    QLineEdit*  m_pEditPath;

    void saveConfig();

private slots:
    void onBrowse();

    void onReturn();
};

#endif // SETTINGDIALOG_H
