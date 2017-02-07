#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QFileDialog>

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

    /* Disable the load button as it's not yet implemented
    ui->loadButton->setEnabled(false); */
    // Load Button
    connect(ui->loadButton, &QPushButton::clicked, [this](){
        qDebug() << "Loading a file...";

        QString filename = QFileDialog::getOpenFileName();

        QFile file(filename);
         if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
             return;

        ui->plainTextEdit->appendPlainText(file.readAll());

        file.close();
        //setToolTip(tr("Load contacts from a file"));
    });

    // pointless append button :)
    connect(ui->appendButton, &QPushButton::clicked, [this](){
        ui->htmlBrowserPane->append("<h4>Heading</h4><p>Html Paragraph</p>");
        ui->plainTextEdit->appendPlainText(QString("Clicked!"));
        ui->lcdNumber->display(++counter);
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
