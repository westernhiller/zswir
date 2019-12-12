#include "zswirdialog.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ZSwirDialog w;
    w.show();

    return a.exec();
}
