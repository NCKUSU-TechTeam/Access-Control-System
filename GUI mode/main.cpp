#include "mainwindow.h"
#include <QApplication>
#include <QDesktopWidget>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    QDesktopWidget wid;
    // Set windows size: width ( wid.screen()->width()*0.8) , height ( wid.screen()->height()*0.8)
    // ============= Moving the window to center of screen =============
    w.setGeometry(wid.screen()->width()/2 - (wid.screen()->width()*0.5/2) , wid.screen()->height()/2 - ( wid.screen()->height()*0.5/2) , wid.screen()->width()*0.5 , wid.screen()->height()*0.5);
    // ============= Disable scaling size =============
    w.setFixedSize(w.width(),w.height());
    w.setWindowTitle("NCKU-SU Access Control System");
    w.setWindowIcon(QIcon(":nckusu"));
    w.show();

    return a.exec();
}
