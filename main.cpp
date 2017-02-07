#include "mainwindow.h"
#include <QApplication>
#include <QDebug>

int main(int argc, char *argv[])
{
QApplication a(argc, argv);
qDebug() << "Starting...";

//int window_width = QApplication::desktop()->width();
//int window_height = QApplication::desktop()->height();

MainWindow w;
w.setWindowTitle("Learn QT5 v0.0-1");
/*
QPushButton * quit_btn = new QPushButton;
quit_btn->setParent(w.centralWidget());
quit_btn->setGeometry(window_width-50,12,32,32);

QObject::connect(quit_btn,SIGNAL(clicked()),qApp,SLOT(quit()));
*/

//w.resize(window_width,window_height);
w.show();

return a.exec();
}
