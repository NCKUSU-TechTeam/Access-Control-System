#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGridLayout>
#include <QTextBrowser>
#include <QPushButton>
#include <QMessageBox>
#include <QProcess>
#include <QTimer>
#include <QFile>

#define VERSION "0.0.1"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    // Setup
    void setupAdderPart();
    void setupScannerPart();
    ~MainWindow();

public slots:
    // Adder
    void scanTheUID();
    void addCurrentUID();
    void clearCurrentUID();

    void pendingScan();
    // Scanner
    void openScanMode();
    void pendingScan_long();
    // Informer
    void showInfo();

private:
    Ui::MainWindow *ui;
    // In main frame
    QWidget *adder;
    QWidget *scanner;

    // In adder part
    QTextBrowser *UID_Displayer;
    // In scanner part
    QTextBrowser *scannedUID,*compareResult;

    QTimer *scanPender,*scanPender_long;
};

#endif // MAINWINDOW_H
