#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // slider and progress bar
    connect(ui->horizontalSlider,
                SIGNAL(valueChanged(int)),
                ui->progressBar,
                SLOT(setValue(int)));

    // Disable the load button as it's not yet implemented
    ui->loadButton->setEnabled(false);

    // pointless button
    connect(ui->appendButton, &QPushButton::clicked, [this](){
        ui->plainTextEdit->appendPlainText(QString("Clicked!"));
    });

    // Quit button
    connect(ui->quitButton, &QPushButton::clicked, [this](){
        qDebug() << "Quitting Application...";
        exit(0);
        //SLOT(quit());
    });

    /*connect(ui->quitButton,
            SIGNAL(clicked()),

            SLOT(quit())); */
}

MainWindow::~MainWindow()
{
    delete ui;
}
