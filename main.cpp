#include "mainwindow.h"
#include <iostream>
#include <iomanip>
#include <ctime>

#include <QApplication>
#include <QDebug>

class Class {
    int value;
public:
    Class();
};


int main(int argc, char *argv[])
{
    /* PUT Time - TODO - works but not with qDebug() */
    auto t = std::time(nullptr);
    auto tm = *std::localtime(&t);
    std::cout << std::put_time(&tm, "%d-%m-%Y %H-%M-%S") << std::endl;

QApplication a(argc, argv);
/*auto t = std::time(nullptr);
auto tm = *std::localtime(&t); */

time_t _tm =time(NULL );
struct tm * curtime = localtime ( &_tm );
qDebug() << "Application Started on" << asctime(curtime);

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
