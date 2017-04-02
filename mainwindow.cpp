#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QFileDialog>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->counter=0;

    // slider and progress bar
    connect(ui->horizontalSlider,
                SIGNAL(valueChanged(int)),
                ui->progressBar,
                SLOT(setValue(int)));

    // ListView
    // Create model
    model = new QStringListModel(this);

    // Make data
    QStringList List;
    List << "Clair de Lune" << "Reverie" << "Prelude";

    // Populate our model
    model->setStringList(List);

    // Glue model and view together
    ui->listView->setModel(model);

    // Load Button
    connect(ui->loadButton, &QPushButton::clicked, [this](){
        // Done in the UI setToolTip(tr("Load contacts from a file"));
        qDebug() << "Loading contents of file " << QFileDialog::getOpenFileName();

        // Or you can generate a QString first
        QString filename = QFileDialog::getOpenFileName();
        QFile file(filename);
         if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
             return;

        ui->plainTextEdit->appendPlainText(file.readAll());

        file.close();
    });

    // pointless append button :)
    connect(ui->appendButton, &QPushButton::clicked, [this](){
        ui->htmlBrowserPane->append("<h4>Heading</h4><p>Html Paragraph</p>");
        ui->plainTextEdit->appendPlainText(QString("Clicked!"));
        ui->lcdNumber->display(++counter);
    });

    // Quit button
    connect(ui->quitButton, &QPushButton::clicked, [this](){
        // Show dialogue box before quitting
        QMessageBox msgBox;
        msgBox.setWindowTitle("Quit Application");
        msgBox.setText("Are you sure you want to quit the application?");
        msgBox.setStandardButtons(QMessageBox::Yes);
        msgBox.addButton(QMessageBox::No);
        msgBox.setDefaultButton(QMessageBox::No);
        if(msgBox.exec() == QMessageBox::Yes) {
            time_t _tm =time(NULL );
            struct tm * curtime = localtime ( &_tm );
            qDebug() << "Quitting Application on" << asctime(curtime);
            exit(0);
        }
    });
}

MainWindow::~MainWindow()
{
    delete ui;
}
