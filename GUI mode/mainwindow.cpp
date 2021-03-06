#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->mainToolBar->setVisible(false);
    ui->menuBar->setVisible(false);
    // Set up layout and add the object into it
    adder = new QWidget();
    scanner = new QWidget();
    QPushButton *informer = new QPushButton("About");

    QGridLayout *mainLayout = new QGridLayout();

    mainLayout->addWidget(adder,0,0,1,1);
    mainLayout->addWidget(scanner,1,0,1,1);
    mainLayout->addWidget(informer,2,0,1,1);
    ui->centralWidget->setLayout(mainLayout);
    ui->centralWidget->setFont(QFont(QString("Consolas")));

    // Set up FrameWork
    setupAdderPart();
    setupScannerPart();

    connect(informer,SIGNAL(clicked(bool)),this,SLOT(showInfo()));
}

void MainWindow::setupAdderPart()
{
    // Setting Adder
    QGridLayout *aLayout = new QGridLayout();

    QPushButton *scanning = new QPushButton("Scan UID");
    QPushButton *addThisUID = new QPushButton("Add to Valid User");
    QPushButton *clearThisUID = new QPushButton("Clear the edit space");

    connect(scanning,SIGNAL(clicked(bool)),this,SLOT(scanTheUID()));
    connect(addThisUID,SIGNAL(clicked(bool)),this,SLOT(addCurrentUID()));
    connect(clearThisUID,SIGNAL(clicked(bool)),this,SLOT(clearCurrentUID()));

    UID_Displayer = new QTextBrowser();

    aLayout->addWidget(scanning,0,0,2,1);
    aLayout->addWidget(UID_Displayer,0,1,1,2);
    aLayout->addWidget(addThisUID,1,1,1,1);
    aLayout->addWidget(clearThisUID,1,2,1,1);

    scanPender = new QTimer();
    connect(scanPender,SIGNAL(timeout()),this,SLOT(pendingScan()));

    adder->setLayout(aLayout);
}

void MainWindow::setupScannerPart()
{
    // Setting Scanner
    QGridLayout *sLayout = new QGridLayout();

    QPushButton *turnOn = new QPushButton("keep Scanning");

    scannedUID = new QTextBrowser();
    compareResult = new QTextBrowser();

    sLayout->addWidget(turnOn,0,0,2,1);
    sLayout->addWidget(scannedUID,0,1,1,1);
    sLayout->addWidget(compareResult,1,1,1,1);

    scanPender_long = new QTimer();
    connect(turnOn,SIGNAL(clicked(bool)),this,SLOT(openScanMode()));
    connect(scanPender_long,SIGNAL(timeout()),this,SLOT(pendingScan_long()));

    scanner->setLayout(sLayout);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::scanTheUID()
{
    // Enable the timer
    scanPender->start(100);
    scanPender->setInterval(100);
    // And Disable scanner
    scanner->setEnabled(false);
}

void MainWindow::addCurrentUID()
{
    if(UID_Displayer->toPlainText().length() == 17){
        // It's a valid Card UID to enroll
        UID_Displayer->setText("The User Card UID : "+UID_Displayer->toPlainText() + " , is going to store into database , please waiting...");
        // Going to database , to chech whether this UID can enroll or not

    }
    else{
        // It's invalid Card UID , clear it
        UID_Displayer->setText("It's error ! Please check your device or card condition!");
    }
}

void MainWindow::clearCurrentUID()
{
    UID_Displayer->setText("");
}

void MainWindow::pendingScan()
{
    // Dealing with the scanner
    QFile createFile("output.txt");
    createFile.open(QIODevice::ReadWrite);
    QProcess::execute("./readCardID");
    // Get the content in output.txt
    QString rawData = QString(createFile.readAll());
    QString UID = rawData.mid(38,17);
    createFile.close();

    if(UID.length() == 17){
        // Display UID
        UID_Displayer->setText(UID);
        scanPender->stop();
        scanner->setEnabled(true);
    }
    else{
        // Show error
        UID_Displayer->setText("Sleeping ...");
    }
}

void MainWindow::openScanMode()
{
    scanPender_long->start(100);
    scanPender_long->setInterval(1000);
    adder->setEnabled(false);
}

void MainWindow::pendingScan_long()
{
    // Dealing with the scanner
    QFile createFile("output.txt");
    createFile.open(QIODevice::ReadWrite);
    QProcess::execute("./readCardID");
    // Get the content in output.txt
    QString rawData = QString(createFile.readAll());
    QString UID = rawData.mid(38,17);
    createFile.close();

    if(UID.length() == 17){
        // Display UID
        scannedUID->setText(UID);

        // Need to check the database
        compareResult->setText("...");
    }
    else{
        // Show error
        scannedUID->setText("wait for scanning ...");
    }
}

void MainWindow::showInfo()
{
    QMessageBox msgBox;
    msgBox.setWindowTitle(tr("Access Control System - version %1").arg(VERSION));
    msgBox.setText("Base on original pc/sc tools to build this program\n"
                   "Fit with the card no:\"3B 8F 80 01 80 4F 0C A0 00 00 03 06 03 00 01 00 00 00 00 6A\"\n"
                "GUI Author : Kevin Chiu , https://github.com/kevinbird61\n");
    msgBox.exec();
}
