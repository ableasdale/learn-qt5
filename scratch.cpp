/*
 * #include "mainwindow.h"
#include <QApplication>
#include <QPushButton>

class MyButton : public QWidget {

 public:
     MyButton(QWidget *parent = 0);
};

MyButton::MyButton(QWidget *parent)
    : QWidget(parent) {

  QPushButton *quitBtn = new QPushButton("Quit", this);
  quitBtn->setGeometry(50, 40, 75, 30);

  connect(quitBtn, &QPushButton::clicked, qApp, &QApplication::quit);
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    MainWindow w;



    // Not sure if you can even see these on OS X...
    w.setWindowIcon(QIcon("web.png"));
    w.setToolTip("This is my pointless tooltip");
    w.show();

    return a.exec();
} */
