#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGridLayout>
#include <QTextBrowser>
#include <QPushButton>
#include <QMessageBox>
#include <QProcess>
#include <QFile>

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

    // Adder Part
    void scanUID();
    void addUID();
    void clearUID();
    // Scanner Part

    ~MainWindow();

public slots:
    // Adder
    void scanTheUID();
    void addCurrentUID();
    void clearCurrentUID();
    // Scanner
    void openScanMode();
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
};

#endif // MAINWINDOW_H
